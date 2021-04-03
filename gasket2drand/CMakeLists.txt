cmake_minimum_required(VERSION 3.10)

set(CPP_COMPILE_FLAG "-g -Wall")

include_directories(${CMAKE_SOURCE_DIR}/sharedlib
                    ${CMAKE_SOURCE_DIR}/gasket2drand)

file(GLOB_RECURSE GASKET2DRAND_SOURCES RELATIVE
     ${CMAKE_SOURCE_DIR}/gasket2drand "*.cpp")

add_definitions(${CPP_COMPILE_FLAG})

add_executable(gasket2drand ${GASKET2DRAND_SOURCES})

set_property(TARGET gasket2drand PROPERTY CXX_STANDARD 11)

target_link_libraries(gasket2drand sharedlib opengl32 glfw3 glew32)

