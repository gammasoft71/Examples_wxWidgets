cmake_minimum_required(VERSION 3.20)
project(wxGL)

set_property(GLOBAL PROPERTY USE_FOLDERS ON)

set(OpenGL_GL_PREFERENCE GLVND)
find_package(OpenGL)

if(OPENGL_FOUND)
  add_subdirectory(Controls)
else()
  message(WARNING "OpenGL not found : Install OpenGL to generate wxGL examples")
endif()
