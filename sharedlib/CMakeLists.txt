cmake_minimum_required(VERSION 3.10)

set(CPP_COMPILE_FLAG "-g -Wall")

include_directories(${CMAKE_SOURCE_DIR}/sharedlib)

add_definitions(${CPP_COMPILE_FLAG})

add_library(sharedlib sharedlib_my_exception.cpp
                      sharedlib_file_utils.cpp
                      sharedlib_math_utils.cpp
                      sharedlib_vector.cpp
                      sharedlib_matrix.cpp
                      sharedlib_buffer_block.cpp
                      sharedlib_shader_program.cpp
                      sharedlib_vertex_array.cpp
                      sharedlib_app.cpp)

set_property(TARGET sharedlib PROPERTY CXX_STANDARD 11)

target_link_libraries(sharedlib opengl32 glfw3 glew32)

