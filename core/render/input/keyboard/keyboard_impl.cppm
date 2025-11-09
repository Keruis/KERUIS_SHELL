module;

#include "../../../utils/attributes.h"

module ks.core.render.input:keyboard_impl;

import :keyboard;

namespace ks::core::render::input {

void Keyboard::update() KS_NOEXCEPT {
    previous = current;
}

bool Keyboard::isKeyDown(key_t key) KS_CONST KS_NOEXCEPT {
    return current.keys[key];
}

bool Keyboard::isKeyPressed(key_t key) KS_CONST KS_NOEXCEPT {
    return current.keys[key] && !previous.keys[key];
}

bool Keyboard::isKeyReleased(key_t key) KS_CONST KS_NOEXCEPT {
    return !current.keys[key] && previous.keys[key];
}

void Keyboard::_onKeyDown(key_t key) KS_NOEXCEPT {
    current.keys[key] = true;
}

void Keyboard::_onKeyUp(key_t key) KS_NOEXCEPT {
    current.keys[key] = false;
}


}