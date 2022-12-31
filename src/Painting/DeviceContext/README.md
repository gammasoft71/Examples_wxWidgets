# DeviceContext

Shows how to create a form and catch paint event.

## Source

[DeviceContext.cpp](DeviceContext.cpp)

[CMakeLists.txt](CMakeLists.txt)

## Output

![output](../../../docs/Pictures/DeviceContext.png)

## Build and run

To build this project, open "Terminal" and type following lines:

### Windows :

``` shell
mkdir build && cd build
cmake .. 
start DeviceContext.sln
```

Select DeviceContext project and type Ctrl+F5 to build and run it.

### macOS :

``` shell
mkdir build && cd build
cmake .. -G "Xcode"
open ./DeviceContext.xcodeproj
```

Select DeviceContext project and type Cmd+R to build and run it.

### Linux with Code::Blocks :

``` shell
mkdir build && cd build
cmake .. -G "CodeBlocks - Unix Makefiles"
xdg-open ./DeviceContext.cbp > /dev/null 2>&1
```

Select DeviceContext project and type F9 to build and run it.

### Linux :

``` shell
mkdir build && cd build
cmake .. 
cmake --build . --config Debug
./DeviceContext
```
