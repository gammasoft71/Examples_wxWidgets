cmake_minimum_required(VERSION 3.5)

# Project
project(ApplicationAndException)

find_package(wxWidgets REQUIRED)
include(${wxWidgets_USE_FILE})

set(SOURCES README.md ApplicationAndException.cpp)

# Options
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Target
add_executable(${PROJECT_NAME} WIN32 MACOSX_BUNDLE ${SOURCES})
target_link_libraries(${PROJECT_NAME} ${wxWidgets_LIBRARIES})
set_target_properties(${PROJECT_NAME} PROPERTIES FOLDER "Applications")
