module;

#include "../../../utils/attributes.h"

export module ks.core.render.input:keyboard;

import ks.core.render.keyboard_types;

export namespace ks::core::render::input {

class Keyboard {
public:
    void update() KS_NOEXCEPT;

    bool isKeyDown(key_t key) KS_CONST KS_NOEXCEPT;
    bool isKeyPressed(key_t key) KS_CONST KS_NOEXCEPT;
    bool isKeyReleased(key_t key) KS_CONST KS_NOEXCEPT;

    void _onKeyDown(key_t key) KS_NOEXCEPT;
    void _onKeyUp(key_t key) KS_NOEXCEPT;

private:
    KeyboardState current{};
    KeyboardState previous{};
};

}