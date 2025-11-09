module;

#include <array>

export module ks.core.render.mouse_types;

export namespace ks::core::render::input {

using mouse_coord_t = int;
using mouse_scroll_t = float;

enum class MouseButton {
    Left,
    Right,
    Middle,
};

enum class CursorMode {
    Normal,
    Hidden,
    Locked
};

struct MousePosition {
    mouse_coord_t x = 0.f;
    mouse_coord_t y = 0.f;
};

struct MouseButtons {
    std::array<bool, 3> buttons;
};

}
