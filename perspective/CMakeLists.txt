cmake_minimum_required(VERSION 3.10)

set(CPP_COMPILE_FLAG "-g -Wall")

include_directories(${CMAKE_SOURCE_DIR}/sharedlib
                    ${CMAKE_SOURCE_DIR}/perspective)

add_definitions(${CPP_COMPILE_FLAG})

add_executable(perspective perspective_main.cpp
                           perspective_program.cpp
                           perspective_cube_generator.cpp
                           perspective_app.cpp)

set_property(TARGET perspective PROPERTY CXX_STANDARD 11)

target_link_libraries(perspective sharedlib opengl32 glfw3 glew32)

