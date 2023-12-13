export module platform;

import types;
import task;
export namespace bd {

enum class window_mode : uint8 { wm_windowed, wm_fullscreen, wm_borderless };

enum class back_buffer_count : uint8 { bbc_double_buffer, bbc_triple_buffer };

struct rect_desc {
    int32 left;
    int32 top;
    int32 right;
    int32 bottom;
};

struct window_handle {};

struct window_desc {

    // WindowHandle handle;
    // RectDesc windowedRect;
    // RectDesc fullscreenRect;
    // RectDesc clientRect;
    // uint32_t windowsFlags;
    // bool fullScreen;
    // bool cursorCaptured;
    // bool iconified;
    // bool maximized;
    // bool minimized;
    // bool hide;
    // bool noresizeFrame;
    // bool borderlessWindow;
    // bool overrideDefaultPosition;
    // bool centered;
    // bool forceLowDPI;

    // int32 mWindowMode;

    // int32 pCurRes[MAX_MONITOR_COUNT];
    // int32 pLastRes[MAX_MONITOR_COUNT];

    // int32 mWndX;
    // int32 mWndY;
    // int32 mWndW;
    // int32 mWndH;

    // bool mCursorHidden;
    // int32 mCursorInsideWindow;
    // bool mCursorClipped;
    // bool mMinimizeRequested;
};

// https://github.com/glfw/glfw/issues/1755

struct resoluion {
    uint32 width;
    uint32 height;
};

struct monitor_desc {
    //     RectDesc monitorRect;
    //     RectDesc workRect;
    //     unsigned int dpi[2];
    //     unsigned int physicalSize[2];
    //     // This size matches the static size of DISPLAY_DEVICE.DeviceName
    // #if defined(_WINDOWS) || defined(XBOX)
    //     WCHAR adapterName[32];
    //     WCHAR displayName[32];
    //     WCHAR publicAdapterName[128];
    //     WCHAR publicDisplayName[128];
    // #elif defined(__APPLE__)
    // #if defined(TARGET_IOS)
    // #else
    //     CGDirectDisplayID displayID;
    //     char publicAdapterName[64];
    //     char publicDisplayName[64];
    // #endif
    // #elif defined(__linux__) && !defined(__ANDROID__)
    //     Screen *screen;
    //     char adapterName[32];
    //     char displayName[32];
    //     char publicAdapterName[64];
    //     char publicDisplayName[64];
    // #else
    //     char adapterName[32];
    //     char displayName[32];
    //     char publicAdapterName[64];
    //     char publicDisplayName[64];
    // #endif
    //     // stb_ds array of Resolutions
    //     Resolution *resolutions;
    //     Resolution defaultResolution;
    //     bool modesPruned;
    //     bool modeChanged;
};

// unicode support
void open_window(const char *app_name, const window_desc &desc);

void close_window(const window_desc &desc);
void set_window_rect(const window_desc &desc, const rect_desc *rect);
void set_window_size(const window_desc &desc, unsigned width, unsigned height);
void toggleBorderless(const window_desc &desc, unsigned width, unsigned height);
void toggleFullscreen(const window_desc &desc);
void show_window(const window_desc &desc);
void hide_window(const window_desc &desc);
void maximize_window(const window_desc &desc);
void minimize_window(const window_desc &desc);
void center_window(const window_desc &desc);
void capture_cursor(const window_desc &desc, bool enable);

// Mouse and cursor handling
void *create_cursor(const char *path);
void set_cursor(void *cursor);
void show_cursor(void);
void hide_cursor(void);
bool is_cursor_inside_tracking_area(void);
void set_mouse_position_relative(const window_desc &desc, int32 x, int32 y);
void set_mouse_position_absolute(int32 x, int32 y);

void getRecommendedResolution(rect_desc *rect);
// Sets video mode for specified display
void setResolution(const monitor_desc &monitor, const resoluion &res);

monitor_desc *get_monitor(uint32 index);
uint32 get_monitor_count(void);
// pArray pointer to array with at least 2 elements(x,y)
void getDpiScale(float32 array[2]);

bool getResolutionSupport(const monitor_desc &monitor, const resoluion &res);

bd::uint32 max_thread_count = bd::thread::hardware_concurrency();

} // namespace bd

// #pragma once

// #include <GLFW/glfw3.h>

// import log
// #include "framework/utils/types/types.h"

// namespace ante {

// struct ante_window {
//     GLFWwindow *m_window;
// };

// struct window_desc {
//     const char *name;
//     u32 width;
//     u32 height;
//     bool b_vsync;
// };

// bool create_window(window_desc *desc, ante_window *window);

// void destroy_window(ante_window *window);

// bool window_pool_events(ante_window *window);

// //#ifdef _WIN32
// //HWND get_hwnd_window(ante_window window) { return glfwGetWin32Window(window.m_window); }
// //#endif // WIN32

// //enum class input_mode { mouse_keyboard, controller };
// //
// //bool add_device(input_mode mode);
// //
// //bool get_key();
// //bool get_key_down();
// //};

// } // namespace ante
