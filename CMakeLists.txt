cmake_minimum_required(VERSION 3.31)
project(KERUIS_SHELL CXX)

set(CMAKE_CXX_STANDARD 23)

add_subdirectory(core/math)

add_executable(KERUIS_SHELL
        app/main.cpp
)

target_link_libraries(KERUIS_SHELL math_lib)