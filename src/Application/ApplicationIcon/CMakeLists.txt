cmake_minimum_required(VERSION 3.0)
project(ApplicationIcon)

find_package(wxWidgets REQUIRED)
include(${wxWidgets_USE_FILE})
link_libraries(${wxWidgets_LIBRARIES})

configure_file(${CMAKE_CURRENT_SOURCE_DIR}/Resources/Gammasoft.ico ${EXECUTABLE_OUTPUT_PATH}/Resources/Gammasoft.ico COPYONLY)
configure_file(${CMAKE_CURRENT_SOURCE_DIR}/Resources/Gammasoft.ico ${EXECUTABLE_OUTPUT_PATH}/Debug/Resources/Gammasoft.ico COPYONLY)
configure_file(${CMAKE_CURRENT_SOURCE_DIR}/Resources/Gammasoft.ico ${EXECUTABLE_OUTPUT_PATH}/Release/Resources/Gammasoft.ico COPYONLY)

configure_file(${CMAKE_CURRENT_SOURCE_DIR}/Resources/Gammasoft.icns ${EXECUTABLE_OUTPUT_PATH}/Resources/Gammasoft.icns COPYONLY)
configure_file(${CMAKE_CURRENT_SOURCE_DIR}/Resources/Gammasoft.icns ${EXECUTABLE_OUTPUT_PATH}/Debug/Resources/Gammasoft.icns COPYONLY)
configure_file(${CMAKE_CURRENT_SOURCE_DIR}/Resources/Gammasoft.icns ${EXECUTABLE_OUTPUT_PATH}/Release/Resources/Gammasoft.icns COPYONLY)

configure_file(${CMAKE_CURRENT_SOURCE_DIR}/Resources/Gammasoft.png ${EXECUTABLE_OUTPUT_PATH}/Resources/Gammasoft.png COPYONLY)
configure_file(${CMAKE_CURRENT_SOURCE_DIR}/Resources/Gammasoft.png ${EXECUTABLE_OUTPUT_PATH}/Debug/Resources/Gammasoft.png COPYONLY)
configure_file(${CMAKE_CURRENT_SOURCE_DIR}/Resources/Gammasoft.png ${EXECUTABLE_OUTPUT_PATH}/Release/Resources/Gammasoft.png COPYONLY)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
add_executable(ApplicationIcon WIN32 MACOSX_BUNDLE ApplicationIcon.cpp)
