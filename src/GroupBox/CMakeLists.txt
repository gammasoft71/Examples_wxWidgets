cmake_minimum_required(VERSION 3.5)

project(GroupBox VERSION 1.0.0)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

if(MSVC)
  set(GUI_OPTION WIN32)
elseif (APPLE)
  set(GUI_OPTION MACOSX_BUNDLE)
elseif(UNIX)
  set(GUI_OPTION )
endif ()

find_package(wxWidgets REQUIRED net gl core base)
include(${wxWidgets_USE_FILE})

add_executable(GroupBox ${GUI_OPTION} GroupBox.cpp)
target_link_libraries(GroupBox ${wxWidgets_LIBRARIES})
