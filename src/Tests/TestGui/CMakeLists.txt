cmake_minimum_required(VERSION 3.5)
project(TestGui)


find_package(wxWidgets REQUIRED)
include(${wxWidgets_USE_FILE})

link_libraries(${wxWidgets_LIBRARIES})

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
if (MSVC)
  set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} /ENTRY:mainCRTStartup")
endif ()

add_executable(TestGui WIN32 MACOSX_BUNDLE TestGui.cpp Application.h)
set_target_properties(${PROJECT_NAME} PROPERTIES FOLDER "Tests")
