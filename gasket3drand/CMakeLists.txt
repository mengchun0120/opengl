cmake_minimum_required(VERSION 3.10)

set(CPP_COMPILE_FLAG "-g -Wall")

include_directories(${CMAKE_SOURCE_DIR}/sharedlib
                    ${CMAKE_SOURCE_DIR}/gasket3drand)

file(GLOB_RECURSE GASKET3DRAND_SOURCES RELATIVE
     ${CMAKE_SOURCE_DIR}/gasket3drand "*.cpp")

add_definitions(${CPP_COMPILE_FLAG})

add_executable(gasket3drand ${GASKET3DRAND_SOURCES})

set_property(TARGET gasket3drand PROPERTY CXX_STANDARD 11)

target_link_libraries(gasket3drand sharedlib opengl32 glfw3 glew32)

