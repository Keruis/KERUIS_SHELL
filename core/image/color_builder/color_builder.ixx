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
        static KS_CONSTEXPR pixel_t build() KS_NOEXCEPT
        requires (pixel_t::traits::CHANNELS == 3) {
            return pixel_t{
                ColorLookup<CM>::template Color<CT>::template ChannelConst<pixel_t::traits::color_channel_1>::value,
                ColorLookup<CM>::template Color<CT>::template ChannelConst<pixel_t::traits::color_channel_2>::value,
                ColorLookup<CM>::template Color<CT>::template ChannelConst<pixel_t::traits::color_channel_3>::value
            };
        }

        static KS_CONSTEXPR pixel_t build(const typename pixel_t::value_t alpha = pixel_t::traits::MAX) KS_NOEXCEPT
        requires (pixel_t::traits::CHANNELS == 4) {
            return pixel_t{
                ColorLookup<CM>::template Color<CT>::template ChannelConst<pixel_t::traits::color_channel_1>::value,
                ColorLookup<CM>::template Color<CT>::template ChannelConst<pixel_t::traits::color_channel_2>::value,
                ColorLookup<CM>::template Color<CT>::template ChannelConst<pixel_t::traits::color_channel_3>::value,
                alpha
            };
        }
    };
};

}