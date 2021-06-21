cmake_minimum_required(VERSION 3.10)

set(CPP_COMPILE_FLAG "-g -Wall")

include_directories(${CMAKE_SOURCE_DIR}/sharedlib
                    ${CMAKE_SOURCE_DIR}/lookatortho)

add_definitions(${CPP_COMPILE_FLAG})

add_executable(lookatortho lookatortho_main.cpp
                           lookatortho_program.cpp
                           lookatortho_cube_generator.cpp
                           lookatortho_app.cpp)

set_property(TARGET cube PROPERTY CXX_STANDARD 11)

target_link_libraries(lookatortho sharedlib opengl32 glfw3 glew32)

