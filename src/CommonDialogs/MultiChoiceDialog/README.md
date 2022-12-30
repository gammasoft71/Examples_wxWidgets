# MultiChoiceDialog

Shows how to create a MultiChoiceDialog dialog with wxMultiChoiceDialog.

## Source

[MultiChoiceDialog.cpp](MultiChoiceDialog.cpp)

[CMakeLists.txt](CMakeLists.txt)

## Output

![output](../../../docs/Pictures/MultiChoiceDialog.png)

## Build and run

To build this project, open "Terminal" and type following lines:

### Windows :

``` shell
mkdir build && cd build
cmake .. 
start MultiChoiceDialog.sln
```

Select MultiChoiceDialog project and type Ctrl+F5 to build and run it.

### macOS :

``` shell
mkdir build && cd build
cmake .. -G "Xcode"
open ./MultiChoiceDialog.xcodeproj
```

Select MultiChoiceDialog project and type Cmd+R to build and run it.

### Linux with Code::Blocks :

``` shell
mkdir build && cd build
cmake .. -G "CodeBlocks - Unix Makefiles"
xdg-open ./MultiChoiceDialog.cbp > /dev/null 2>&1
```

Select MultiChoiceDialog project and type F9 to build and run it.

### Linux :

``` shell
mkdir build && cd build
cmake .. 
cmake --build . --config Debug
./MultiChoiceDialog
```
