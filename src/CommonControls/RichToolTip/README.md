# RichToolTip

Shows how to create a RichToolTip widget with wxRichToolTip.

## Source

[RichToolTip.cpp](RichToolTip.cpp)

[CMakeLists.txt](CMakeLists.txt)

## Build and run

To build this project, open "Terminal" and type following lines:

### Windows :

``` shell
mkdir build && cd build
cmake .. 
start RichToolTip.sln
```

Select RichToolTip project and type Ctrl+F5 to build and run it.

### macOS :

``` shell
mkdir build && cd build
cmake .. -G "Xcode"
open ./RichToolTip.xcodeproj
```

Select RichToolTip project and type Cmd+R to build and run it.

### Linux with Code::Blocks :

``` shell
mkdir build && cd build
cmake .. -G "CodeBlocks - Unix Makefiles"
xdg-open ./RichToolTip.cbp > /dev/null 2>&1
```

Select RichToolTip project and type F9 to build and run it.

### Linux :

``` shell
mkdir build && cd build
cmake .. 
cmake --build . --config Debug
./RichToolTip
```
