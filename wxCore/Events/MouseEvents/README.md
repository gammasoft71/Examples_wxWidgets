# MouseEvents

Shows how to create a Frame and catch mouse events.

## Source

[MouseEvents.cpp](MouseEvents.cpp)

[CMakeLists.txt](CMakeLists.txt)

## Output

![output](../../../docs/Pictures/MouseEvents.png)

## Build and run

To build this project, open "Terminal" and type following lines:

### Windows :

``` shell
mkdir build && cd build
cmake .. 
start MouseEvents.sln
```

Select MouseEvents project and type Ctrl+F5 to build and run it.

### macOS :

``` shell
mkdir build && cd build
cmake .. -G "Xcode"
open ./MouseEvents.xcodeproj
```

Select MouseEvents project and type Cmd+R to build and run it.

### Linux with Code::Blocks :

``` shell
mkdir build && cd build
cmake .. -G "CodeBlocks - Unix Makefiles"
xdg-open ./MouseEvents.cbp > /dev/null 2>&1
```

Select MouseEvents project and type F9 to build and run it.

### Linux :

``` shell
mkdir build && cd build
cmake .. 
cmake --build . --config Debug
./MouseEvents
```
