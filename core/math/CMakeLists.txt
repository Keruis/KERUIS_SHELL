cmake_minimum_required(VERSION 3.31)
project(math LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_library(math_lib STATIC)

target_sources(math_lib PUBLIC
        FILE_SET CXX_MODULES
        FILES
        tag/vec2_tag.ixx
        tag/tag.ixx

        concepts/scalar.ixx
        concepts/vector.ixx
        concepts/concepts.ixx

        traits/vec_traits.ixx
        traits/traits.ixx

        vec/vec2/vec2_base.ixx
        vec/vec2/vec2_impl.cppm
        vec/vec2/vec2_ops.ixx
        vec/vec2.ixx
)

target_compile_features(math_lib PUBLIC cxx_std_23)

target_include_directories(math_lib PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})