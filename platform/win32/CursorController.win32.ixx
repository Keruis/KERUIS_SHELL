module;

#include <array>
#include <windows.h>
#include <dinput.h>

export module ks.platform.win32.CursorController;

import ks.platform.common.ICursorController;
import ks.core.render.mouse_types;

export namespace ks::platform::win32 {

class CursorControllerWin32 final : public ICursorController {
public:
    bool Init(void* windowHandle) override {
        hwnd = static_cast<HWND>(windowHandle);

        HRESULT result = DirectInput8Create(GetModuleHandle(nullptr), DIRECTINPUT_VERSION, IID_IDirectInput8,
                                            reinterpret_cast<void**>(&directInput), nullptr);
        if (FAILED(result)) return false;

        result = directInput->CreateDevice(GUID_SysMouse, &mouse, nullptr);
        if (FAILED(result)) return false;

        result = mouse->SetDataFormat(&c_dfDIMouse);
        if (FAILED(result)) return false;

        result = mouse->SetCooperativeLevel(hwnd, DISCL_FOREGROUND | DISCL_NONEXCLUSIVE);
        if (FAILED(result)) return false;

        result = mouse->Acquire();
        if (FAILED(result)) return false;

        return true;
    }

    void SetCursorMode(core::render::input::CursorMode mode) override {
        cursorMode = mode;
        switch (mode) {
        case core::render::input::CursorMode::Normal:
            ShowCursor(true);
            break;
        case core::render::input::CursorMode::Hidden:
            ShowCursor(false);
            break;
        case core::render::input::CursorMode::Locked:

            break;
        }
    }

    core::render::input::CursorMode GetCursorMode() const override {
        return cursorMode;
    }

    void SetPosition(core::render::input::MousePosition position) override {
        POINT point{(position.x), (position.y)};
        ::SetCursorPos(point.x, point.y);
    }

    core::render::input::MousePosition GetPosition() const override {
        POINT point;
        ::GetCursorPos(&point);
        return core::render::input::MousePosition(point.x, point.y);
    }

    bool ReadMouseState() override {
        if (const HRESULT result = mouse->GetDeviceState(sizeof(DIMOUSESTATE), &mouseState); FAILED(result)) {
            if (result == DIERR_INPUTLOST || result == DIERR_NOTACQUIRED) {
                mouse->Acquire();
            } else {
                return false;
            }
        }
        return true;
    }

    core::render::input::MousePosition GetMouseStatePosition() const override {
        return { static_cast<int>(mouseState.lX), static_cast<int>(mouseState.lY) };
    }

    std::array<bool, 3> GetMouseStateButton() const override {
        return {(mouseState.rgbButtons[0] & 0x80) != 0,
                   (mouseState.rgbButtons[1] & 0x80) != 0,
                   (mouseState.rgbButtons[2] & 0x80) != 0
        };
    }

    float GetMouseStateScrollDelta() const override {
        return mouseState.lZ;
    }

    core::render::input::MousePosition GetPositionInClient() const override {
        POINT point;
        GetCursorPos(&point);
        ScreenToClient(hwnd, &point);
        return { static_cast<int>(point.x), static_cast<int>(point.y) };
    }

private:
    HWND hwnd = nullptr;
    LPDIRECTINPUTDEVICE8 mouse = nullptr;
    DIMOUSESTATE mouseState{};
    LPDIRECTINPUT8 directInput = nullptr;

    core::render::input::CursorMode cursorMode = core::render::input::CursorMode::Normal;
};

}
