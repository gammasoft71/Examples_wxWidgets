cmake_minimum_required(VERSION 3.2)
project(PickerControls)

if ("${CMAKE_CURRENT_SOURCE_DIR}" STREQUAL "${CMAKE_SOURCE_DIR}")
  find_package(wxWidgets REQUIRED core richtext ribbon aui gl)
  include(${wxWidgets_USE_FILE})
endif ()

add_subdirectory("ColourPickerCtrl")
add_subdirectory("DatePickerCtrl")
add_subdirectory("DirPickerCtrl")
add_subdirectory("FilePickerCtrl")
add_subdirectory("FontPickerCtrl")
add_subdirectory("TimePickerCtrl")
