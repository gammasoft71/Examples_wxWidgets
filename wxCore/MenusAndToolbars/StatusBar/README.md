# StatusBar

Shows how to create a StatusBar widget with wxStatusBar.

## Source

[StatusBar.cpp](StatusBar.cpp)

[CMakeLists.txt](CMakeLists.txt)

## Output

![output](../../../docs/Pictures/StatusBar.png)

## Build and run

To build this project, open "Terminal" and type following lines:

### Windows :

``` shell
mkdir build && cd build
cmake .. 
start StatusBar.sln
```

Select StatusBar project and type Ctrl+F5 to build and run it.

### macOS :

``` shell
mkdir build && cd build
cmake .. -G "Xcode"
open ./StatusBar.xcodeproj
```

Select StatusBar project and type Cmd+R to build and run it.

### Linux with Code::Blocks :

``` shell
mkdir build && cd build
cmake .. -G "CodeBlocks - Unix Makefiles"
xdg-open ./StatusBar.cbp > /dev/null 2>&1
```

Select StatusBar project and type F9 to build and run it.

### Linux :

``` shell
mkdir build && cd build
cmake .. 
cmake --build . --config Debug
./StatusBar
```
