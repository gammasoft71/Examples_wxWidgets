# StaticBoxAndRadioButton

Shows how to use wxStaticBox and wxRadioButton.

## Source

[StaticBoxAndRadioButton.cpp](StaticBoxAndRadioButton.cpp)

[CMakeLists.txt](CMakeLists.txt)

## Build and run

To build this project, open "Terminal" and type following lines:

### Windows :

``` shell
mkdir build && cd build
cmake .. 
start StaticBoxAndRadioButton.sln
```

Select StaticBoxAndRadioButton project and type Ctrl+F5 to build and run it.

### macOS :

``` shell
mkdir build && cd build
cmake .. -G "Xcode"
open ./StaticBoxAndRadioButton.xcodeproj
```

Select StaticBoxAndRadioButton project and type Cmd+R to build and run it.

### Linux with Code::Blocks :

``` shell
mkdir build && cd build
cmake .. -G "CodeBlocks - Unix Makefiles"
xdg-open ./StaticBoxAndRadioButton.cbp > /dev/null 2>&1
```

Select StaticBoxAndRadioButton project and type F9 to build and run it.

### Linux :

``` shell
mkdir build && cd build
cmake .. 
cmake --build . --config Debug
./StaticBoxAndRadioButton
```
