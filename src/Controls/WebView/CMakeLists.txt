cmake_minimum_required(VERSION 3.5)
project(WebView)


find_package(wxWidgets COMPONENTS base core webview)
include(${wxWidgets_USE_FILE})

link_libraries(${wxWidgets_LIBRARIES})

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
add_executable(${PROJECT_NAME} WIN32 MACOSX_BUNDLE WebView.cpp)
set_target_properties(${PROJECT_NAME} PROPERTIES FOLDER "Controls")
