# CheckBox

Shows how to create a CheckBox widget with wxCheckBox.

## Source

[CheckBox.cpp](CheckBox.cpp)

[CMakeLists.txt](CMakeLists.txt)

## Build and run

To build this project, open "Terminal" and type following lines:

### Windows :

``` shell
mkdir build && cd build
cmake .. 
start CheckBox.sln
```

Select CheckBox project and type Ctrl+F5 to build and run it.

### macOS :

``` shell
mkdir build && cd build
cmake .. -G "Xcode"
open ./CheckBox.xcodeproj
```

Select CheckBox project and type Cmd+R to build and run it.

### Linux with Code::Blocks :

``` shell
mkdir build && cd build
cmake .. -G "CodeBlocks - Unix Makefiles"
xdg-open ./CheckBox.cbp > /dev/null 2>&1
```

Select CheckBox project and type F9 to build and run it.

### Linux :

``` shell
mkdir build && cd build
cmake .. 
cmake --build . --config Debug
./CheckBox
```
