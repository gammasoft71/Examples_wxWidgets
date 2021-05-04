# DirDialogShowWindowModal

Shows how to create a DirDialogWindowModal with wxDirDialog.

## Source

[DirDialogShowWindowModal.cpp](DirDialogShowWindowModal.cpp)

[CMakeLists.txt](CMakeLists.txt)

## Build and run

To build this project, open "Terminal" and type following lines:

### Windows :

``` shell
mkdir build && cd build
cmake .. 
start DirDialogShowWindowModal.sln
```

Select DirDialogShowWindowModal project and type Ctrl+F5 to build and run it.

### macOS :

``` shell
mkdir build && cd build
cmake .. -G "Xcode"
open ./DirDialogShowWindowModal.xcodeproj
```

Select DirDialogShowWindowModal project and type Cmd+R to build and run it.

### Linux with Code::Blocks :

``` shell
mkdir build && cd build
cmake .. -G "CodeBlocks - Unix Makefiles"
xdg-open ./DirDialogShowWindowModal.cbp > /dev/null 2>&1
```

Select DirDialogShowWindowModal project and type F9 to build and run it.

### Linux :

``` shell
mkdir build && cd build
cmake .. 
cmake --build . --config Debug
./DirDialogShowWindowModal
```
