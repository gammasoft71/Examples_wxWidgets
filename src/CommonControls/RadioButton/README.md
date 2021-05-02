# RadioButton

Shows how to create a RadioButton widget with wxRadioButton.

## Source

[RadioButton.cpp](RadioButton.cpp)

[CMakeLists.txt](CMakeLists.txt)

## Build and run

To build this project, open "Terminal" and type following lines:

### Windows :

``` shell
mkdir build && cd build
cmake .. 
start RadioButton.sln
```

Select RadioButton project and type Ctrl+F5 to build and run it.

### macOS :

``` shell
mkdir build && cd build
cmake .. -G "Xcode"
open ./RadioButton.xcodeproj
```

Select RadioButton project and type Cmd+R to build and run it.

### Linux with Code::Blocks :

``` shell
mkdir build && cd build
cmake .. -G "CodeBlocks - Unix Makefiles"
xdg-open ./RadioButton.cbp > /dev/null 2>&1
```

Select RadioButton project and type F9 to build and run it.

### Linux :

``` shell
mkdir build && cd build
cmake .. 
cmake --build . --config Debug
./RadioButton
```
