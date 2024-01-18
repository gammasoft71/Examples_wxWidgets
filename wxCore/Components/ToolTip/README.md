# ToolTip

Shows how to create a ToolTip component with wxToolTip.

## Source

[ToolTip.cpp](ToolTip.cpp)

[CMakeLists.txt](CMakeLists.txt)

## Output

![output](../../../docs/Pictures/ToolTip.png)

## Build and run

To build this project, open "Terminal" and type following lines:

### Windows :

``` shell
mkdir build && cd build
cmake .. 
start ToolTip.sln
```

Select ToolTip project and type Ctrl+F5 to build and run it.

### macOS :

``` shell
mkdir build && cd build
cmake .. -G "Xcode"
open ./ToolTip.xcodeproj
```

Select ToolTip project and type Cmd+R to build and run it.

### Linux with Code::Blocks :

``` shell
mkdir build && cd build
cmake .. -G "CodeBlocks - Unix Makefiles"
xdg-open ./ToolTip.cbp > /dev/null 2>&1
```

Select ToolTip project and type F9 to build and run it.

### Linux :

``` shell
mkdir build && cd build
cmake .. 
cmake --build . --config Debug
./ToolTip
```
