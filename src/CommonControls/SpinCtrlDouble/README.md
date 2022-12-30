# SpinCtrlDouble

Shows how to create a SpinCtrlDouble widget with wxSpinCtrlDouble.

## Source

[SpinCtrlDouble.cpp](SpinCtrlDouble.cpp)

[CMakeLists.txt](CMakeLists.txt)

## Output

![output](../../../docs/Pictures/SpinCtrlDouble.png)

## Build and run

To build this project, open "Terminal" and type following lines:

### Windows :

``` shell
mkdir build && cd build
cmake .. 
start SpinCtrlDouble.sln
```

Select SpinCtrlDouble project and type Ctrl+F5 to build and run it.

### macOS :

``` shell
mkdir build && cd build
cmake .. -G "Xcode"
open ./SpinCtrlDouble.xcodeproj
```

Select SpinCtrlDouble project and type Cmd+R to build and run it.

### Linux with Code::Blocks :

``` shell
mkdir build && cd build
cmake .. -G "CodeBlocks - Unix Makefiles"
xdg-open ./SpinCtrlDouble.cbp > /dev/null 2>&1
```

Select SpinCtrlDouble project and type F9 to build and run it.

### Linux :

``` shell
mkdir build && cd build
cmake .. 
cmake --build . --config Debug
./SpinCtrlDouble
```
