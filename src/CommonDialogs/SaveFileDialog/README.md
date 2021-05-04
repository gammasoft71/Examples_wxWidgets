# SaveFileDialog

Shows how to create a SaveFileDialog dialog with wxFileDialog.

## Source

[SaveFileDialog.cpp](SaveFileDialog.cpp)

[CMakeLists.txt](CMakeLists.txt)

## Build and run

To build this project, open "Terminal" and type following lines:

### Windows :

``` shell
mkdir build && cd build
cmake .. 
start SaveFileDialog.sln
```

Select SaveFileDialog project and type Ctrl+F5 to build and run it.

### macOS :

``` shell
mkdir build && cd build
cmake .. -G "Xcode"
open ./SaveFileDialog.xcodeproj
```

Select SaveFileDialog project and type Cmd+R to build and run it.

### Linux with Code::Blocks :

``` shell
mkdir build && cd build
cmake .. -G "CodeBlocks - Unix Makefiles"
xdg-open ./SaveFileDialog.cbp > /dev/null 2>&1
```

Select SaveFileDialog project and type F9 to build and run it.

### Linux :

``` shell
mkdir build && cd build
cmake .. 
cmake --build . --config Debug
./SaveFileDialog
```
