cmake_minimum_required(VERSION 3.31)
project(string_lib LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_library(string_lib STATIC)

target_sources(string_lib PUBLIC
        FILE_SET CXX_MODULES
        FILES

        string_category.ixx
        string_trait.ixx
        string_box.ixx
        string_core.ixx
        basic_string.ixx
        string.ixx

        mod.string.ixx
)

target_compile_features(string_lib PUBLIC cxx_std_23)

target_include_directories(string_lib PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
