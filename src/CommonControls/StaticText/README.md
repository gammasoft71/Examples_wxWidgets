# StaticText

Shows how to create a StaticText widget with StaticText.

## Source

[StaticText.cpp](StaticText.cpp)

[CMakeLists.txt](CMakeLists.txt)

## Build and run

To build this project, open "Terminal" and type following lines:

### Windows :

``` shell
mkdir build && cd build
cmake .. 
start StaticText.sln
```

Select StaticText project and type Ctrl+F5 to build and run it.

### macOS :

``` shell
mkdir build && cd build
cmake .. -G "Xcode"
open ./StaticText.xcodeproj
```

Select StaticText project and type Cmd+R to build and run it.

### Linux with Code::Blocks :

``` shell
mkdir build && cd build
cmake .. -G "CodeBlocks - Unix Makefiles"
xdg-open ./StaticText.cbp > /dev/null 2>&1
```

Select StaticText project and type F9 to build and run it.

### Linux :

``` shell
mkdir build && cd build
cmake .. 
cmake --build . --config Debug
./StaticText
```
