# SplitterWindow

Shows how to create a SplitterWindow widget with wxSplitterWindow.

## Source

[SplitterWindow.cpp](SplitterWindow.cpp)

[CMakeLists.txt](CMakeLists.txt)

## Build and run

To build this project, open "Terminal" and type following lines:

### Windows :

``` shell
mkdir build && cd build
cmake .. 
start SplitterWindow.sln
```

Select SplitterWindow project and type Ctrl+F5 to build and run it.

### macOS :

``` shell
mkdir build && cd build
cmake .. -G "Xcode"
open ./SplitterWindow.xcodeproj
```

Select SplitterWindow project and type Cmd+R to build and run it.

### Linux with Code::Blocks :

``` shell
mkdir build && cd build
cmake .. -G "CodeBlocks - Unix Makefiles"
xdg-open ./SplitterWindow.cbp > /dev/null 2>&1
```

Select SplitterWindow project and type F9 to build and run it.

### Linux :

``` shell
mkdir build && cd build
cmake .. 
cmake --build . --config Debug
./SplitterWindow
```
