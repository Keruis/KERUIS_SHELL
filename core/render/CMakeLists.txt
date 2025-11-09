cmake_minimum_required(VERSION 3.31)
project(render_lib LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_library(render_lib_types STATIC)
target_sources(render_lib_types
        PUBLIC FILE_SET CXX_MODULES FILES
        input/mouse/mouse.types.ixx
        input/keyboard/keyboard.types.ixx
)
target_compile_features(render_lib_types PUBLIC cxx_std_23)
target_include_directories(render_lib_types PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

add_library(render_lib STATIC)

target_sources(render_lib PUBLIC
        FILE_SET CXX_MODULES
        FILES

        utils/frameLimiter.ixx
        utils/frameLimiter_impl.cppm

        utils/frameRateCounter.ixx
        utils/frameRateCounter_impl.cppm

        input/mouse/mouse.ixx
        input/mouse/mouse_impl.cppm

        input/keyboard/keyboard.ixx
        input/keyboard/keyboard_impl.cppm

        utils/mod.render.utils.ixx
        input/mod.render.input.ixx
        mod.render.ixx
)

target_link_libraries(render_lib
        PRIVATE platform_lib
        PRIVATE render_lib_types
)

target_compile_features(render_lib PUBLIC cxx_std_23)
target_include_directories(render_lib PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})