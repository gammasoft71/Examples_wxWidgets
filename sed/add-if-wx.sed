#!/bin/env sed

/find_package(wx.*)/ i if("${CMAKE_CURRENT_SOURCE_DIR}" STREQUAL "${CMAKE_SOURCE_DIR}")
/include(${wxWidgets_USE_FILE})/ a endif()