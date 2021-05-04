# StaticBoxAndCheckBox

Shows how to use wxStaticBox and wxCheckBox.

## Source

[StaticBoxAndCheckBox.cpp](StaticBoxAndCheckBox.cpp)

[CMakeLists.txt](CMakeLists.txt)

## Build and run

To build this project, open "Terminal" and type following lines:

### Windows :

``` shell
mkdir build && cd build
cmake .. 
start StaticBoxAndCheckBox.sln
```

Select StaticBoxAndCheckBox project and type Ctrl+F5 to build and run it.

### macOS :

``` shell
mkdir build && cd build
cmake .. -G "Xcode"
open ./StaticBoxAndCheckBox.xcodeproj
```

Select StaticBoxAndCheckBox project and type Cmd+R to build and run it.

### Linux with Code::Blocks :

``` shell
mkdir build && cd build
cmake .. -G "CodeBlocks - Unix Makefiles"
xdg-open ./StaticBoxAndCheckBox.cbp > /dev/null 2>&1
```

Select StaticBoxAndCheckBox project and type F9 to build and run it.

### Linux :

``` shell
mkdir build && cd build
cmake .. 
cmake --build . --config Debug
./StaticBoxAndCheckBox
```
