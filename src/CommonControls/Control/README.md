# Control

Shows how to create a Control widget with wxControl.

## Source

[Control.cpp](Control.cpp)

[CMakeLists.txt](CMakeLists.txt)

## Build and run

To build this project, open "Terminal" and type following lines:

### Windows :

``` shell
mkdir build && cd build
cmake .. 
start Control.sln
```

Select Control project and type Ctrl+F5 to build and run it.

### macOS :

``` shell
mkdir build && cd build
cmake .. -G "Xcode"
open ./Control.xcodeproj
```

Select Control project and type Cmd+R to build and run it.

### Linux with Code::Blocks :

``` shell
mkdir build && cd build
cmake .. -G "CodeBlocks - Unix Makefiles"
xdg-open ./Control.cbp > /dev/null 2>&1
```

Select Control project and type F9 to build and run it.

### Linux :

``` shell
mkdir build && cd build
cmake .. 
cmake --build . --config Debug
./Control
```
