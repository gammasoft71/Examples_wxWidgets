# SaveFileDialogShowWindowModal

Shows how to create a SaveFileDialogShowWindowModal dialog with wxFileDialog using ShowWindowModal method.

## Source

[SaveFileDialogShowWindowModal.cpp](SaveFileDialogShowWindowModal.cpp)

[CMakeLists.txt](CMakeLists.txt)

## Build and run

To build this project, open "Terminal" and type following lines:

### Windows :

``` shell
mkdir build && cd build
cmake .. 
start SaveFileDialogShowWindowModal.sln
```

Select SaveFileDialogShowWindowModal project and type Ctrl+F5 to build and run it.

### macOS :

``` shell
mkdir build && cd build
cmake .. -G "Xcode"
open ./SaveFileDialogShowWindowModal.xcodeproj
```

Select SaveFileDialogShowWindowModal project and type Cmd+R to build and run it.

### Linux with Code::Blocks :

``` shell
mkdir build && cd build
cmake .. -G "CodeBlocks - Unix Makefiles"
xdg-open ./SaveFileDialogShowWindowModal.cbp > /dev/null 2>&1
```

Select SaveFileDialogShowWindowModal project and type F9 to build and run it.

### Linux :

``` shell
mkdir build && cd build
cmake .. 
cmake --build . --config Debug
./Line
```
