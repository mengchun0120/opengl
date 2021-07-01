cmake_minimum_required(VERSION 3.10)

set(CPP_COMPILE_FLAG "-g -Wall")

include_directories(${CMAKE_SOURCE_DIR}/test
                    ${CMAKE_SOURCE_DIR}/sharedlib)

add_definitions(${CPP_COMPILE_FLAG})

add_executable(test test_main.cpp
                    test_sharedlib_vector.cpp
                    test_sharedlib_matrix.cpp
                    test_sharedlib_validator.cpp)

set_property(TARGET test PROPERTY CXX_STANDARD 11)

target_link_libraries(test sharedlib gtest gmock opengl32 glfw3 glew32)

