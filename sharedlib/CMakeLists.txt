cmake_minimum_required(VERSION 3.10)

set(CPP_COMPILE_FLAG "-g -Wall")

include_directories(${CMAKE_SOURCE_DIR}/sharedlib/src)

add_definitions(${CPP_COMPILE_FLAG})

add_library(sharedlib src/sharedlib_my_exception.cpp
                      src/sharedlib_file_utils.cpp
                      src/sharedlib_math_utils.cpp
                      src/sharedlib_random_utils.cpp
                      src/sharedlib_vector.cpp
                      src/sharedlib_matrix.cpp
                      src/sharedlib_buffer_block.cpp
                      src/sharedlib_shader_program.cpp
                      src/sharedlib_vertex_array.cpp
                      src/sharedlib_validator.cpp
                      src/sharedlib_out.cpp
                      src/sharedlib_stringify.cpp
                      src/sharedlib_json_utils.cpp
                      src/sharedlib_parse_json.cpp
                      src/sharedlib_json_param.cpp
                      src/sharedlib_app.cpp)

set_property(TARGET sharedlib PROPERTY CXX_STANDARD 11)
target_link_libraries(sharedlib opengl32 glfw3 glew32)

add_executable(test_sharedlib test/test_vector.cpp
                              test/test_matrix.cpp
                              test/test_json_param.cpp
                              test/test_validator.cpp
                              test/test_main.cpp)

set_property(TARGET test_sharedlib PROPERTY CXX_STANDARD 11)
target_link_libraries(test_sharedlib sharedlib gtest gmock opengl32 glfw3 glew32)

