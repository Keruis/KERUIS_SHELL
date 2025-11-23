module;

#include <tuple>

export module ks.core.image.color_constant;

import ks.core.image.color_space;
import ks.core.image.color_tag;
import ks.core.image.color_channel;

import ks.core.image.utils.color_convert;

constexpr auto white_rgb = ks::core::image::utils::hex_to_rgb(0xFFFFFF);
constexpr auto white_hsv = ks::core::image::utils::rgb_to_hsv(std::get<0>(white_rgb), std::get<1>(white_rgb), std::get<2>(white_rgb));

constexpr auto black_rgb = ks::core::image::utils::hex_to_rgb(0x000000);
constexpr auto black_hsv = ks::core::image::utils::rgb_to_hsv(std::get<0>(black_rgb), std::get<1>(black_rgb), std::get<2>(black_rgb));

constexpr auto red_rgb = ks::core::image::utils::hex_to_rgb(0xFF0000);
constexpr auto red_hsv = ks::core::image::utils::rgb_to_hsv(std::get<0>(red_rgb), std::get<1>(red_rgb), std::get<2>(red_rgb));

constexpr auto yellow_rgb = ks::core::image::utils::hex_to_rgb(0xFF0000);
constexpr auto yellow_hsv = ks::core::image::utils::rgb_to_hsv(std::get<0>(yellow_rgb), std::get<1>(yellow_rgb), std::get<2>(yellow_rgb));


export namespace ks::core::image {

template <color_model>
struct ColorLookup {
    template <color_tag>
    struct Color {
        template <constants::color_channel>
        struct ChannelConst {

        };
    };
};

// === RGB / White / Channels ===
template <> template <> template <> struct ColorLookup<rgb>::Color<color_tag::White>::ChannelConst<constants::color_channel::R> { static constexpr unsigned char value = std::get<0>(white_rgb); };
template <> template <> template <> struct ColorLookup<rgb>::Color<color_tag::White>::ChannelConst<constants::color_channel::G> { static constexpr unsigned char value = std::get<1>(white_rgb); };
template <> template <> template <> struct ColorLookup<rgb>::Color<color_tag::White>::ChannelConst<constants::color_channel::B> { static constexpr unsigned char value = std::get<2>(white_rgb); };

// === RGBA / White / Channels ===
template <> template <> template <> struct ColorLookup<rgba>::Color<color_tag::White>::ChannelConst<constants::color_channel::R> { static constexpr unsigned char value = std::get<0>(white_rgb); };
template <> template <> template <> struct ColorLookup<rgba>::Color<color_tag::White>::ChannelConst<constants::color_channel::G> { static constexpr unsigned char value = std::get<1>(white_rgb); };
template <> template <> template <> struct ColorLookup<rgba>::Color<color_tag::White>::ChannelConst<constants::color_channel::B> { static constexpr unsigned char value = std::get<2>(white_rgb); };
template <> template <> template <> struct ColorLookup<rgba>::Color<color_tag::White>::ChannelConst<constants::color_channel::A> { static constexpr unsigned char value = 255; };

// === HSV / White / Channels ===
template <> template <> template <> struct ColorLookup<hsv>::Color<color_tag::White>::ChannelConst<constants::color_channel::H> { static constexpr float value = std::get<0>(white_hsv); };
template <> template <> template <> struct ColorLookup<hsv>::Color<color_tag::White>::ChannelConst<constants::color_channel::S> { static constexpr float value = std::get<1>(white_hsv); };
template <> template <> template <> struct ColorLookup<hsv>::Color<color_tag::White>::ChannelConst<constants::color_channel::V> { static constexpr float value = std::get<2>(white_hsv); };

// === HSVA / White / Channels ===
template <> template <> template <> struct ColorLookup<hsva>::Color<color_tag::White>::ChannelConst<constants::color_channel::H> { static constexpr float value = std::get<0>(white_hsv); };
template <> template <> template <> struct ColorLookup<hsva>::Color<color_tag::White>::ChannelConst<constants::color_channel::S> { static constexpr float value = std::get<1>(white_hsv); };
template <> template <> template <> struct ColorLookup<hsva>::Color<color_tag::White>::ChannelConst<constants::color_channel::V> { static constexpr float value = std::get<2>(white_hsv); };
template <> template <> template <> struct ColorLookup<hsva>::Color<color_tag::White>::ChannelConst<constants::color_channel::A> { static constexpr float value = 1.f; };


// === RGB / Black / Channels ===
template <> template <> template <> struct ColorLookup<rgb>::Color<color_tag::Black>::ChannelConst<constants::color_channel::R> { static constexpr unsigned char value = std::get<0>(black_rgb); };
template <> template <> template <> struct ColorLookup<rgb>::Color<color_tag::Black>::ChannelConst<constants::color_channel::G> { static constexpr unsigned char value = std::get<1>(black_rgb); };
template <> template <> template <> struct ColorLookup<rgb>::Color<color_tag::Black>::ChannelConst<constants::color_channel::B> { static constexpr unsigned char value = std::get<2>(black_rgb); };

// === RGBA / Black / Channels ===
template <> template <> template <> struct ColorLookup<rgba>::Color<color_tag::Black>::ChannelConst<constants::color_channel::R> { static constexpr unsigned char value = std::get<0>(black_rgb); };
template <> template <> template <> struct ColorLookup<rgba>::Color<color_tag::Black>::ChannelConst<constants::color_channel::G> { static constexpr unsigned char value = std::get<1>(black_rgb); };
template <> template <> template <> struct ColorLookup<rgba>::Color<color_tag::Black>::ChannelConst<constants::color_channel::B> { static constexpr unsigned char value = std::get<2>(black_rgb); };
template <> template <> template <> struct ColorLookup<rgba>::Color<color_tag::Black>::ChannelConst<constants::color_channel::A> { static constexpr unsigned char value = 255; };

// === HSV / Black / Channels ===
template <> template <> template <> struct ColorLookup<hsv>::Color<color_tag::Black>::ChannelConst<constants::color_channel::H> { static constexpr float value = std::get<0>(black_hsv); };
template <> template <> template <> struct ColorLookup<hsv>::Color<color_tag::Black>::ChannelConst<constants::color_channel::S> { static constexpr float value = std::get<1>(black_hsv); };
template <> template <> template <> struct ColorLookup<hsv>::Color<color_tag::Black>::ChannelConst<constants::color_channel::V> { static constexpr float value = std::get<2>(black_hsv); };

// === HSVA / Black / Channels ===
template <> template <> template <> struct ColorLookup<hsva>::Color<color_tag::Black>::ChannelConst<constants::color_channel::H> { static constexpr float value = std::get<0>(black_hsv); };
template <> template <> template <> struct ColorLookup<hsva>::Color<color_tag::Black>::ChannelConst<constants::color_channel::S> { static constexpr float value = std::get<1>(black_hsv); };
template <> template <> template <> struct ColorLookup<hsva>::Color<color_tag::Black>::ChannelConst<constants::color_channel::V> { static constexpr float value = std::get<2>(black_hsv); };
template <> template <> template <> struct ColorLookup<hsva>::Color<color_tag::Black>::ChannelConst<constants::color_channel::A> { static constexpr float value = 1.f; };


// === RGB / Red / Channels ===
template <> template <> template <> struct ColorLookup<rgb>::Color<color_tag::Red>::ChannelConst<constants::color_channel::R> { static constexpr unsigned char value = std::get<0>(red_rgb); };
template <> template <> template <> struct ColorLookup<rgb>::Color<color_tag::Red>::ChannelConst<constants::color_channel::G> { static constexpr unsigned char value = std::get<1>(red_rgb); };
template <> template <> template <> struct ColorLookup<rgb>::Color<color_tag::Red>::ChannelConst<constants::color_channel::B> { static constexpr unsigned char value = std::get<2>(red_rgb); };

// === RGBA / Red / Channels ===
template <> template <> template <> struct ColorLookup<rgba>::Color<color_tag::Red>::ChannelConst<constants::color_channel::R> { static constexpr unsigned char value = std::get<0>(red_rgb); };
template <> template <> template <> struct ColorLookup<rgba>::Color<color_tag::Red>::ChannelConst<constants::color_channel::G> { static constexpr unsigned char value = std::get<1>(red_rgb); };
template <> template <> template <> struct ColorLookup<rgba>::Color<color_tag::Red>::ChannelConst<constants::color_channel::B> { static constexpr unsigned char value = std::get<2>(red_rgb); };
template <> template <> template <> struct ColorLookup<rgba>::Color<color_tag::Red>::ChannelConst<constants::color_channel::A> { static constexpr unsigned char value = 255; };

// === HSV / Red / Channels ===
template <> template <> template <> struct ColorLookup<hsv>::Color<color_tag::Red>::ChannelConst<constants::color_channel::H> { static constexpr float value = std::get<0>(red_hsv); };
template <> template <> template <> struct ColorLookup<hsv>::Color<color_tag::Red>::ChannelConst<constants::color_channel::S> { static constexpr float value = std::get<1>(red_hsv); };
template <> template <> template <> struct ColorLookup<hsv>::Color<color_tag::Red>::ChannelConst<constants::color_channel::V> { static constexpr float value = std::get<2>(red_hsv); };

// === HSVA / Red / Channels ===
template <> template <> template <> struct ColorLookup<hsva>::Color<color_tag::Red>::ChannelConst<constants::color_channel::H> { static constexpr float value = std::get<0>(red_hsv); };
template <> template <> template <> struct ColorLookup<hsva>::Color<color_tag::Red>::ChannelConst<constants::color_channel::S> { static constexpr float value = std::get<1>(red_hsv); };
template <> template <> template <> struct ColorLookup<hsva>::Color<color_tag::Red>::ChannelConst<constants::color_channel::V> { static constexpr float value = std::get<2>(red_hsv); };
template <> template <> template <> struct ColorLookup<hsva>::Color<color_tag::Red>::ChannelConst<constants::color_channel::A> { static constexpr float value = 1.f; };


// === RGB / Yellow / Channels ===
template <> template <> template <> struct ColorLookup<rgb>::Color<color_tag::Yellow>::ChannelConst<constants::color_channel::R> { static constexpr unsigned char value = std::get<0>(yellow_rgb); };
template <> template <> template <> struct ColorLookup<rgb>::Color<color_tag::Yellow>::ChannelConst<constants::color_channel::G> { static constexpr unsigned char value = std::get<1>(yellow_rgb); };
template <> template <> template <> struct ColorLookup<rgb>::Color<color_tag::Yellow>::ChannelConst<constants::color_channel::B> { static constexpr unsigned char value = std::get<2>(yellow_rgb); };

// === RGBA / Yellow / Channels ===
template <> template <> template <> struct ColorLookup<rgba>::Color<color_tag::Yellow>::ChannelConst<constants::color_channel::R> { static constexpr unsigned char value = std::get<0>(yellow_rgb); };
template <> template <> template <> struct ColorLookup<rgba>::Color<color_tag::Yellow>::ChannelConst<constants::color_channel::G> { static constexpr unsigned char value = std::get<1>(yellow_rgb); };
template <> template <> template <> struct ColorLookup<rgba>::Color<color_tag::Yellow>::ChannelConst<constants::color_channel::B> { static constexpr unsigned char value = std::get<2>(yellow_rgb); };
template <> template <> template <> struct ColorLookup<rgba>::Color<color_tag::Yellow>::ChannelConst<constants::color_channel::A> { static constexpr unsigned char value = 255; };

// === HSV / Yellow / Channels ===
template <> template <> template <> struct ColorLookup<hsv>::Color<color_tag::Yellow>::ChannelConst<constants::color_channel::H> { static constexpr float value = std::get<0>(yellow_hsv); };
template <> template <> template <> struct ColorLookup<hsv>::Color<color_tag::Yellow>::ChannelConst<constants::color_channel::S> { static constexpr float value = std::get<1>(yellow_hsv); };
template <> template <> template <> struct ColorLookup<hsv>::Color<color_tag::Yellow>::ChannelConst<constants::color_channel::V> { static constexpr float value = std::get<2>(yellow_hsv); };

// === HSVA / Yellow / Channels ===
template <> template <> template <> struct ColorLookup<hsva>::Color<color_tag::Yellow>::ChannelConst<constants::color_channel::H> { static constexpr float value = std::get<0>(yellow_hsv); };
template <> template <> template <> struct ColorLookup<hsva>::Color<color_tag::Yellow>::ChannelConst<constants::color_channel::S> { static constexpr float value = std::get<1>(yellow_hsv); };
template <> template <> template <> struct ColorLookup<hsva>::Color<color_tag::Yellow>::ChannelConst<constants::color_channel::V> { static constexpr float value = std::get<2>(yellow_hsv); };
template <> template <> template <> struct ColorLookup<hsva>::Color<color_tag::Yellow>::ChannelConst<constants::color_channel::A> { static constexpr float value = 1.f; };

}