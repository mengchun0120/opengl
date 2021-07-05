cmake_minimum_required(VERSION 3.10)

set(CPP_COMPILE_FLAG "-g -Wall")

include_directories(${CMAKE_SOURCE_DIR}/sharedlib/src
                    ${CMAKE_SOURCE_DIR}/sphere/src)

add_definitions(${CPP_COMPILE_FLAG})

add_executable(sphere src/sphere_sphere_generator.cpp
                      src/sphere_app.cpp
                      src/sphere_main.cpp)

set_property(TARGET sphere PROPERTY CXX_STANDARD 11)
target_link_libraries(sphere sharedlib opengl32 glfw3 glew32)

add_executable(test_sphere test/test_main.cpp
                           test/test_sphere_generator.cpp
                           src/sphere_sphere_generator.cpp)

set_property(TARGET test_sphere PROPERTY CXX_STANDARD 11)
target_link_libraries(test_sphere sharedlib gtest gmock)

