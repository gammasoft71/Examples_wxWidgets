# FrameShowHide

Demonstrates the use of wxFrame Show, Hide and Close methods.

## Source

[FrameShowHide.cpp](FrameShowHide.cpp)

[CMakeLists.txt](CMakeLists.txt)

## Output

![output](../../../docs/Pictures/FrameShowHide.png)

## Build and run

To build this project, open "Terminal" and type following lines:

### Windows :

``` shell
mkdir build && cd build
cmake .. 
start FrameShowHide.sln
```

Select FrameShowHide project and type Ctrl+F5 to build and run it.

### macOS :

``` shell
mkdir build && cd build
cmake .. -G "Xcode"
open ./FrameShowHide.xcodeproj
```

Select FrameShowHide project and type Cmd+R to build and run it.

### Linux with Code::Blocks :

``` shell
mkdir build && cd build
cmake .. -G "CodeBlocks - Unix Makefiles"
xdg-open ./FrameShowHide.cbp > /dev/null 2>&1
```

Select FrameShowHide project and type F9 to build and run it.

### Linux :

``` shell
mkdir build && cd build
cmake .. 
cmake --build . --config Debug
./FrameShowHide
```
