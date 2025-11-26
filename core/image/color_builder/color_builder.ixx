module;

#include "../../utils/attributes.h"

export module ks.core.image.color_builder_impl:color_builder;

import ks.core.image.color_tag;
import ks.core.image.color_space;
import ks.core.image.color_channel;
import ks.core.image.pixel_impl;
import ks.core.image.color_constant;

export namespace ks::core::image {

template <color_model CM>
struct color_builder {
    template <color_tag CT>
    struct make {
        using pixel_t = pixel<CM>;
        template <typename... Args>
        static KS_CONSTEXPR pixel_t build(Args... args) KS_NOEXCEPT {
            if constexpr (pixel_t::traits::CHANNELS == 3) {
                static_assert(sizeof...(Args) == 0,
                              "RGB pixel does not accept extra arguments");
                return pixel_t{
                    ColorLookup<CM>::template Color<CT>::template ChannelConst<pixel_t::traits::color_channel_1>::value,
                    ColorLookup<CM>::template Color<CT>::template ChannelConst<pixel_t::traits::color_channel_2>::value,
                    ColorLookup<CM>::template Color<CT>::template ChannelConst<pixel_t::traits::color_channel_3>::value
                };
            } else if constexpr (pixel_t::traits::CHANNELS == 4) {
                static_assert(sizeof...(Args) <= 1,
                              "RGBA pixel accepts at most 1 extra argument for alpha");
                typename pixel_t::value_t alpha = pixel_t::traits::MAX;
                if constexpr (sizeof...(Args) == 1) {
                    alpha = (args, ...);
                }
                return pixel_t{
                    ColorLookup<CM>::template Color<CT>::template ChannelConst<pixel_t::traits::color_channel_1>::value,
                    ColorLookup<CM>::template Color<CT>::template ChannelConst<pixel_t::traits::color_channel_2>::value,
                    ColorLookup<CM>::template Color<CT>::template ChannelConst<pixel_t::traits::color_channel_3>::value,
                    alpha
                };
            } else {
                static_assert(pixel_t::traits::CHANNELS == 3 || pixel_t::traits::CHANNELS == 4,
                              "Only RGB and RGBA pixels are supported");
            }
            return pixel_t{};
        }
    };
};

}