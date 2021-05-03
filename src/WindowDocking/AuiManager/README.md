# AuiManager

Shows how to create an AuiManager widget with wxAuiManager.

## Source

[AuiManager.cpp](AuiManager.cpp)

[CMakeLists.txt](CMakeLists.txt)

## Build and run

To build this project, open "Terminal" and type following lines:

### Windows :

``` shell
mkdir build && cd build
cmake .. 
start AuiManager.sln
```

Select AuiManager project and type Ctrl+F5 to build and run it.

### macOS :

``` shell
mkdir build && cd build
cmake .. -G "Xcode"
open ./AuiManager.xcodeproj
```

Select AuiManager project and type Cmd+R to build and run it.

### Linux with Code::Blocks :

``` shell
mkdir build && cd build
cmake .. -G "CodeBlocks - Unix Makefiles"
xdg-open ./AuiManager.cbp > /dev/null 2>&1
```

Select AuiManager project and type F9 to build and run it.

### Linux :

``` shell
mkdir build && cd build
cmake .. 
cmake --build . --config Debug
./AuiManager
```
