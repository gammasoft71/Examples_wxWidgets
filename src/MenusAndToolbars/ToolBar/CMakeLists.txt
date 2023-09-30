cmake_minimum_required(VERSION 3.5)
project(ToolBar)


find_package(wxWidgets REQUIRED)
include(${wxWidgets_USE_FILE})

link_libraries(${wxWidgets_LIBRARIES})

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
add_executable(ToolBar WIN32 MACOSX_BUNDLE ToolBar.cpp)
set_target_properties(${PROJECT_NAME} PROPERTIES FOLDER "MenusAndToolbars")
