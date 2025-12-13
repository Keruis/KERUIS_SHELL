cmake_minimum_required(VERSION 3.29)
project(platform_lib LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_library(platform_lib STATIC)

target_sources(platform_lib PUBLIC
        FILE_SET CXX_MODULES
        FILES

        common/ICursorController.ixx
        common/IWindow.ixx

        win32/CursorController.win32.ixx
        win32/Window.win32.ixx

        mod.platform.ixx
)

target_compile_features(platform_lib PUBLIC cxx_std_23)

target_include_directories(platform_lib PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

target_link_libraries(platform_lib
        PRIVATE render_lib_types
)

if (WIN32)
    target_link_libraries(platform_lib
            PRIVATE dinput8 dxguid
    )
endif()