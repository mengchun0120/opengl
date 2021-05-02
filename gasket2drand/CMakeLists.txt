cmake_minimum_required(VERSION 3.10)

set(CPP_COMPILE_FLAG "-g -Wall")

include_directories(${CMAKE_SOURCE_DIR}/sharedlib
                    ${CMAKE_SOURCE_DIR}/gasket2drand)

add_definitions(${CPP_COMPILE_FLAG})

add_executable(gasket2drand gasket2drand_vectors.cpp
                            gasket2drand_program.cpp
                            gasket2drand_app.cpp
                            gasket2drand_main.cpp)

set_property(TARGET gasket2drand PROPERTY CXX_STANDARD 11)

target_link_libraries(gasket2drand sharedlib opengl32 glfw3 glew32)

