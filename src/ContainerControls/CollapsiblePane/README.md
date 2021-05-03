# CollapsiblePane

Shows how to create a CollapsiblePane widget with wxCollapsiblePane.

## Source

[CollapsiblePane.cpp](CollapsiblePane.cpp)

[CMakeLists.txt](CMakeLists.txt)

## Build and run

To build this project, open "Terminal" and type following lines:

### Windows :

``` shell
mkdir build && cd build
cmake .. 
start CollapsiblePane.sln
```

Select CollapsiblePane project and type Ctrl+F5 to build and run it.

### macOS :

``` shell
mkdir build && cd build
cmake .. -G "Xcode"
open ./CollapsiblePane.xcodeproj
```

Select CollapsiblePane project and type Cmd+R to build and run it.

### Linux with Code::Blocks :

``` shell
mkdir build && cd build
cmake .. -G "CodeBlocks - Unix Makefiles"
xdg-open ./CollapsiblePane.cbp > /dev/null 2>&1
```

Select CollapsiblePane project and type F9 to build and run it.

### Linux :

``` shell
mkdir build && cd build
cmake .. 
cmake --build . --config Debug
./CollapsiblePane
```
