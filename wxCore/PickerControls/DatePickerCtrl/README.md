# DatePickerCtrl

Shows how to create a DatePickerCtrl widget with wxDatePickerCtrl.

## Source

[DatePickerCtrl.cpp](DatePickerCtrl.cpp)

[CMakeLists.txt](CMakeLists.txt)

## Output

![output](../../../docs/Pictures/DatePickerCtrl.png)

## Build and run

To build this project, open "Terminal" and type following lines:

### Windows :

``` shell
mkdir build && cd build
cmake .. 
start DatePickerCtrl.sln
```

Select DatePickerCtrl project and type Ctrl+F5 to build and run it.

### macOS :

``` shell
mkdir build && cd build
cmake .. -G "Xcode"
open ./DatePickerCtrl.xcodeproj
```

Select DatePickerCtrl project and type Cmd+R to build and run it.

### Linux with Code::Blocks :

``` shell
mkdir build && cd build
cmake .. -G "CodeBlocks - Unix Makefiles"
xdg-open ./DatePickerCtrl.cbp > /dev/null 2>&1
```

Select DatePickerCtrl project and type F9 to build and run it.

### Linux :

``` shell
mkdir build && cd build
cmake .. 
cmake --build . --config Debug
./DatePickerCtrl
```
