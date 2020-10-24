cmake_minimum_required(VERSION 3.2)
project(OpenGL)

find_package(OpenGL)
if(OPENGL_FOUND)
  add_subdirectory(Cube)
endif()
