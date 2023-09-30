cmake_minimum_required(VERSION 3.5)
project(StaticBitmap2)


find_package(wxWidgets REQUIRED)
include(${wxWidgets_USE_FILE})

link_libraries(${wxWidgets_LIBRARIES})

configure_file(${CMAKE_CURRENT_SOURCE_DIR}/Resources/Logo.png ${CMAKE_CURRENT_BINARY_DIR}/Resources/Logo.png COPYONLY)
configure_file(${CMAKE_CURRENT_SOURCE_DIR}/Resources/Logo.png ${CMAKE_CURRENT_BINARY_DIR}/Debug/Resources/Logo.png COPYONLY)
configure_file(${CMAKE_CURRENT_SOURCE_DIR}/Resources/Logo.png ${CMAKE_CURRENT_BINARY_DIR}/Release/Resources/Logo.png COPYONLY)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
add_executable(${PROJECT_NAME} WIN32 MACOSX_BUNDLE StaticBitmap2.cpp)
set_target_properties(${PROJECT_NAME} PROPERTIES FOLDER "Controls")
