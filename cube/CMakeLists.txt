cmake_minimum_required(VERSION 3.10)

set(CPP_COMPILE_FLAG "-g -Wall")

include_directories(${CMAKE_SOURCE_DIR}/sharedlib
                    ${CMAKE_SOURCE_DIR}/cube)

add_definitions(${CPP_COMPILE_FLAG})

add_executable(cube cube_main.cpp
                    cube_app.cpp
                    cube_cube_generator.cpp
                    cube_program.cpp)

set_property(TARGET cube PROPERTY CXX_STANDARD 11)

target_link_libraries(cube sharedlib opengl32 glfw3 glew32)

