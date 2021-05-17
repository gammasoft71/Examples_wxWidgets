cmake_minimum_required(VERSION 3.2)
project(WindowDocking)

if ("${CMAKE_CURRENT_SOURCE_DIR}" STREQUAL "${CMAKE_SOURCE_DIR}")
  find_package(wxWidgets REQUIRED core richtext ribbon aui gl webview)
  include(${wxWidgets_USE_FILE})
endif ()

add_subdirectory(AuiManager)
add_subdirectory(AuiNotebook)
add_subdirectory(AuiToolbar)
