module;

#include <cstdint>

export module ks.core.image.pixel_traits;

import ks.core.image.color_space;
import ks.core.image.color_channel;

export namespace ks::core::image {

template <color_model>
struct pixel_traits;

template <>
struct pixel_traits<rgb> {
    using value_t = uint8_t;
    static constexpr constants::color_channel color_channel_1 = constants::color_channel::R;
    static constexpr constants::color_channel color_channel_2 = constants::color_channel::G;
    static constexpr constants::color_channel color_channel_3 = constants::color_channel::B;

    static constexpr int CHANNELS = 3;

    static constexpr value_t MAX = 255;
    static constexpr value_t MIN = 0;

    static constexpr value_t DEFAULT_GRAY = 128;
};

template <>
struct pixel_traits<rgba> {
    using value_t = uint8_t;
    static constexpr constants::color_channel color_channel_1 = constants::color_channel::R;
    static constexpr constants::color_channel color_channel_2 = constants::color_channel::G;
    static constexpr constants::color_channel color_channel_3 = constants::color_channel::B;
    static constexpr constants::color_channel color_channel_4 = constants::color_channel::A;

    static constexpr int CHANNELS = 4;

    static constexpr value_t MAX = 255;
    static constexpr value_t MIN = 0;

    static constexpr value_t DEFAULT_GRAY = 128;
};

template <>
struct pixel_traits<hsv> {
    using value_t = float;
    static constexpr constants::color_channel color_channel_1 = constants::color_channel::H;
    static constexpr constants::color_channel color_channel_2 = constants::color_channel::S;
    static constexpr constants::color_channel color_channel_3 = constants::color_channel::V;

    static constexpr int CHANNELS = 3;

    static constexpr value_t MAX = 1.f;
    static constexpr value_t MIN = 0.f;

    static constexpr value_t DEFAULT_GRAY = 0.5f;
};

template <>
struct pixel_traits<hsva> {
    using value_t = float;
    static constexpr constants::color_channel color_channel_1 = constants::color_channel::H;
    static constexpr constants::color_channel color_channel_2 = constants::color_channel::S;
    static constexpr constants::color_channel color_channel_3 = constants::color_channel::V;
    static constexpr constants::color_channel color_channel_4 = constants::color_channel::A;

    static constexpr int CHANNELS = 4;

    static constexpr value_t MAX = 1.f;
    static constexpr value_t MIN = 0.f;

    static constexpr value_t DEFAULT_GRAY = 0.5f;
};

}
