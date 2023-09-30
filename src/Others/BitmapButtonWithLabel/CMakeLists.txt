cmake_minimum_required(VERSION 3.5)
project(BitmapButtonWithLabel)


find_package(wxWidgets REQUIRED)
include(${wxWidgets_USE_FILE})

link_libraries(${wxWidgets_LIBRARIES})

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
add_executable(${PROJECT_NAME} WIN32 MACOSX_BUNDLE BitmapButtonWithLabel.cpp gammasoft_16x16.xpm gammasoft_32x32.xpm gammasoft_64x64.xpm)
set_target_properties(${PROJECT_NAME} PROPERTIES FOLDER "Others")
