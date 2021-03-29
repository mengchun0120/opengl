cmake_minimum_required(VERSION 3.10)

set(CPP_COMPILE_FLAG "-g -Wall -DENABLE_LOG")

include_directories(${CMAKE_SOURCE_DIR}/shared_lib/misc)
file(GLOB_RECURSE SHARED_LIB_SOURCES RELATIVE ${CMAKE_SOURCE_DIR}/shared_lib "*.cpp")

add_definitions(${CPP_COMPILE_FLAG})

add_library(shared_lib ${SHARED_LIB_SOURCES})

set_property(TARGET shared_lib PROPERTY CXX_STANDARD 11)


if(UNIX)
    target_link_libraries(shared_lib GL GLEW glfw dl m Xrandr Xi X11 Xxf86vm Xinerama Xcursor pthread)
elseif(MINGW)
    target_link_libraries(shared_lib opengl32 glfw3 glew32)
endif()

