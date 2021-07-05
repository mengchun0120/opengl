cmake_minimum_required(VERSION 3.10)

set(CPP_COMPILE_FLAG "-g -Wall")

include_directories(${CMAKE_SOURCE_DIR}/sharedlib/src
                    ${CMAKE_SOURCE_DIR}/gasket2dline)

add_definitions(${CPP_COMPILE_FLAG})

add_executable(gasket2dline gasket2dline_vectors.cpp
                            gasket2dline_program.cpp
                            gasket2dline_app.cpp
                            gasket2dline_main.cpp)

set_property(TARGET gasket2dline PROPERTY CXX_STANDARD 11)

target_link_libraries(gasket2dline sharedlib opengl32 glfw3 glew32)

