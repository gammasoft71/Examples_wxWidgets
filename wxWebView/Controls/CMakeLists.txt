cmake_minimum_required(VERSION 3.20)
project(CommonControls)

if (APPLE OR MSVC)
  add_subdirectory(WebView)
endif()
