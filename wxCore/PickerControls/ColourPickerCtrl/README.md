# ColourPickerCtrl

Shows how to create a ColourPickerCtrl widget with wxColourPickerCtrl.

## Source

[ColourPickerCtrl.cpp](ColourPickerCtrl.cpp)

[CMakeLists.txt](CMakeLists.txt)

## Output

![output](../../../docs/Pictures/ColourPickerCtrl.png)

## Build and run

To build this project, open "Terminal" and type following lines:

### Windows :

``` shell
mkdir build && cd build
cmake .. 
start ColourPickerCtrl.sln
```

Select ColourPickerCtrl project and type Ctrl+F5 to build and run it.

### macOS :

``` shell
mkdir build && cd build
cmake .. -G "Xcode"
open ./ColourPickerCtrl.xcodeproj
```

Select ColourPickerCtrl project and type Cmd+R to build and run it.

### Linux with Code::Blocks :

``` shell
mkdir build && cd build
cmake .. -G "CodeBlocks - Unix Makefiles"
xdg-open ./ColourPickerCtrl.cbp > /dev/null 2>&1
```

Select ColourPickerCtrl project and type F9 to build and run it.

### Linux :

``` shell
mkdir build && cd build
cmake .. 
cmake --build . --config Debug
./ColourPickerCtrl
```
