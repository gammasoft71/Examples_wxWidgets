# ToolBar

Shows how to create a ToolBar widget with wxToolBar.

## Source

[ToolBar.cpp](ToolBar.cpp)

[CMakeLists.txt](CMakeLists.txt)

## Build and run

To build this project, open "Terminal" and type following lines:

### Windows :

``` shell
mkdir build && cd build
cmake .. 
start ToolBar.sln
```

Select ToolBar project and type Ctrl+F5 to build and run it.

### macOS :

``` shell
mkdir build && cd build
cmake .. -G "Xcode"
open ./ToolBar.xcodeproj
```

Select ToolBar project and type Cmd+R to build and run it.

### Linux with Code::Blocks :

``` shell
mkdir build && cd build
cmake .. -G "CodeBlocks - Unix Makefiles"
xdg-open ./ToolBar.cbp > /dev/null 2>&1
```

Select ToolBar project and type F9 to build and run it.

### Linux :

``` shell
mkdir build && cd build
cmake .. 
cmake --build . --config Debug
./ToolBar
```
