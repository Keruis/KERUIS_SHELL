cmake_minimum_required(VERSION 3.29)
project(KERUIS_SHELL CXX)

set(CMAKE_CXX_STANDARD 23)

add_executable(KERUIS_SHELL
        main.cpp
        core/memory/allocator.cpp
)