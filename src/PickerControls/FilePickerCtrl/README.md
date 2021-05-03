# FilePickerCtrl

Shows how to create a FilePickerCtrl widget with wxFilePickerCtrl.

## Source

[FilePickerCtrl.cpp](FilePickerCtrl.cpp)

[CMakeLists.txt](CMakeLists.txt)

## Build and run

To build this project, open "Terminal" and type following lines:

### Windows :

``` shell
mkdir build && cd build
cmake .. 
start FilePickerCtrl.sln
```

Select FilePickerCtrl project and type Ctrl+F5 to build and run it.

### macOS :

``` shell
mkdir build && cd build
cmake .. -G "Xcode"
open ./FilePickerCtrl.xcodeproj
```

Select FilePickerCtrl project and type Cmd+R to build and run it.

### Linux with Code::Blocks :

``` shell
mkdir build && cd build
cmake .. -G "CodeBlocks - Unix Makefiles"
xdg-open ./FilePickerCtrl.cbp > /dev/null 2>&1
```

Select FilePickerCtrl project and type F9 to build and run it.

### Linux :

``` shell
mkdir build && cd build
cmake .. 
cmake --build . --config Debug
./FilePickerCtrl
```
