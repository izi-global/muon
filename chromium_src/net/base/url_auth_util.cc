// Copyright 2013 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#include <iostream>
#include <string>

#include "base/strings/string_piece.h"
#include "net/base/url_auth_util.h"
#include "url/third_party/mozilla/url_parse.h"
#include "url/url_canon_ip.h"

namespace net {

// Copypasta of ParseHostAndPort that extracts the username and
// password instead of rejecting them.
bool ParseAuthHostAndPort(base::StringPiece input,
                          std::string* up_host_ret,
                          int* port) {
  if (input.empty())
    return false;

  url::Component auth_component(0, input.size());
  url::Component username_component;
  url::Component password_component;
  url::Component hostname_component;
  url::Component port_component;

  url::ParseAuthority(input.data(), auth_component, &username_component,
                      &password_component, &hostname_component,
                      &port_component);

  if (!hostname_component.is_nonempty())
    return false;  // Failed parsing.

  int parsed_port_number = -1;
  if (port_component.is_nonempty()) {
    parsed_port_number = url::ParsePort(input.data(), port_component);

    // If parsing failed, port_number will be either PORT_INVALID or
    // PORT_UNSPECIFIED, both of which are negative.
    if (parsed_port_number < 0)
      return false;  // Failed parsing the port number.
  }

  if (port_component.len == 0)
    return false;  // Reject inputs like "foo:"

  unsigned char tmp_ipv6_addr[16];

  // If the hostname starts with a bracket, it is either an IPv6 literal or
  // invalid. If it is an IPv6 literal then strip the brackets.
  if (hostname_component.len > 0 && input[hostname_component.begin] == '[') {
    if (input[hostname_component.end() - 1] == ']' &&
        url::IPv6AddressToNumber(input.data(), hostname_component,
                                 tmp_ipv6_addr)) {
      // Strip the brackets.
      hostname_component.begin++;
      hostname_component.len -= 2;
    } else {
      return false;
    }
  }

  // Reassemble user:pass@host as up_host.
  std::string up_host;
  if (username_component.is_valid() || password_component.is_valid()) {
    if (username_component.is_valid()) {
      std::string username(input.data() + username_component.begin,
                           username_component.len);
      up_host += username;
    }
    if (password_component.is_valid()) {
      std::string password(input.data() + password_component.begin,
                           password_component.len);
      up_host += ":";
      up_host += password;
    }
    up_host += "@";
  }
  std::string hostname(input.data() + hostname_component.begin,
                       hostname_component.len);
  up_host += hostname;

  // Pass results back to caller.
  *up_host_ret = up_host;
  *port = parsed_port_number;

  return true;  // Success.
}

}
