cmake_minimum_required(VERSION 3.0)
project(PictureBox2)

find_package(wxWidgets REQUIRED)
include(${wxWidgets_USE_FILE})
link_libraries(${wxWidgets_LIBRARIES})

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
add_executable(PictureBox2 WIN32 MACOSX_BUNDLE PictureBox2.cpp Logo.xpm)
