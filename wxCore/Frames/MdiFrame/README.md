# MdiFrame

shows how to create a MDI (Multiple Document Interface) frame.

## Source

[MdiFrame.cpp](MdiFrame.cpp)

[CMakeLists.txt](CMakeLists.txt)

## Output

![output](../../../docs/Pictures/MdiFrame.png)

## Build and run

To build this project, open "Terminal" and type following lines:

### Windows :

``` shell
mkdir build && cd build
cmake .. 
start MdiFrame.sln
```

Select MdiFrame project and type Ctrl+F5 to build and run it.

### macOS :

``` shell
mkdir build && cd build
cmake .. -G "Xcode"
open ./MdiFrame.xcodeproj
```

Select MdiFrame project and type Cmd+R to build and run it.

### Linux with Code::Blocks :

``` shell
mkdir build && cd build
cmake .. -G "CodeBlocks - Unix Makefiles"
xdg-open ./MdiFrame.cbp > /dev/null 2>&1
```

Select MdiFrame project and type F9 to build and run it.

### Linux :

``` shell
mkdir build && cd build
cmake .. 
cmake --build . --config Debug
./MdiFrame
```
