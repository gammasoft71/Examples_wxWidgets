cmake_minimum_required(VERSION 3.0)
project(ListView)

find_package(wxWidgets REQUIRED)
include(${wxWidgets_USE_FILE})
link_libraries(${wxWidgets_LIBRARIES})

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
add_executable(ListView WIN32 MACOSX_BUNDLE ListView.cpp Ai16.xpm Ai48.xpm Avi16.xpm Avi48.xpm Bmp16.xpm Bmp48.xpm)
