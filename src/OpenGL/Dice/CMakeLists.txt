cmake_minimum_required(VERSION 3.0)
project(Dice)

find_package(OpenGL REQUIRED)
include_directories(${OPENGL_INCLUDE_DIR})
link_libraries(${OPENGL_LIBRARIES})

if("${CMAKE_CURRENT_SOURCE_DIR}" STREQUAL "${CMAKE_SOURCE_DIR}")
find_package(wxWidgets REQUIRED COMPONENTS base core gl)
include(${wxWidgets_USE_FILE})
endif()
link_libraries(${wxWidgets_LIBRARIES})

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
add_executable(${PROJECT_NAME} WIN32 MACOSX_BUNDLE Dice.cpp)
set_target_properties(${PROJECT_NAME} PROPERTIES FOLDER "OpenGL")

if (APPLE)
  add_custom_target(NSPrincipalClass ALL plutil -replace NSPrincipalClass -string NSApplication ${CMAKE_BINARY_DIR}/${PROJECT_NAME}.app/Contents/Info.plist DEPENDS ${PROJECT_NAME})
  add_custom_target(NSHighResolutionCapable ALL plutil -replace NSHighResolutionCapable -bool true ${CMAKE_BINARY_DIR}/${PROJECT_NAME}.app/Contents/Info.plist DEPENDS ${PROJECT_NAME})
endif()
