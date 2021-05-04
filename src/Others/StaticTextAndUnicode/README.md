# StaticTextAndUnicode

Shows how to create a Line widget with wxPanel.

## Source

[StaticTextAndUnicode.cpp](StaticTextAndUnicode.cpp)

[CMakeLists.txt](CMakeLists.txt)

## Build and run

To build this project, open "Terminal" and type following lines:

### Windows :

``` shell
mkdir build && cd build
cmake .. 
start StaticTextAndUnicode.sln
```

Select StaticTextAndUnicode project and type Ctrl+F5 to build and run it.

### macOS :

``` shell
mkdir build && cd build
cmake .. -G "Xcode"
open ./StaticTextAndUnicode.xcodeproj
```

Select StaticTextAndUnicode project and type Cmd+R to build and run it.

### Linux with Code::Blocks :

``` shell
mkdir build && cd build
cmake .. -G "CodeBlocks - Unix Makefiles"
xdg-open ./StaticTextAndUnicode.cbp > /dev/null 2>&1
```

Select StaticTextAndUnicode project and type F9 to build and run it.

### Linux :

``` shell
mkdir build && cd build
cmake .. 
cmake --build . --config Debug
./StaticTextAndUnicode
```
