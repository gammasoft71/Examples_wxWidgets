cmake_minimum_required(VERSION 3.0)
project(CheckBox)

find_package(wxWidgets REQUIRED)
include(${wxWidgets_USE_FILE})
link_libraries(${wxWidgets_LIBRARIES})

if(MSVC)
  set(GUI_OPTION WIN32)
elseif (APPLE)
  set(GUI_OPTION MACOSX_BUNDLE)
endif ()

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
add_executable(CheckBox ${GUI_OPTION} CheckBox.cpp)
