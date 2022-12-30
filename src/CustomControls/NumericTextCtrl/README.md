# NumericTextCtrl

Shows how to create a NumericTextCtrl widget with wxTextCtrl.

## Source

[NumericTextCtrl.cpp](NumericTextCtrl.cpp)

[CMakeLists.txt](CMakeLists.txt)

## Output

![output](../../../docs/Pictures/NumericTextBox.png)

## Build and run

To build this project, open "Terminal" and type following lines:

### Windows :

``` shell
mkdir build && cd build
cmake .. 
start NumericTextCtrl.sln
```

Select NumericTextCtrl project and type Ctrl+F5 to build and run it.

### macOS :

``` shell
mkdir build && cd build
cmake .. -G "Xcode"
open ./NumericTextCtrl.xcodeproj
```

Select NumericTextCtrl project and type Cmd+R to build and run it.

### Linux with Code::Blocks :

``` shell
mkdir build && cd build
cmake .. -G "CodeBlocks - Unix Makefiles"
xdg-open ./NumericTextCtrl.cbp > /dev/null 2>&1
```

Select NumericTextCtrl project and type F9 to build and run it.

### Linux :

``` shell
mkdir build && cd build
cmake .. 
cmake --build . --config Debug
./NumericTextCtrl
```
