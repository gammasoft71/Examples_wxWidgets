cmake_minimum_required(VERSION 3.5)

# Project
project(AnimationCtrl)

find_package(wxWidgets REQUIRED)
include(${wxWidgets_USE_FILE})

set(SOURCES README.md AnimationCtrl.cpp)

# Resources
set(RESOURCES Resources/load.gif)
if (APPLE)
  set_source_files_properties(Resources/load.gif PROPERTIES MACOSX_PACKAGE_LOCATION "Resources")
else ()
  configure_file(Resources/load.gif ${CMAKE_CURRENT_BINARY_DIR}/Resources/load.gif COPYONLY)
  configure_file(Resources/load.gif ${CMAKE_CURRENT_BINARY_DIR}/Debug/Resources/load.gif COPYONLY)
  configure_file(Resources/load.gif ${CMAKE_CURRENT_BINARY_DIR}/Release/Resources/load.gif COPYONLY)
endif ()

# Options
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Target
add_executable(${PROJECT_NAME} WIN32 MACOSX_BUNDLE ${SOURCES} ${RESOURCES})
target_link_libraries(${PROJECT_NAME} ${wxWidgets_LIBRARIES})
set_target_properties(${PROJECT_NAME} PROPERTIES FOLDER "Controls")
