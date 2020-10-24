cmake_minimum_required(VERSION 3.2)
project(OpenGL)

find_package(OpenGL)
if(OPENGL_FOUND)
  add_subdirectory(Dice)
else()
  message(WARNING "OpenGL not found : Install OpenGL to generate OpenGL examples")
endif()
