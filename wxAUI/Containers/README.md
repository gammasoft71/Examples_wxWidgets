# Containers Examples

Shows how to use AUI containers examples.

* [AuiManager](AuiManager/README.md) shows how to create a AuiManager widget with wxAuiManager.

## Build and run

To build this project, open "Terminal" and type following lines:

### Windows
``` shell
mkdir build && cd build
cmake ..
start Containers.sln
```

Select any project and type Ctrl+F5 to build and run it.

### macOS :

``` shell
mkdir build && cd build
cmake .. -G "Xcode"
open ./Containers.xcodeproj
```

Select any project and type Cmd+R to build and run it.

### Linux with Code::Blocks :

``` shell
mkdir build
cd build
cmake .. -G "CodeBlocks - Unix Makefiles"
xdg-open ./Containers.cbp > /dev/null 2>&1
```

Select any project and type F10 to build and run it.

### Linux :

``` shell
mkdir build
cd build
cmake ..
cmake --build . --config Debug
./AnyProject
```
