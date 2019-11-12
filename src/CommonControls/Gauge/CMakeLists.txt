cmake_minimum_required(VERSION 3.0)
project(Gauge)

find_package(wxWidgets REQUIRED)
include(${wxWidgets_USE_FILE})
link_libraries(${wxWidgets_LIBRARIES})

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
add_executable(${PROJECT_NAME} WIN32 MACOSX_BUNDLE Gauge.cpp)
set_target_properties(${PROJECT_NAME} PROPERTIES FOLDER "CommonControls")
