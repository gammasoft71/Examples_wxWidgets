cmake_minimum_required(VERSION 3.2)
project(OpenGL)

if ("${CMAKE_CURRENT_SOURCE_DIR}" STREQUAL "${CMAKE_SOURCE_DIR}")
  find_package(wxWidgets REQUIRED core richtext ribbon aui gl)
  include(${wxWidgets_USE_FILE})
endif ()

find_package(OpenGL)
if(OPENGL_FOUND)
  add_subdirectory(Dice)
else()
  message(WARNING "OpenGL not found : Install OpenGL to generate OpenGL examples")
endif()
