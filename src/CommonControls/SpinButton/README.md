# SpinButton

Shows how to create a SpinButton widget with wxSpinButton.

## Source

[SpinButton.cpp](SpinButton.cpp)

[CMakeLists.txt](CMakeLists.txt)

## Build and run

To build this project, open "Terminal" and type following lines:

### Windows :

``` shell
mkdir build && cd build
cmake .. 
start SpinButton.sln
```

Select SpinButton project and type Ctrl+F5 to build and run it.

### macOS :

``` shell
mkdir build && cd build
cmake .. -G "Xcode"
open ./SpinButton.xcodeproj
```

Select SpinButton project and type Cmd+R to build and run it.

### Linux with Code::Blocks :

``` shell
mkdir build && cd build
cmake .. -G "CodeBlocks - Unix Makefiles"
xdg-open ./SpinButton.cbp > /dev/null 2>&1
```

Select SpinButton project and type F9 to build and run it.

### Linux :

``` shell
mkdir build && cd build
cmake .. 
cmake --build . --config Debug
./SpinButton
```
