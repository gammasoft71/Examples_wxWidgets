cmake_minimum_required(VERSION 3.0)
project(PictureBox2)

find_package(wxWidgets REQUIRED)
include(${wxWidgets_USE_FILE})
link_libraries(${wxWidgets_LIBRARIES})

configure_file(${CMAKE_CURRENT_SOURCE_DIR}/Resources/Logo.png ${EXECUTABLE_OUTPUT_PATH}/Resources/Logo.png COPYONLY)
configure_file(${CMAKE_CURRENT_SOURCE_DIR}/Resources/Logo.png ${EXECUTABLE_OUTPUT_PATH}/Debug/Resources/Logo.png COPYONLY)
configure_file(${CMAKE_CURRENT_SOURCE_DIR}/Resources/Logo.png ${EXECUTABLE_OUTPUT_PATH}/Release/Resources/Logo.png COPYONLY)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
add_executable(PictureBox2 WIN32 MACOSX_BUNDLE PictureBox2.cpp)
set_target_properties(${PROJECT_NAME} PROPERTIES FOLDER "CommonControl")
