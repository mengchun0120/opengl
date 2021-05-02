cmake_minimum_required(VERSION 3.10)

set(CPP_COMPILE_FLAG "-g -Wall")

include_directories(${CMAKE_SOURCE_DIR}/sharedlib
                    ${CMAKE_SOURCE_DIR}/gasket3drand)

add_definitions(${CPP_COMPILE_FLAG})

add_executable(gasket3drand gasket3drand_vectors.cpp
                            gasket3drand_program.cpp
                            gasket3drand_app.cpp
                            gasket3drand_main.cpp)

set_property(TARGET gasket3drand PROPERTY CXX_STANDARD 11)

target_link_libraries(gasket3drand sharedlib opengl32 glfw3 glew32)

