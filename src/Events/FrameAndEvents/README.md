# FrameAndEvents

Shows how to create a Frame and catch some events.

## Source

[FrameAndEvents.cpp](FrameAndEvents.cpp)

[CMakeLists.txt](CMakeLists.txt)

## Build and run

To build this project, open "Terminal" and type following lines:

### Windows :

``` shell
mkdir build && cd build
cmake .. 
start FrameAndEvents.sln
```

Select FrameAndEvents project and type Ctrl+F5 to build and run it.

### macOS :

``` shell
mkdir build && cd build
cmake .. -G "Xcode"
open ./FrameAndEvents.xcodeproj
```

Select FrameAndEvents project and type Cmd+R to build and run it.

### Linux with Code::Blocks :

``` shell
mkdir build && cd build
cmake .. -G "CodeBlocks - Unix Makefiles"
xdg-open ./FrameAndEvents.cbp > /dev/null 2>&1
```

Select FrameAndEvents project and type F9 to build and run it.

### Linux :

``` shell
mkdir build && cd build
cmake .. 
cmake --build . --config Debug
./FrameAndEvents
```
