module;

#include <cstdint>
#include <cstddef>

export module ks.core.image.color_space;

export namespace ks::core::image {

enum color_model : uint8_t {
    rgb,
    rgba,
    hsv,
    hsva,
    hsl,
    hsla
};

template <color_model color_model>
constexpr std::size_t get_color_space_size() {
    switch (color_model) {
        case rgb:
        case hsv:
        case hsl:
        return 3;
        case rgba:
        case hsva:
        case hsla:
        return 4;
    }
    return std::size_t{};
}
}
