cmake_minimum_required(VERSION 3.5)

# Project
project(Dice)

set(OpenGL_GL_PREFERENCE GLVND)
find_package(OpenGL REQUIRED)
include_directories(${OPENGL_INCLUDE_DIR})
find_package(wxWidgets REQUIRED COMPONENTS base core gl)
include(${wxWidgets_USE_FILE})

set(SOURCES README.md Dice.cpp)

# Options
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Target
add_executable(${PROJECT_NAME} WIN32 MACOSX_BUNDLE ${SOURCES})
target_link_libraries(${PROJECT_NAME} ${OPENGL_LIBRARIES} ${wxWidgets_LIBRARIES})
set_target_properties(${PROJECT_NAME} PROPERTIES FOLDER "OpenGL")
