cmake_minimum_required(VERSION 3.20)
project(AuiNotebook)


find_package(wxWidgets REQUIRED COMPONENTS base core aui)
include(${wxWidgets_USE_FILE})

link_libraries(${wxWidgets_LIBRARIES})

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
add_executable(${PROJECT_NAME} WIN32 MACOSX_BUNDLE AuiNotebook.cpp)
set_target_properties(${PROJECT_NAME} PROPERTIES FOLDER "wxAUI/BookControls")
