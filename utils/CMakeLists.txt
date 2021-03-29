cmake_minimum_required(VERSION 3.10)

set(CPP_COMPILE_FLAG "-g -Wall")

include_directories(${CMAKE_SOURCE_DIR}/utils)
file(GLOB_RECURSE UTILS_SOURCES RELATIVE ${CMAKE_SOURCE_DIR}/utils "*.cpp")

add_definitions(${CPP_COMPILE_FLAG})

add_library(utils ${UTILS_SOURCES})

set_property(TARGET utils PROPERTY CXX_STANDARD 11)

target_link_libraries(shared_lib opengl32 glfw3 glew32)

