# ToggleButton

Shows how to create a ToggleButton widget with wxToggleButton.

## Source

[ToggleButton.cpp](ToggleButton.cpp)

[CMakeLists.txt](CMakeLists.txt)

## Output

![output](../../../docs/Pictures/ToggleButton.png)

## Build and run

To build this project, open "Terminal" and type following lines:

### Windows :

``` shell
mkdir build && cd build
cmake .. 
start ToggleButton.sln
```

Select ToggleButton project and type Ctrl+F5 to build and run it.

### macOS :

``` shell
mkdir build && cd build
cmake .. -G "Xcode"
open ./ToggleButton.xcodeproj
```

Select ToggleButton project and type Cmd+R to build and run it.

### Linux with Code::Blocks :

``` shell
mkdir build && cd build
cmake .. -G "CodeBlocks - Unix Makefiles"
xdg-open ./ToggleButton.cbp > /dev/null 2>&1
```

Select ToggleButton project and type F9 to build and run it.

### Linux :

``` shell
mkdir build && cd build
cmake .. 
cmake --build . --config Debug
./ToggleButton
```
