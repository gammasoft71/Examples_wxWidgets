cmake_minimum_required(VERSION 3.0)
project(TreeView)

find_package(wxWidgets REQUIRED)
include(${wxWidgets_USE_FILE})
link_libraries(${wxWidgets_LIBRARIES})

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
add_executable(TreeView WIN32 MACOSX_BUNDLE TreeView.cpp)
set_target_properties(${PROJECT_NAME} PROPERTIES FOLDER "CommonControls")
