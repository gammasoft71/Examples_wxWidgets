cmake_minimum_required(VERSION 3.0)
project(TreeCtrl)

if ("${CMAKE_CURRENT_SOURCE_DIR}" STREQUAL "${CMAKE_SOURCE_DIR}")
  find_package(wxWidgets REQUIRED)
  include(${wxWidgets_USE_FILE})
endif ()
link_libraries(${wxWidgets_LIBRARIES})

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
add_executable(${PROJECT_NAME} WIN32 MACOSX_BUNDLE TreeCtrl.cpp)
set_target_properties(${PROJECT_NAME} PROPERTIES FOLDER "CommonControls")
