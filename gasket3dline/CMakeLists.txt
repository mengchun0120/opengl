cmake_minimum_required(VERSION 3.10)

set(CPP_COMPILE_FLAG "-g -Wall")

include_directories(${CMAKE_SOURCE_DIR}/sharedlib/src
                    ${CMAKE_SOURCE_DIR}/gasket3dline)

add_definitions(${CPP_COMPILE_FLAG})

add_executable(gasket3dline gasket3dline_generator.cpp
                            gasket3dline_program.cpp
                            gasket3dline_app.cpp
                            gasket3dline_main.cpp)

set_property(TARGET gasket3dline PROPERTY CXX_STANDARD 11)

target_link_libraries(gasket3dline sharedlib opengl32 glfw3 glew32)

