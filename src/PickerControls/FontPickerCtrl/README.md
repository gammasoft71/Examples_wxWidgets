# FontPickerCtrl

Shows how to create a FontPickerCtrl widget with wxFontPickerCtrl.

## Source

[FontPickerCtrl.cpp](FontPickerCtrl.cpp)

[CMakeLists.txt](CMakeLists.txt)

## Build and run

To build this project, open "Terminal" and type following lines:

### Windows :

``` shell
mkdir build && cd build
cmake .. 
start FontPickerCtrl.sln
```

Select FontPickerCtrl project and type Ctrl+F5 to build and run it.

### macOS :

``` shell
mkdir build && cd build
cmake .. -G "Xcode"
open ./FontPickerCtrl.xcodeproj
```

Select FontPickerCtrl project and type Cmd+R to build and run it.

### Linux with Code::Blocks :

``` shell
mkdir build && cd build
cmake .. -G "CodeBlocks - Unix Makefiles"
xdg-open ./FontPickerCtrl.cbp > /dev/null 2>&1
```

Select FontPickerCtrl project and type F9 to build and run it.

### Linux :

``` shell
mkdir build && cd build
cmake .. 
cmake --build . --config Debug
./FontPickerCtrl
```
