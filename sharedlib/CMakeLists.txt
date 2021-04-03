cmake_minimum_required(VERSION 3.10)

set(CPP_COMPILE_FLAG "-g -Wall")

include_directories(${CMAKE_SOURCE_DIR}/sharedlib)
file(GLOB_RECURSE SHAREDLIB_SOURCES RELATIVE
     ${CMAKE_SOURCE_DIR}/sharedlib "*.cpp")

add_definitions(${CPP_COMPILE_FLAG})

add_library(sharedlib ${SHAREDLIB_SOURCES})

set_property(TARGET sharedlib PROPERTY CXX_STANDARD 11)

target_link_libraries(sharedlib opengl32 glfw3 glew32)

