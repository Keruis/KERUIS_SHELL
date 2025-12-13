module;

#include <cstdint>
#include <limits>
#include <cmath>

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

    static constexpr value_t c_MAX[CHANNELS] = {255, 255, 255};
    static constexpr value_t c_MIN[CHANNELS] = {0, 0, 0};

    static constexpr value_t DEFAULT_GRAY = 128;

    template <std::size_t CHANNEL, bool IsMAX>
    static constexpr value_t range() {
        static_assert(1 <= CHANNEL && CHANNEL <= CHANNELS);
        if constexpr (IsMAX) {
            return c_MAX[CHANNEL - 1];
        } else {
            return c_MIN[CHANNEL - 1];
        }
    }

    template <std::size_t CHANNEL>
    static constexpr value_t normalize(uint32_t x) {
        return static_cast<value_t>(
            (x / static_cast<float>(std::numeric_limits<uint32_t>::max())) * range<CHANNEL, true>()
        );
    }

    template <std::size_t CHANNEL>
    static constexpr value_t lerp(value_t a, value_t b, float t) {
        return a + (b - a) * t;
    }

    template <std::size_t CHANNEL>
    static constexpr value_t clamp(value_t v) {
        return v < range<CHANNEL, false>() ? range<CHANNEL, false>() : v > range<CHANNEL, true>() ? range<CHANNEL, true>() : v;
    }
};

template <>
struct pixel_traits<rgba> {
    using value_t = uint8_t;
    static constexpr constants::color_channel color_channel_1 = constants::color_channel::R;
    static constexpr constants::color_channel color_channel_2 = constants::color_channel::G;
    static constexpr constants::color_channel color_channel_3 = constants::color_channel::B;
    static constexpr constants::color_channel color_channel_4 = constants::color_channel::A;

    static constexpr int CHANNELS = 4;

    static constexpr value_t c_MAX[CHANNELS] = {255, 255, 255, 255};
    static constexpr value_t c_MIN[CHANNELS] = {0, 0, 0, 0};

    static constexpr value_t DEFAULT_GRAY = 128;

    template <std::size_t CHANNEL, bool IsMAX>
    static constexpr value_t range() {
        static_assert(1 <= CHANNEL && CHANNEL <= CHANNELS);
        if constexpr (IsMAX) {
            return c_MAX[CHANNEL - 1];
        } else {
            return c_MIN[CHANNEL - 1];
        }
    }

    template <std::size_t CHANNEL>
    static constexpr value_t normalize(uint32_t x) {
        return static_cast<value_t>(
            (x / static_cast<float>(std::numeric_limits<uint32_t>::max())) * range<CHANNEL, true>()
        );
    }

    template <std::size_t CHANNEL>
    static constexpr value_t lerp(value_t a, value_t b, float t) {
        return a + (b - a) * t;
    }

    template <std::size_t CHANNEL>
    static constexpr value_t clamp(value_t v) {
        return v < range<CHANNEL, false>() ? range<CHANNEL, false>() : v > range<CHANNEL, true>() ? range<CHANNEL, true>() : v;
    }
};

template <>
struct pixel_traits<hsv> {
    using value_t = float;
    static constexpr constants::color_channel color_channel_1 = constants::color_channel::H;
    static constexpr constants::color_channel color_channel_2 = constants::color_channel::S;
    static constexpr constants::color_channel color_channel_3 = constants::color_channel::V;

    static constexpr int CHANNELS = 3;

    static constexpr value_t c_MAX[CHANNELS] = {1.f, 1.f, 1.f};
    static constexpr value_t c_MIN[CHANNELS] = {0.f, 0.f, 0.f};

    static constexpr value_t DEFAULT_GRAY = 0.5f;

    template <std::size_t CHANNEL, bool IsMAX>
    static constexpr value_t range() {
        static_assert(1 <= CHANNEL && CHANNEL <= CHANNELS);
        if constexpr (IsMAX) {
            return c_MAX[CHANNEL - 1];
        } else {
            return c_MIN[CHANNEL - 1];
        }
    }

    template <std::size_t CHANNEL>
    static constexpr value_t normalize(uint32_t x) {
        constexpr float inv = 1.0f / static_cast<float>(std::numeric_limits<uint32_t>::max());
        return x * inv * range<CHANNEL, true>();
    }

    template <std::size_t CHANNEL>
    static constexpr float lerp(float h1, float h2, float t) {
        if constexpr (CHANNEL == 1) {
            float d = std::fmod(h2 - h1 + 540.0f, 360.0f) - 180.0f;
            float h = h1 + d * t;
            return std::fmod(h + 360.0f, 360.0f);
        } else {
            return h1 + (h2 - h1) * t;
        }
    }

    template <std::size_t CHANNEL>
     static constexpr value_t clamp(value_t v) {
        return v < range<CHANNEL, false>() ? range<CHANNEL, false>() : v > range<CHANNEL, true>() ? range<CHANNEL, true>() : v;
    }
};

template <>
struct pixel_traits<hsva> {
    using value_t = float;
    static constexpr constants::color_channel color_channel_1 = constants::color_channel::H;
    static constexpr constants::color_channel color_channel_2 = constants::color_channel::S;
    static constexpr constants::color_channel color_channel_3 = constants::color_channel::V;
    static constexpr constants::color_channel color_channel_4 = constants::color_channel::A;

    static constexpr int CHANNELS = 4;

    static constexpr value_t c_MAX[CHANNELS] = {1.f, 1.f, 1.f, 1.f};
    static constexpr value_t c_MIN[CHANNELS] = {0.f, 0.f, 0.f, 0.f};

    static constexpr value_t DEFAULT_GRAY = 0.5f;

    template <std::size_t CHANNEL, bool IsMAX>
    static constexpr value_t range() {
        static_assert(1 <= CHANNEL && CHANNEL <= CHANNELS);
        if constexpr (IsMAX) {
            return c_MAX[CHANNEL - 1];
        } else {
            return c_MIN[CHANNEL - 1];
        }
    }

    template <std::size_t CHANNEL>
    static constexpr value_t normalize(uint32_t x) {
        constexpr float inv = 1.0f / static_cast<float>(std::numeric_limits<uint32_t>::max());
        return x * inv * range<CHANNEL, true>();
    }

    template <std::size_t CHANNEL>
    static constexpr float lerp(float h1, float h2, float t) {
        if constexpr (CHANNEL == 1) {
            float d = std::fmod(h2 - h1 + 540.0f, 360.0f) - 180.0f;
            float h = h1 + d * t;
            return std::fmod(h + 360.0f, 360.0f);
        } else {
            return h1 + (h2 - h1) * t;
        }
    }

    template <std::size_t CHANNEL>
    static constexpr value_t clamp(value_t v) {
        return v < range<CHANNEL, false>() ? range<CHANNEL, false>() : v > range<CHANNEL, true>() ? range<CHANNEL, true>() : v;
    }
};

template <>
struct pixel_traits<hsl> {
    using value_t = float;
    static constexpr constants::color_channel color_channel_1 = constants::color_channel::H;
    static constexpr constants::color_channel color_channel_2 = constants::color_channel::S;
    static constexpr constants::color_channel color_channel_3 = constants::color_channel::L;

    static constexpr int CHANNELS = 3;

    static constexpr value_t c_MAX[CHANNELS] = {360.f, 1.f, 1.f};
    static constexpr value_t c_MIN[CHANNELS] = {0.f, 0.f, 0.f};

    static constexpr value_t DEFAULT_GRAY = 0.5f;

    template <std::size_t CHANNEL, bool IsMAX>
    static constexpr value_t range() {
        static_assert(1 <= CHANNEL && CHANNEL <= CHANNELS);
        if constexpr (IsMAX) {
            return c_MAX[CHANNEL - 1];
        } else {
            return c_MIN[CHANNEL - 1];
        }
    }

    template <std::size_t CHANNEL>
    static constexpr value_t normalize(uint32_t x) {
        constexpr float inv = 1.0f / static_cast<float>(std::numeric_limits<uint32_t>::max());
        return x * inv * range<CHANNEL, true>();
    }


    template <std::size_t CHANNEL>
    static constexpr float lerp(float h1, float h2, float t) {
        if constexpr (CHANNEL == 1) {
            float d = std::fmod(h2 - h1 + 540.0f, 360.0f) - 180.0f;
            float h = h1 + d * t;
            return std::fmod(h + 360.0f, 360.0f);
        } else {
            return h1 + (h2 - h1) * t;
        }
    }

    template <std::size_t CHANNEL>
    static constexpr value_t clamp(value_t v) {
        return v < range<CHANNEL, false>() ? range<CHANNEL, false>() : v > range<CHANNEL, true>() ? range<CHANNEL, true>() : v;
    }
};

template <>
struct pixel_traits<hsla> {
    using value_t = float;
    static constexpr constants::color_channel color_channel_1 = constants::color_channel::H;
    static constexpr constants::color_channel color_channel_2 = constants::color_channel::S;
    static constexpr constants::color_channel color_channel_3 = constants::color_channel::L;
    static constexpr constants::color_channel color_channel_4 = constants::color_channel::A;

    static constexpr int CHANNELS = 4;

    static constexpr value_t c_MAX[CHANNELS] = {360.f, 1.f, 1.f, 1.f};
    static constexpr value_t c_MIN[CHANNELS] = {0.f, 0.f, 0.f, 0.f};

    static constexpr value_t DEFAULT_GRAY = 0.5f;

    template <std::size_t CHANNEL, bool IsMAX>
    static constexpr value_t range() {
        static_assert(1 <= CHANNEL && CHANNEL <= CHANNELS);
        if constexpr (IsMAX) {
            return c_MAX[CHANNEL - 1];
        } else {
            return c_MIN[CHANNEL - 1];
        }
    }

    template <std::size_t CHANNEL>
    static constexpr value_t normalize(uint32_t x) {
        constexpr float inv = 1.0f / static_cast<float>(std::numeric_limits<uint32_t>::max());
        return x * inv * range<CHANNEL, true>();
    }

    template <std::size_t CHANNEL>
    static constexpr float lerp(float h1, float h2, float t) {
        if constexpr (CHANNEL == 1) {
            float d = std::fmod(h2 - h1 + 540.0f, 360.0f) - 180.0f;
            float h = h1 + d * t;
            return std::fmod(h + 360.0f, 360.0f);
        } else {
            return h1 + (h2 - h1) * t;
        }
    }

    template <std::size_t CHANNEL>
    static constexpr value_t clamp(value_t v) {
        return v < range<CHANNEL, false>() ? range<CHANNEL, false>() : v > range<CHANNEL, true>() ? range<CHANNEL, true>() : v;
    }
};

}
