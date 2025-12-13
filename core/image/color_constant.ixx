module;

#include <tuple>

export module ks.core.image.color_constant;

import ks.core.image.color_space;
import ks.core.image.color_channel;
import ks.core.image.utils.color_parse;
import ks.core.constexpr_utils.string_literal;

import ks.core.image.pixel_impl;

import ks.core.image.utils.color_convert;

export namespace ks::core::image {

template <color_model CM>
struct ColorLookup {
    template <string_literal STR>
    struct Color {
        template <constants::color_channel CH>
        struct ChannelConst {
            using value_t = typename pixel<CM>::traits::value_t;

            static constexpr value_t get_value() {
                if constexpr (CM == rgb || CM == rgba) {
                    if (CH == constants::color_channel::R) {
                        return utils::get_color<STR>()->r;
                    } else if constexpr (CH == constants::color_channel::G) {
                        return utils::get_color<STR>()->g;
                    } else {
                        return utils::get_color<STR>()->b;
                    }
                } else if constexpr (CM == hsv || CM == hsva) {
                    constexpr auto hsv = utils::rgb_to_hsv(utils::get_color<STR>()->r, utils::get_color<STR>()->g, utils::get_color<STR>()->b);
                    if (CH == constants::color_channel::H) {
                        return std::get<0>(hsv);
                    } else if constexpr (CH == constants::color_channel::S) {
                        return std::get<1>(hsv);
                    } else {
                        return std::get<2>(hsv);
                    }
                }
                return value_t{};
            }

        };
    };
};

}