cmake_minimum_required(VERSION 3.10)

set(CPP_COMPILE_FLAG "-g -Wall")

include_directories(${CMAKE_SOURCE_DIR}/sharedlib
                    ${CMAKE_SOURCE_DIR}/tetrahedron)

file(GLOB_RECURSE TETRA_SOURCES RELATIVE
     ${CMAKE_SOURCE_DIR}/tetra "*.cpp")

add_definitions(${CPP_COMPILE_FLAG})

add_executable(tetra ${TETRA_SOURCES})

set_property(TARGET tetra PROPERTY CXX_STANDARD 11)

target_link_libraries(tetra sharedlib opengl32 glfw3 glew32)

