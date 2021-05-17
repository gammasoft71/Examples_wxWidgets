cmake_minimum_required(VERSION 3.2)
project(Applications)

if ("${CMAKE_CURRENT_SOURCE_DIR}" STREQUAL "${CMAKE_SOURCE_DIR}")
  find_package(wxWidgets REQUIRED core richtext ribbon aui gl)
  include(${wxWidgets_USE_FILE})
endif ()

add_subdirectory(Application)
add_subdirectory(ApplicationAndException)
add_subdirectory(ApplicationAndMain)
add_subdirectory(ApplicationAndMain2)
add_subdirectory(ApplicationIcon)
