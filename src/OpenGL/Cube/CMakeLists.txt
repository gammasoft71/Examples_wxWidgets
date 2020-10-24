cmake_minimum_required(VERSION 3.0)
project(Cube)

find_package(OpenGL REQUIRED)
include_directories(${OPENGL_INCLUDE_DIR})
link_libraries(${OPENGL_LIBRARIES})

find_package(wxWidgets REQUIRED COMPONENTS base core aui html gl net qa richtext webview xml xrc)
include(${wxWidgets_USE_FILE})
link_libraries(${wxWidgets_LIBRARIES})

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
add_executable(${PROJECT_NAME} WIN32 MACOSX_BUNDLE Cube.cpp)
set_target_properties(${PROJECT_NAME} PROPERTIES FOLDER "OpenGL")

