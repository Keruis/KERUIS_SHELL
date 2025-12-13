cmake_minimum_required(VERSION 3.29)
project(constexpr_utils_lib LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_library(constexpr_utils_lib STATIC)

target_sources(constexpr_utils_lib PUBLIC
        FILE_SET CXX_MODULES
        FILES

        is_space.ixx
        string_literal.ixx
        hash.ixx
        compile_time_seed.ixx

        mod.constexpr_utils.ixx
)

target_compile_features(constexpr_utils_lib PUBLIC cxx_std_23)

target_include_directories(constexpr_utils_lib PUBLIC ../constexpr)
