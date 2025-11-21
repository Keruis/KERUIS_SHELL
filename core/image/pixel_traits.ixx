module;

#include <cstdint>

export module ks.core.image.pixel_traits;

import ks.core.image.color_space;

export namespace ks::core::image {

template <typename C_>
struct pixel_traits;

template <>
struct pixel_traits<rgb_t> {
    using value_t = uint8_t;

    static constexpr int CHANNELS = 4;

    static constexpr value_t MAX = 255;
    static constexpr value_t MIN = 0;

    static constexpr value_t DEFAULT_GRAY = 128;
};

template <>
struct pixel_traits<hsv_t> {
    using value_t = float;

    static constexpr int CHANNELS = 4;

    static constexpr value_t MAX = 1.f;
    static constexpr value_t MIN = 0.f;

    static constexpr value_t DEFAULT_GRAY = 0.5f;
};

}
