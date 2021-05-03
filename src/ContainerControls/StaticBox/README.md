# StaticBox

Shows how to create a StaticBox widget with wxStaticBox.

## Source

[StaticBox.cpp](StaticBox.cpp)

[CMakeLists.txt](CMakeLists.txt)

## Build and run

To build this project, open "Terminal" and type following lines:

### Windows :

``` shell
mkdir build && cd build
cmake .. 
start StaticBox.sln
```

Select StaticBox project and type Ctrl+F5 to build and run it.

### macOS :

``` shell
mkdir build && cd build
cmake .. -G "Xcode"
open ./StaticBox.xcodeproj
```

Select StaticBox project and type Cmd+R to build and run it.

### Linux with Code::Blocks :

``` shell
mkdir build && cd build
cmake .. -G "CodeBlocks - Unix Makefiles"
xdg-open ./StaticBox.cbp > /dev/null 2>&1
```

Select StaticBox project and type F9 to build and run it.

### Linux :

``` shell
mkdir build && cd build
cmake .. 
cmake --build . --config Debug
./StaticBox
```
