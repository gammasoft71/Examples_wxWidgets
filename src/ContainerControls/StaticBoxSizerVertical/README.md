# StaticBoxSizerVertical

Shows how to create a StaticBoxSizerVertical widget with wxStaticBoxSizer.

## Source

[StaticBoxSizerVertical.cpp](StaticBoxSizerVertical.cpp)

[CMakeLists.txt](CMakeLists.txt)

## Build and run

To build this project, open "Terminal" and type following lines:

### Windows :

``` shell
mkdir build && cd build
cmake .. 
start StaticBoxSizerVertical.sln
```

Select StaticBoxSizerVertical project and type Ctrl+F5 to build and run it.

### macOS :

``` shell
mkdir build && cd build
cmake .. -G "Xcode"
open ./StaticBoxSizerVertical.xcodeproj
```

Select StaticBoxSizerVertical project and type Cmd+R to build and run it.

### Linux with Code::Blocks :

``` shell
mkdir build && cd build
cmake .. -G "CodeBlocks - Unix Makefiles"
xdg-open ./StaticBoxSizerVertical.cbp > /dev/null 2>&1
```

Select StaticBoxSizerVertical project and type F9 to build and run it.

### Linux :

``` shell
mkdir build && cd build
cmake .. 
cmake --build . --config Debug
./StaticBoxSizerVertical
```
