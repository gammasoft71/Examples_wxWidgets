# RearrangeDialog

Shows how to create a RearrangeDialog dialog with wxRearrangeDialog.

## Source

[RearrangeDialog.cpp](RearrangeDialog.cpp)

[CMakeLists.txt](CMakeLists.txt)

## Build and run

To build this project, open "Terminal" and type following lines:

### Windows :

``` shell
mkdir build && cd build
cmake .. 
start RearrangeDialog.sln
```

Select RearrangeDialog project and type Ctrl+F5 to build and run it.

### macOS :

``` shell
mkdir build && cd build
cmake .. -G "Xcode"
open ./RearrangeDialog.xcodeproj
```

Select RearrangeDialog project and type Cmd+R to build and run it.

### Linux with Code::Blocks :

``` shell
mkdir build && cd build
cmake .. -G "CodeBlocks - Unix Makefiles"
xdg-open ./RearrangeDialog.cbp > /dev/null 2>&1
```

Select RearrangeDialog project and type F9 to build and run it.

### Linux :

``` shell
mkdir build && cd build
cmake .. 
cmake --build . --config Debug
./RearrangeDialog
```
