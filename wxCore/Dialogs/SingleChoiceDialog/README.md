# SingleChoiceDialog

Shows how to create a SingleChoiceDialog dialog with wxSingleChoiceDialog.

## Source

[SingleChoiceDialog.cpp](SingleChoiceDialog.cpp)

[CMakeLists.txt](CMakeLists.txt)

## Output

![output](../../../docs/Pictures/SingleChoiceDialog.png)

## Build and run

To build this project, open "Terminal" and type following lines:

### Windows :

``` shell
mkdir build && cd build
cmake .. 
start SingleChoiceDialog.sln
```

Select SingleChoiceDialog project and type Ctrl+F5 to build and run it.

### macOS :

``` shell
mkdir build && cd build
cmake .. -G "Xcode"
open ./SingleChoiceDialog.xcodeproj
```

Select SingleChoiceDialog project and type Cmd+R to build and run it.

### Linux with Code::Blocks :

``` shell
mkdir build && cd build
cmake .. -G "CodeBlocks - Unix Makefiles"
xdg-open ./SingleChoiceDialog.cbp > /dev/null 2>&1
```

Select SingleChoiceDialog project and type F9 to build and run it.

### Linux :

``` shell
mkdir build && cd build
cmake .. 
cmake --build . --config Debug
./SingleChoiceDialog
```
