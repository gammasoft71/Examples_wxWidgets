# FrameClick

Shows how to create a Frame and catch click event.

## Source

[FrameClick.cpp](FrameClick.cpp)

[CMakeLists.txt](CMakeLists.txt)

## Build and run

To build this project, open "Terminal" and type following lines:

### Windows :

``` shell
mkdir build && cd build
cmake .. 
start FrameClick.sln
```

Select FrameClick project and type Ctrl+F5 to build and run it.

### macOS :

``` shell
mkdir build && cd build
cmake .. -G "Xcode"
open ./FrameClick.xcodeproj
```

Select FrameClick project and type Cmd+R to build and run it.

### Linux with Code::Blocks :

``` shell
mkdir build && cd build
cmake .. -G "CodeBlocks - Unix Makefiles"
xdg-open ./FrameClick.cbp > /dev/null 2>&1
```

Select FrameClick project and type F9 to build and run it.

### Linux :

``` shell
mkdir build && cd build
cmake .. 
cmake --build . --config Debug
./FrameClick
```
