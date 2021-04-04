cmake_minimum_required(VERSION 3.10)

set(CPP_COMPILE_FLAG "-g -Wall")

include_directories(${CMAKE_SOURCE_DIR}/sharedlib
                    ${CMAKE_SOURCE_DIR}/gasket2dline)

file(GLOB_RECURSE GASKET2DLINE_SOURCES RELATIVE
     ${CMAKE_SOURCE_DIR}/gasket2dline "*.cpp")

add_definitions(${CPP_COMPILE_FLAG})

add_executable(gasket2dline ${GASKET2DLINE_SOURCES})

set_property(TARGET gasket2dline PROPERTY CXX_STANDARD 11)

target_link_libraries(gasket2dline sharedlib opengl32 glfw3 glew32)

