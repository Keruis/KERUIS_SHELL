module;

#include <array>

export module ks.platform.common.ICursorController;

import ks.core.render.mouse_types;

export namespace ks::platform {

class ICursorController {
public:
    virtual bool Init(void* windowHandle) = 0;

    virtual ~ICursorController() = default;

    virtual void SetCursorMode(core::render::input::CursorMode mode) = 0;
    virtual core::render::input::CursorMode GetCursorMode() const = 0;

    virtual void SetPosition(core::render::input::MousePosition position) = 0;
    virtual core::render::input::MousePosition GetPosition() const;

    virtual bool ReadMouseState() = 0;
    virtual core::render::input::MousePosition GetMouseStatePosition() const = 0;
    virtual std::array<bool, 3> GetMouseStateButton() const = 0;
    virtual float GetMouseStateScrollDelta() const = 0;
    virtual core::render::input::MousePosition GetPositionInClient() const = 0;
};

}
