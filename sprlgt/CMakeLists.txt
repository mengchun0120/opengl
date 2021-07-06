cmake_minimum_required(VERSION 3.10)

set(CPP_COMPILE_FLAG "-g -Wall")

include_directories(${CMAKE_SOURCE_DIR}/sharedlib/src
                    ${CMAKE_SOURCE_DIR}/sprlgt/src)

add_definitions(${CPP_COMPILE_FLAG})

add_executable(sprlgt src/sprlgt_sphere_generator.cpp
                      src/sprlgt_sphere_lighting_app.cpp
                      src/sprlgt_sphere_lighting_shader_program.cpp
                      src/sprlgt_main.cpp)

set_property(TARGET sprlgt PROPERTY CXX_STANDARD 11)
target_link_libraries(sprlgt sharedlib opengl32 glfw3 glew32)

add_executable(test_sprlgt test/test_main.cpp
                           test/test_sphere_generator.cpp
                           src/sprlgt_sphere_generator.cpp)

set_property(TARGET test_sprlgt PROPERTY CXX_STANDARD 11)
target_link_libraries(test_sprlgt sharedlib gtest gmock)

