# ColourDialog

Shows how to create a ColourDialog dialog with wxColourDialog.

## Source

[ColourDialog.cpp](ColourDialog.cpp)

[CMakeLists.txt](CMakeLists.txt)

## Output

![output](../../../docs/Pictures/ColourDialog.png)

## Build and run

To build this project, open "Terminal" and type following lines:

### Windows :

``` shell
mkdir build && cd build
cmake .. 
start ColourDialog.sln
```

Select ColourDialog project and type Ctrl+F5 to build and run it.

### macOS :

``` shell
mkdir build && cd build
cmake .. -G "Xcode"
open ./ColourDialog.xcodeproj
```

Select ColourDialog project and type Cmd+R to build and run it.

### Linux with Code::Blocks :

``` shell
mkdir build && cd build
cmake .. -G "CodeBlocks - Unix Makefiles"
xdg-open ./ColourDialog.cbp > /dev/null 2>&1
```

Select ColourDialog project and type F9 to build and run it.

### Linux :

``` shell
mkdir build && cd build
cmake .. 
cmake --build . --config Debug
./ColourDialog
```
