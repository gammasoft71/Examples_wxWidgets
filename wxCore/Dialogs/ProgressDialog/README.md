# ProgressDialog

Shows how to create a ProgressDialog dialog with wxProgressDialog.

## Source

[ProgressDialog.cpp](ProgressDialog.cpp)

[CMakeLists.txt](CMakeLists.txt)

## Output

![output](../../../docs/Pictures/ProgressDialog.png)

## Build and run

To build this project, open "Terminal" and type following lines:

### Windows :

``` shell
mkdir build && cd build
cmake .. 
start ProgressDialog.sln
```

Select ProgressDialog project and type Ctrl+F5 to build and run it.

### macOS :

``` shell
mkdir build && cd build
cmake .. -G "Xcode"
open ./ProgressDialog.xcodeproj
```

Select ProgressDialog project and type Cmd+R to build and run it.

### Linux with Code::Blocks :

``` shell
mkdir build && cd build
cmake .. -G "CodeBlocks - Unix Makefiles"
xdg-open ./ProgressDialog.cbp > /dev/null 2>&1
```

Select ProgressDialog project and type F9 to build and run it.

### Linux :

``` shell
mkdir build && cd build
cmake .. 
cmake --build . --config Debug
./ProgressDialog
```
