cmake_minimum_required(VERSION 3.20)
project(Frame)


find_package(wxWidgets REQUIRED COMPONENTS base core)
include(${wxWidgets_USE_FILE})

link_libraries(${wxWidgets_LIBRARIES})

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
add_executable(${PROJECT_NAME} WIN32 MACOSX_BUNDLE Frame.cpp)
set_target_properties(${PROJECT_NAME} PROPERTIES FOLDER "wxCore/Frames")
