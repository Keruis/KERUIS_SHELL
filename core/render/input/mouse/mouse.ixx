module;

#include "../../../utils/attributes.h"

export module ks.core.render.input:mouse;

import ks.platform.common.ICursorController;
import ks.platform.common.IWindow;
import ks.core.render.mouse_types;

export namespace ks::core::render::input {

class Mouse {
public:
    Mouse(int screenWidth_, int screenHeight_);

    void BindWindow(platform::IWindow* window_);
    void BindCursorController(platform::ICursorController* cursorController);

    bool frame() KS_NOEXCEPT;
    void update() KS_NOEXCEPT;

    bool isButtonDown(MouseButton button) KS_CONST KS_NOEXCEPT;
    bool isButtonPressed(MouseButton button) KS_CONST KS_NOEXCEPT;
    bool isButtonReleased(MouseButton button) KS_CONST KS_NOEXCEPT;

    MousePosition getPosition() KS_CONST KS_NOEXCEPT;
    MousePosition getDelta() KS_CONST KS_NOEXCEPT;
    mouse_scroll_t getScrollDelta() KS_CONST KS_NOEXCEPT;

    void setCursorMode(CursorMode mode) KS_NOEXCEPT;
    CursorMode getCursorMode() KS_CONST KS_NOEXCEPT;

    void _onButtonDown(MouseButton button) KS_NOEXCEPT;
    void _onButtonUp(MouseButton button) KS_NOEXCEPT;
    void _onMove(mouse_coord_t x, mouse_coord_t y) KS_NOEXCEPT;
    void _onScroll(mouse_scroll_t delta) KS_NOEXCEPT;

private:
    bool readMouse() KS_CONST KS_NOEXCEPT;

    int screenWidth = 0;
    int screenHeight = 0;

    MouseButtons current{};
    MouseButtons previous{};

    MousePosition position;
    MousePosition last_position;
    mouse_scroll_t scroll_delta = 0;

    CursorMode cursor_mode = CursorMode::Normal;

    platform::IWindow* window = nullptr;
    platform::ICursorController* cursor_controller = nullptr;
};

}