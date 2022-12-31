# BorderStyle

Demonstrates how to set border style with wxStyle argument.

## Source

[BorderStyle.cpp](BorderStyle.cpp)

[CMakeLists.txt](CMakeLists.txt)

## Build and run

To build this project, open "Terminal" and type following lines:

### Windows :

``` shell
mkdir build && cd build
cmake .. 
start BorderStyle.sln
```

Select BorderStyle project and type Ctrl+F5 to build and run it.

### macOS :

``` shell
mkdir build && cd build
cmake .. -G "Xcode"
open ./BorderStyle.xcodeproj
```

Select BorderStyle project and type Cmd+R to build and run it.

### Linux with Code::Blocks :

``` shell
mkdir build && cd build
cmake .. -G "CodeBlocks - Unix Makefiles"
xdg-open ./BorderStyle.cbp > /dev/null 2>&1
```

Select BorderStyle project and type F9 to build and run it.

### Linux :

``` shell
mkdir build && cd build
cmake .. 
cmake --build . --config Debug
./StaticText
```
