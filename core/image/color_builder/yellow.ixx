module;

#include "../../utils/attributes.h"

export module ks.core.image.color_builder_impl:yellow;

import ks.core.image.color_tag;
import ks.core.image.color_space;
import ks.core.image.color_channel;
import ks.core.image.pixel_impl;
import :color_builder;
import ks.core.image.color_constant;

export namespace ks::core::image {

template <>
template <>
struct color_builder<rgb>::make<color_tag::Yellow> {
    using pixel_t = pixel<rgb>;
    static KS_CONSTEXPR pixel_t build(KS_MAYBE_UNUSED const pixel_t::value_t alpha = pixel_t::traits::MAX) KS_NOEXCEPT {
        return pixel_t{
            ColorLookup<rgb>::Color<color_tag::Yellow>::ChannelConst<constants::color_channel::R>::value,
            ColorLookup<rgb>::Color<color_tag::Yellow>::ChannelConst<constants::color_channel::G>::value,
            ColorLookup<rgb>::Color<color_tag::Yellow>::ChannelConst<constants::color_channel::B>::value
        };
    }
};

template <>
template <>
struct color_builder<rgba>::make<color_tag::Yellow> {
    using pixel_t = pixel<rgba>;
    static KS_CONSTEXPR pixel_t build(const pixel_t::value_t alpha = pixel_t::traits::MAX) KS_NOEXCEPT {
        return pixel_t{
            ColorLookup<rgba>::Color<color_tag::Yellow>::ChannelConst<constants::color_channel::R>::value,
            ColorLookup<rgba>::Color<color_tag::Yellow>::ChannelConst<constants::color_channel::G>::value,
            ColorLookup<rgba>::Color<color_tag::Yellow>::ChannelConst<constants::color_channel::B>::value,
            alpha
        };
    }
};

template <>
template <>
struct color_builder<hsv>::make<color_tag::Yellow> {
    using pixel_t = pixel<hsv>;
    static KS_CONSTEXPR pixel_t build(KS_MAYBE_UNUSED const pixel_t::value_t alpha = pixel_t::traits::MAX) KS_NOEXCEPT {
        return pixel_t{
            ColorLookup<hsv>::Color<color_tag::Yellow>::ChannelConst<constants::color_channel::H>::value,
            ColorLookup<hsv>::Color<color_tag::Yellow>::ChannelConst<constants::color_channel::S>::value,
            ColorLookup<hsv>::Color<color_tag::Yellow>::ChannelConst<constants::color_channel::V>::value
        };
    }
};

template <>
template <>
struct color_builder<hsva>::make<color_tag::Yellow> {
    using pixel_t = pixel<hsva>;
    static KS_CONSTEXPR pixel_t build(const pixel_t::value_t alpha = pixel_t::traits::MAX) KS_NOEXCEPT {
        return pixel_t{
            ColorLookup<hsva>::Color<color_tag::Yellow>::ChannelConst<constants::color_channel::H>::value,
            ColorLookup<hsva>::Color<color_tag::Yellow>::ChannelConst<constants::color_channel::S>::value,
            ColorLookup<hsva>::Color<color_tag::Yellow>::ChannelConst<constants::color_channel::V>::value,
            alpha
        };
    }
};

}