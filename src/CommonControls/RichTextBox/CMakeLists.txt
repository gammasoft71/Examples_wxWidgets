cmake_minimum_required(VERSION 3.0)
project(RichTextBox)

#set(wxWidgets_CONFIG_OPTIONS --libs std,richtext)
#find_package(wxWidgets REQUIRED)
find_package(wxWidgets COMPONENTS gl core base richtext)
include(${wxWidgets_USE_FILE})
link_libraries(${wxWidgets_LIBRARIES})

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
add_executable(RichTextBox WIN32 MACOSX_BUNDLE RichTextBox.cpp)
