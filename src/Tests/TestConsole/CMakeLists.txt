cmake_minimum_required(VERSION 3.5)

# Project
project(TestConsole)

find_package(wxWidgets REQUIRED)
include(${wxWidgets_USE_FILE})

set(SOURCES Console.h TestConsole.cpp)

# Options
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Target
add_executable(${PROJECT_NAME} ${SOURCES})
target_link_libraries(${PROJECT_NAME} ${wxWidgets_LIBRARIES})
set_target_properties(${PROJECT_NAME} PROPERTIES FOLDER "Tests")
