cmake_minimum_required(VERSION 3.31)
project(KERUIS_SHELL CXX)

set(CMAKE_CXX_STANDARD 23)

add_subdirectory(core/math)
#add_subdirectory(platform)
#add_subdirectory(core/render)
#add_subdirectory(core/string)
add_subdirectory(core/image)

add_executable(KERUIS_SHELL
        app/main.cpp
)

target_link_libraries(KERUIS_SHELL math_lib)
#target_link_libraries(KERUIS_SHELL platform_lib)
#target_link_libraries(KERUIS_SHELL render_lib)
#target_link_libraries(KERUIS_SHELL string_lib)
target_link_libraries(KERUIS_SHELL image_lib)