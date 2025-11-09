module;

#include <utility>
#include <windows.h>

export module ks.platform.win32.Window;

import ks.platform.common.IWindow;

export namespace ks::platform::win32 {

class WindowWin32 final : public IWindow {
public:
    bool Init(void* windowHandle) override {
        hwnd = static_cast<HWND>(windowHandle);
        return true;
    }

    WindowSize GetWindowSize() const override {
        RECT rc;
        if (GetClientRect(hwnd, &rc)) {
            int width  = rc.right - rc.left;
            int height = rc.bottom - rc.top;
            return {width, height};
        }
        return {0, 0};
    }

private:
    HWND hwnd = nullptr;
};

}
