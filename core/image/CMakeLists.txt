cmake_minimum_required(VERSION 3.31)
project(image_lib LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_library(image_lib STATIC)

target_sources(image_lib PUBLIC
        FILE_SET CXX_MODULES
        FILES

        utils/color_convert.ixx
        utils/color_parse.ixx

        color_constant.ixx
        color_channel.ixx
        color_tag.ixx
        color_space.ixx
        pixel_weights.ixx

        pixel_traits.ixx
        pixel.ixx
        pixel_RGB.ixx
        pixel_RGBA.ixx
        pixel_HSV.ixx
        pixel_HSVA.ixx
        pixel_impl.ixx

        color_tag.ixx
        color_builder/color_builder.ixx
        color_builder/color_builder_impl.ixx

        color.ixx

        mod.image.ixx
)

target_link_libraries(image_lib PRIVATE constexpr_utils_lib)

target_compile_features(image_lib PUBLIC cxx_std_23)

target_include_directories(image_lib PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
