// Copyright (c) 2016 GitHub, Inc.
// Use of this source code is governed by the MIT license that can be
// found in the LICENSE file.

#include "atom/browser/web_contents_permission_helper.h"

#include <string>

#include "brave/browser/brave_permission_manager.h"
#include "brightray/browser/media/media_stream_devices_controller.h"
#include "content/public/browser/browser_context.h"
#include "content/public/browser/render_frame_host.h"
#include "content/public/browser/render_process_host.h"

DEFINE_WEB_CONTENTS_USER_DATA_KEY(atom::WebContentsPermissionHelper);

namespace atom {

namespace {

void MediaAccessAllowed(
    const content::MediaStreamRequest& request,
    content::MediaResponseCallback callback,
    bool allowed) {
  // TODO(bridiver) - IOThread >>
  brightray::MediaStreamDevicesController controller(request,
                                                     std::move(callback));
  if (allowed)
    controller.TakeAction();
  else
    controller.Deny(content::MEDIA_DEVICE_PERMISSION_DENIED);
}

void OnPointerLockResponse(content::WebContents* web_contents, bool allowed) {
  if (web_contents)
    web_contents->GotResponseToLockMouseRequest(allowed);
}

void OnPermissionResponse(const base::OnceCallback<void(bool)>& callback,
                          blink::mojom::PermissionStatus status) {
  // TODO(hferreiro)
  // if (status == blink::mojom::PermissionStatus::GRANTED)
  //   std::move(callback).Run(true);
  // else
  //   std::move(callback).Run(false);
}

}  // namespace

WebContentsPermissionHelper::WebContentsPermissionHelper(
    content::WebContents* web_contents)
    : web_contents_(web_contents) {
}

WebContentsPermissionHelper::~WebContentsPermissionHelper() {
}

void WebContentsPermissionHelper::RequestPermission(
    content::PermissionType permission,
    const base::OnceCallback<void(bool)>& callback,
    content::RenderFrameHost* rfh,
    const GURL& frame_url, bool user_gesture) {
  GURL url;
  auto permission_manager = static_cast<brave::BravePermissionManager*>(
      web_contents_->GetBrowserContext()->GetPermissionManager());

  if (frame_url.is_empty()) {
    url = web_contents_->GetLastCommittedURL();
  } else {
    url = frame_url;
  }

  // TODO(hferreiro)
  // permission_manager->RequestPermission(
  //     permission, rfh, url, user_gesture,
  //     base::BindOnce(&OnPermissionResponse, std::move(callback)));
}

void WebContentsPermissionHelper::RequestFullscreenPermission(
    const base::OnceCallback<void(bool)>& callback) {
  RequestPermission((content::PermissionType)(PermissionType::FULLSCREEN),
                    std::move(callback), web_contents_->GetMainFrame());
}

void WebContentsPermissionHelper::RequestMediaAccessPermission(
    const content::MediaStreamRequest& request,
    content::MediaResponseCallback response_callback) {
  auto callback = base::BindOnce(&MediaAccessAllowed, request,
                                 std::move(response_callback));
  // The permission type doesn't matter here, AUDIO_CAPTURE/VIDEO_CAPTURE
  // are presented as same type in content_converter.h.
  auto rfh = content::RenderFrameHost::FromID(request.render_process_id,
      request.render_frame_id);
  if (!rfh)
    std::move(callback).Run(false);

  // TODO(hferreiro)
  // RequestPermission(content::PermissionType::AUDIO_CAPTURE, std::move(callback),
  //                   rfh, request.security_origin);
}

void WebContentsPermissionHelper::RequestWebNotificationPermission(
    const base::OnceCallback<void(bool)>& callback) {
  RequestPermission(content::PermissionType::NOTIFICATIONS, std::move(callback),
                    web_contents_->GetMainFrame());
}

void WebContentsPermissionHelper::RequestPointerLockPermission(
    bool user_gesture) {
  RequestPermission((content::PermissionType)(PermissionType::POINTER_LOCK),
                    base::BindOnce(&OnPointerLockResponse, web_contents_),
                    web_contents_->GetMainFrame(),
                    GURL(),
                    user_gesture);
}

void WebContentsPermissionHelper::RequestOpenExternalPermission(
    const base::OnceCallback<void(bool)>& callback,
    content::RenderFrameHost* rfh,
    const GURL& frame_url,
    bool user_gesture) {
  RequestPermission((content::PermissionType)(PermissionType::OPEN_EXTERNAL),
                    std::move(callback),
                    rfh,
                    frame_url,
                    user_gesture);
}

void WebContentsPermissionHelper::RequestProtocolRegistrationPermission(
    const base::OnceCallback<void(bool)>& callback,
    bool user_gesture) {
  RequestPermission((content::PermissionType)
      (PermissionType::PROTOCOL_REGISTRATION),
                    std::move(callback),
                    web_contents_->GetMainFrame(),
                    GURL(),
                    user_gesture);
}

}  // namespace atom
