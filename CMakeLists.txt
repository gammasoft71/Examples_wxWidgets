cmake_minimum_required(VERSION 3.2)
project(wxWidgetsExamples)

if ("${CMAKE_BUILD_TYPE}" STREQUAL "")
  set(EXECUTABLE_OUTPUT_PATH ${PROJECT_BINARY_DIR})
else()
  set(EXECUTABLE_OUTPUT_PATH ${PROJECT_BINARY_DIR}/${CMAKE_BUILD_TYPE})
endif()

# Hello World
add_subdirectory("src/HelloWorld")

# Application and messages
add_subdirectory("src/Application")
add_subdirectory("src/ApplicationAndMain")
add_subdirectory("src/ApplicationIdle")
#add_subdirectory("src/ApplicationWithMessageLoop")

# Common Controls
add_subdirectory("src/Button")
add_subdirectory("src/CheckBox")
add_subdirectory("src/CheckListBox")
add_subdirectory("src/ComboBox")
add_subdirectory("src/Cursors")
add_subdirectory("src/Label")
add_subdirectory("src/PictureBox")
add_subdirectory("src/ProgressBar")
add_subdirectory("src/RadioButton")
add_subdirectory("src/TextBox")
add_subdirectory("src/TrackBar")

# Containers
add_subdirectory("src/Form")
add_subdirectory("src/GroupBox")
add_subdirectory("src/Panel")
add_subdirectory("src/TabControl")

# Menus and Toolbars
add_subdirectory("src/MainMenu")

# Components
add_subdirectory("src/Timer")

# Dialogs
add_subdirectory("src/ColorDialog")
add_subdirectory("src/FolderBrowserDialog")
add_subdirectory("src/FontDialog")
add_subdirectory("src/MessageBox")

# Events
add_subdirectory("src/FormClick")

# Other
#add_subdirectory("src/Drawing")
add_subdirectory("src/ColoredForms")
add_subdirectory("src/ColoredTabPages")
add_subdirectory("src/GroupBoxAndCheckBox")
add_subdirectory("src/GroupBoxAndRadioButton")
