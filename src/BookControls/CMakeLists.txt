cmake_minimum_required(VERSION 3.2)
project(BookControls)

if ("${CMAKE_CURRENT_SOURCE_DIR}" STREQUAL "${CMAKE_SOURCE_DIR}")
  find_package(wxWidgets REQUIRED core richtext ribbon aui gl)
  include(${wxWidgets_USE_FILE})
endif ()

add_subdirectory(Choicebook)
add_subdirectory(Listbook)
add_subdirectory(Notebook)
add_subdirectory(Simplebook)
add_subdirectory(Toolbook)
add_subdirectory(Treebook)
