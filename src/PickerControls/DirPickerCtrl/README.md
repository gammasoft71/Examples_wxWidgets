# DirPickerCtrl

Shows how to create a DirPickerCtrl widget with wxDirPickerCtrl.

## Source

[DirPickerCtrl.cpp](DirPickerCtrl.cpp)

[CMakeLists.txt](CMakeLists.txt)

## Build and run

To build this project, open "Terminal" and type following lines:

### Windows :

``` shell
mkdir build && cd build
cmake .. 
start DirPickerCtrl.sln
```

Select DirPickerCtrl project and type Ctrl+F5 to build and run it.

### macOS :

``` shell
mkdir build && cd build
cmake .. -G "Xcode"
open ./DirPickerCtrl.xcodeproj
```

Select DirPickerCtrl project and type Cmd+R to build and run it.

### Linux with Code::Blocks :

``` shell
mkdir build && cd build
cmake .. -G "CodeBlocks - Unix Makefiles"
xdg-open ./DirPickerCtrl.cbp > /dev/null 2>&1
```

Select DirPickerCtrl project and type F9 to build and run it.

### Linux :

``` shell
mkdir build && cd build
cmake .. 
cmake --build . --config Debug
./DirPickerCtrl
```
