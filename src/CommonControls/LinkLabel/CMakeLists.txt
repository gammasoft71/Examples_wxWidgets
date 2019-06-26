cmake_minimum_required(VERSION 3.0)
project(LinkLabel)

find_package(wxWidgets REQUIRED)
include(${wxWidgets_USE_FILE})
link_libraries(${wxWidgets_LIBRARIES})

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
add_executable(LinkLabel WIN32 MACOSX_BUNDLE LinkLabel.cpp)
