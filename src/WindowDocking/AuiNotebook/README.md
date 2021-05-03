# AuiNotebook

Shows how to create a AuiNotebook widget with wxAuiNotebook.

## Source

[AuiNotebook.cpp](AuiNotebook.cpp)

[CMakeLists.txt](CMakeLists.txt)

## Build and run

To build this project, open "Terminal" and type following lines:

### Windows :

``` shell
mkdir build && cd build
cmake .. 
start AuiNotebook.sln
```

Select AuiNotebook project and type Ctrl+F5 to build and run it.

### macOS :

``` shell
mkdir build && cd build
cmake .. -G "Xcode"
open ./AuiNotebook.xcodeproj
```

Select AuiNotebook project and type Cmd+R to build and run it.

### Linux with Code::Blocks :

``` shell
mkdir build && cd build
cmake .. -G "CodeBlocks - Unix Makefiles"
xdg-open ./AuiNotebook.cbp > /dev/null 2>&1
```

Select AuiNotebook project and type F9 to build and run it.

### Linux :

``` shell
mkdir build && cd build
cmake .. 
cmake --build . --config Debug
./AuiNotebook
```
