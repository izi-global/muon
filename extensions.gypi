{
  'variables': {
    'enable_extensions%': 1,
    'grit_out_dir%': '<(SHARED_INTERMEDIATE_DIR)/atom',
    'grit_defines': [],
    'extension_js_sources': [
      'lib/browser/api/extensions.js',
    ],
    'extension_sources': [
      'atom/browser/api/atom_api_extension.cc',
      'atom/browser/api/atom_api_extension.h',
      'atom/browser/extensions/api/messaging/extension_message_port.cc',
      'atom/browser/extensions/api/messaging/extension_message_port.h',
      'atom/browser/extensions/api/messaging/message_property_provider.cc',
      'atom/browser/extensions/api/messaging/message_property_provider.h',
      'atom/browser/extensions/api/messaging/message_service.cc',
      'atom/browser/extensions/api/messaging/message_service.h',
      'atom/browser/extensions/api/atom_extensions_api_client.cc',
      'atom/browser/extensions/api/atom_extensions_api_client.h',
      'atom/browser/extensions/atom_browser_client_extensions_part.cc',
      'atom/browser/extensions/atom_browser_client_extensions_part.h',
      'atom/browser/extensions/atom_extension_api_frame_id_map_helper.cc',
      'atom/browser/extensions/atom_extension_api_frame_id_map_helper.h',
      'atom/browser/extensions/atom_extension_host_delegate.cc',
      'atom/browser/extensions/atom_extension_host_delegate.h',
      'atom/browser/extensions/atom_extension_system.cc',
      'atom/browser/extensions/atom_extension_system.h',
      'atom/browser/extensions/atom_extension_system_factory.cc',
      'atom/browser/extensions/atom_extension_system_factory.h',
      'atom/browser/extensions/atom_extension_web_contents_observer.cc',
      'atom/browser/extensions/atom_extension_web_contents_observer.h',
      'atom/browser/extensions/atom_extensions_browser_client.cc',
      'atom/browser/extensions/atom_extensions_browser_client.h',
      'atom/browser/extensions/atom_extensions_network_delegate.cc',
      'atom/browser/extensions/atom_extensions_network_delegate.h',
      'atom/browser/extensions/atom_notification_types.h',
      'atom/browser/extensions/atom_process_manager_delegate.cc',
      'atom/browser/extensions/atom_process_manager_delegate.h',
      'atom/browser/extensions/shared_user_script_master.cc',
      'atom/browser/extensions/shared_user_script_master.h',
      'atom/browser/extensions/tab_helper.cc',
      'atom/browser/extensions/tab_helper.h',
      'atom/common/extensions/permissions/chrome_api_permissions.cc',
      'atom/common/extensions/permissions/chrome_api_permissions.h',
      'atom/common/extensions/atom_extensions_client.cc',
      'atom/common/extensions/atom_extensions_client.h',
      'atom/common/javascript_bindings.cc',
      'atom/common/javascript_bindings.h',
      'atom/renderer/content_settings_client.cc',
      'atom/renderer/content_settings_client.h',
      'atom/renderer/content_settings_manager.cc',
      'atom/renderer/content_settings_manager.h',
      'atom/renderer/content_settings_observer.h',
      'atom/renderer/extensions/atom_extensions_dispatcher_delegate.cc',
      'atom/renderer/extensions/atom_extensions_dispatcher_delegate.h',
      'atom/renderer/extensions/atom_extensions_renderer_client.cc',
      'atom/renderer/extensions/atom_extensions_renderer_client.h',
      'chromium_src/chrome/browser/renderer_host/chrome_extension_message_filter.cc',
      'chromium_src/chrome/browser/renderer_host/chrome_extension_message_filter.h',
      'chromium_src/chrome/browser/ui/zoom/chrome_zoom_level_prefs.cc',
      'chromium_src/chrome/browser/ui/zoom/chrome_zoom_level_prefs.h',
      'chromium_src/chrome/common/cloud_devices_urls.cc',
      'chromium_src/chrome/common/cloud_devices_urls.h',
      'chromium_src/chrome/renderer/extensions/tabs_custom_bindings.cc',
      'chromium_src/chrome/renderer/extensions/tabs_custom_bindings.h',
      'chromium_src/components/sessions/core/session_id.h',
      'chromium_src/components/sessions/core/session_id.cc',
      'chromium_src/components/sessions/core/sessions_export.h',
      # brave
      'brave/browser/notifications/platform_notification_service_impl.h',
      'brave/browser/notifications/platform_notification_service_impl.cc',
      'brave/browser/brave_browser_context.h',
      'brave/browser/brave_browser_context.cc',
      'brave/browser/brave_content_browser_client.h',
      'brave/browser/brave_content_browser_client.cc',
      'brave/browser/brave_permission_manager.h',
      'brave/browser/brave_permission_manager.cc',
      'brave/renderer/brave_content_renderer_client.cc',
      'brave/renderer/brave_content_renderer_client.h',
    ],
  },
  'conditions': [
    ['OS=="mac" or OS=="linux"', {
      'variables': {
        'extension_libraries': [
          '<(libchromiumcontent_dir)/libapi_gen_util.a',
          '<(libchromiumcontent_dir)/libautofill_content_browser.a',
          '<(libchromiumcontent_dir)/libautofill_content_common.a',
          '<(libchromiumcontent_dir)/libautofill_content_mojo_bindings.a',
          '<(libchromiumcontent_dir)/libautofill_content_renderer.a',
          '<(libchromiumcontent_dir)/libautofill_core_browser.a',
          '<(libchromiumcontent_dir)/libautofill_core_common.a',
          '<(libchromiumcontent_dir)/libbrowsing_data.a',
          '<(libchromiumcontent_dir)/libchrome_api.a',
          '<(libchromiumcontent_dir)/libchrome_zlib.a',
          '<(libchromiumcontent_dir)/libcld2_static.a',
          '<(libchromiumcontent_dir)/libcontent_settings_core_common.a',
          '<(libchromiumcontent_dir)/libcrx_file.a',
          '<(libchromiumcontent_dir)/libdevice_usb.a',
          '<(libchromiumcontent_dir)/libextensions_api.a',
          '<(libchromiumcontent_dir)/libextensions_api_registration.a',
          '<(libchromiumcontent_dir)/libextensions_browser.a',
          '<(libchromiumcontent_dir)/libextensions_common.a',
          '<(libchromiumcontent_dir)/libextensions_common_constants.a',
          '<(libchromiumcontent_dir)/libextensions_renderer.a',
          '<(libchromiumcontent_dir)/libextensions_utility.a',
          '<(libchromiumcontent_dir)/libgoogle_apis.a',
          '<(libchromiumcontent_dir)/libguest_view_browser.a',
          '<(libchromiumcontent_dir)/libguest_view_common.a',
          '<(libchromiumcontent_dir)/libguest_view_renderer.a',
          '<(libchromiumcontent_dir)/libleveldatabase.a',
          '<(libchromiumcontent_dir)/libmojo_cpp_bindings.a',
          '<(libchromiumcontent_dir)/libmojo_cpp_system.a',
          '<(libchromiumcontent_dir)/libmojo_js_bindings.a',
          '<(libchromiumcontent_dir)/libpref_registry.a',
          '<(libchromiumcontent_dir)/libre2.a',
          '<(libchromiumcontent_dir)/libsnappy.a',
          '<(libchromiumcontent_dir)/libsyncable_prefs.a',
          '<(libchromiumcontent_dir)/libui_zoom.a',
          '<(libchromiumcontent_dir)/libvariations.a',
          '<(libchromiumcontent_dir)/libweb_cache_browser.a',
          '<(libchromiumcontent_dir)/libweb_cache_mojo_bindings.a',
          '<(libchromiumcontent_dir)/libweb_modal.a',
          '<(libchromiumcontent_dir)/libxml2.a',
          '<(libchromiumcontent_dir)/libzlib_x86_simd.a',
        ]
      }
    }],
    ['OS=="win"', {
      'variables': {
        'extension_libraries': [
          '<(libchromiumcontent_dir)/api_gen_util.lib',
          '<(libchromiumcontent_dir)/browsing_data.lib',
          '<(libchromiumcontent_dir)/chrome_api.lib',
          '<(libchromiumcontent_dir)/cld2_static.lib',
          '<(libchromiumcontent_dir)/content_settings_core_common.lib',
          '<(libchromiumcontent_dir)/crx_file.lib',
          '<(libchromiumcontent_dir)/device_usb.lib',
          '<(libchromiumcontent_dir)/extensions_api.lib',
          '<(libchromiumcontent_dir)/extensions_api_registration.lib',
          '<(libchromiumcontent_dir)/extensions_browser.lib',
          '<(libchromiumcontent_dir)/extensions_common.lib',
          '<(libchromiumcontent_dir)/extensions_common_constants.lib',
          '<(libchromiumcontent_dir)/extensions_renderer.lib',
          '<(libchromiumcontent_dir)/extensions_utility.lib',
          '<(libchromiumcontent_dir)/guest_view_browser.lib',
          '<(libchromiumcontent_dir)/guest_view_common.lib',
          '<(libchromiumcontent_dir)/guest_view_renderer.lib',
          '<(libchromiumcontent_dir)/leveldatabase.lib',
          '<(libchromiumcontent_dir)/mojo_cpp_bindings.lib',
          '<(libchromiumcontent_dir)/mojo_cpp_system.lib',
          '<(libchromiumcontent_dir)/mojo_js_bindings.lib',
          '<(libchromiumcontent_dir)/pref_registry.lib',
          '<(libchromiumcontent_dir)/re2.lib',
          '<(libchromiumcontent_dir)/snappy.lib',
          '<(libchromiumcontent_dir)/syncable_prefs.lib',
          '<(libchromiumcontent_dir)/ui_zoom.lib',
          '<(libchromiumcontent_dir)/variations.lib',
          '<(libchromiumcontent_dir)/web_cache_browser.lib',
          '<(libchromiumcontent_dir)/web_cache_mojo_bindings.lib',
          '<(libchromiumcontent_dir)/web_modal.lib',
          '<(libchromiumcontent_dir)/libxml2.lib',
          '<(libchromiumcontent_dir)/zlib_x86_simd.lib',
        ],
      },
    }],
  ],
  'target_defaults': {
    'defines': [
      'GOOGLE_PROTOBUF_NO_RTTI'
    ],
    'conditions': [
      ['enable_extensions==1', {
        'defines': [
          'ENABLE_EXTENSIONS=1',
        ],
      }],
    ],
  },
}
