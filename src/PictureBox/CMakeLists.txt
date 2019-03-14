cmake_minimum_required(VERSION 3.0)
project(PictureBox)

find_package(wxWidgets REQUIRED)
include(${wxWidgets_USE_FILE})
link_libraries(${wxWidgets_LIBRARIES})

if(MSVC)
  set(GUI_OPTION WIN32)
elseif (APPLE)
  set(GUI_OPTION MACOSX_BUNDLE)
endif ()

configure_file(${CMAKE_CURRENT_SOURCE_DIR}/Resources/Logo.png ${EXECUTABLE_OUTPUT_PATH}/Resources/Logo.png COPYONLY)
configure_file(${CMAKE_CURRENT_SOURCE_DIR}/Resources/Logo.png ${EXECUTABLE_OUTPUT_PATH}/Debug/Resources/Logo.png COPYONLY)
configure_file(${CMAKE_CURRENT_SOURCE_DIR}/Resources/Logo.png ${EXECUTABLE_OUTPUT_PATH}/Release/Resources/Logo.png COPYONLY)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
add_executable(PictureBox ${GUI_OPTION} PictureBox.cpp)
