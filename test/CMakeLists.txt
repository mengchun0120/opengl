cmake_minimum_required(VERSION 3.10)

set(CPP_COMPILE_FLAG "-g -Wall")

include_directories(${CMAKE_SOURCE_DIR}/test)
file(GLOB_RECURSE TEST_SOURCES RELATIVE
     ${CMAKE_SOURCE_DIR}/test "*.cpp")

add_definitions(${CPP_COMPILE_FLAG})

add_executable(test ${TEST_SOURCES})

set_property(TARGET test PROPERTY CXX_STANDARD 11)

target_link_libraries(test sharedlib gtest gmock opengl32 glfw3 glew32)

