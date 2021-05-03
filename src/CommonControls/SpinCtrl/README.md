# SpinCtrl

Shows how to create a SpinCtrl widget with wxSpinCtrl.

## Source

[SpinCtrl.cpp](SpinCtrl.cpp)

[CMakeLists.txt](CMakeLists.txt)

## Build and run

To build this project, open "Terminal" and type following lines:

### Windows :

``` shell
mkdir build && cd build
cmake .. 
start SpinCtrl.sln
```

Select SpinCtrl project and type Ctrl+F5 to build and run it.

### macOS :

``` shell
mkdir build && cd build
cmake .. -G "Xcode"
open ./SpinCtrl.xcodeproj
```

Select SpinCtrl project and type Cmd+R to build and run it.

### Linux with Code::Blocks :

``` shell
mkdir build && cd build
cmake .. -G "CodeBlocks - Unix Makefiles"
xdg-open ./SpinCtrl.cbp > /dev/null 2>&1
```

Select SpinCtrl project and type F9 to build and run it.

### Linux :

``` shell
mkdir build && cd build
cmake .. 
cmake --build . --config Debug
./SpinCtrl
```
