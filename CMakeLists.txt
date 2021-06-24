cmake_minimum_required(VERSION 3.10)

project(opengl CXX)

add_subdirectory(sharedlib)
add_subdirectory(test)
add_subdirectory(gasket2drand)
add_subdirectory(gasket2dline)
add_subdirectory(gasket3drand)
add_subdirectory(gasket3dline)
add_subdirectory(tetra)
add_subdirectory(cube)
add_subdirectory(lookatortho)
add_subdirectory(perspective)

