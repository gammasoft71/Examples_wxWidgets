# AutoScroll

Shows how to create an auto scroll widget with wxPanel.

## Source

[AutoScroll.cpp](AutoScroll.cpp)

[CMakeLists.txt](CMakeLists.txt)

## Build and run

To build this project, open "Terminal" and type following lines:

### Windows :

``` shell
mkdir build && cd build
cmake .. 
start AutoScroll.sln
```

Select AutoScroll project and type Ctrl+F5 to build and run it.

### macOS :

``` shell
mkdir build && cd build
cmake .. -G "Xcode"
open ./AutoScroll.xcodeproj
```

Select AutoScroll project and type Cmd+R to build and run it.

### Linux with Code::Blocks :

``` shell
mkdir build && cd build
cmake .. -G "CodeBlocks - Unix Makefiles"
xdg-open ./AutoScroll.cbp > /dev/null 2>&1
```

Select AutoScroll project and type F9 to build and run it.

### Linux :

``` shell
mkdir build && cd build
cmake .. 
cmake --build . --config Debug
./AutoScroll
```
