module;

#include <array>
#include <cstdint>

export module ks.core.render.keyboard_types;

export namespace ks::core::render::input {

using key_t = uint8_t;

struct KeyboardState {
    std::array<bool, 256> keys;
};

}