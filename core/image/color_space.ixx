module;

#include <cstdint>

export module ks.core.image.color_space;

export namespace ks::core::image {

enum color_model : uint8_t {
    rgb,
    rgba,
    hsv,
    hsva,
};

}