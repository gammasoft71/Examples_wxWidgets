cmake_minimum_required(VERSION 3.2)
project(ContainerControls)

if ("${CMAKE_CURRENT_SOURCE_DIR}" STREQUAL "${CMAKE_SOURCE_DIR}")
  find_package(wxWidgets REQUIRED core richtext ribbon aui gl)
  include(${wxWidgets_USE_FILE})
endif ()

add_subdirectory(CollapsiblePane)
add_subdirectory(Frame)
add_subdirectory(Panel)
add_subdirectory(RadioBox)
add_subdirectory(SplitterWindow)
add_subdirectory(StaticBox)
