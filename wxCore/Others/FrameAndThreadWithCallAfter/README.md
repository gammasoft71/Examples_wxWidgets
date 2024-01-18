# FrameAndThreadWithCallAfter

Shows how to dialog with a frame widget from a thread with CallAfter method.

## Source

[FrameAndThreadWithCallAfter.cpp](FrameAndThreadWithCallAfter.cpp)

[CMakeLists.txt](CMakeLists.txt)

## Output

![output](../../../docs/Pictures/FrameAndThreadWithCallAfter.png)

## Build and run

To build this project, open "Terminal" and type following lines:

### Windows :

``` shell
mkdir build && cd build
cmake .. 
start FrameAndThreadWithCallAfter.sln
```

Select FrameAndThreadWithCallAfter project and type Ctrl+F5 to build and run it.

### macOS :

``` shell
mkdir build && cd build
cmake .. -G "Xcode"
open ./FrameAndThreadWithCallAfter.xcodeproj
```

Select FrameAndThreadWithCallAfter project and type Cmd+R to build and run it.

### Linux with Code::Blocks :

``` shell
mkdir build && cd build
cmake .. -G "CodeBlocks - Unix Makefiles"
xdg-open ./FrameAndThreadWithCallAfter.cbp > /dev/null 2>&1
```

Select FrameAndThreadWithCallAfter project and type F9 to build and run it.

### Linux :

``` shell
mkdir build && cd build
cmake .. 
cmake --build . --config Debug
./FrameAndThreadWithCallAfter
```
