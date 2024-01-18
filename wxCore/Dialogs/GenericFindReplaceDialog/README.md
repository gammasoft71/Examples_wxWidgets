# GenericFindReplaceDialog

Shows how to create a GenericFindReplaceDialog dialog with wxGenericFindReplaceDialog.

## Source

[GenericFindReplaceDialog.cpp](GenericFindReplaceDialog.cpp)

[CMakeLists.txt](CMakeLists.txt)

## Output

![output](../../../docs/Pictures/GenericFindReplaceDialog.png)

## Build and run

To build this project, open "Terminal" and type following lines:

### Windows :

``` shell
mkdir build && cd build
cmake .. 
start GenericFindReplaceDialog.sln
```

Select GenericFindReplaceDialog project and type Ctrl+F5 to build and run it.

### macOS :

``` shell
mkdir build && cd build
cmake .. -G "Xcode"
open ./GenericFindReplaceDialog.xcodeproj
```

Select GenericFindReplaceDialog project and type Cmd+R to build and run it.

### Linux with Code::Blocks :

``` shell
mkdir build && cd build
cmake .. -G "CodeBlocks - Unix Makefiles"
xdg-open ./Line.cbp > /dev/null 2>&1
```

Select GenericFindReplaceDialog project and type F9 to build and run it.

### Linux :

``` shell
mkdir build && cd build
cmake .. 
cmake --build . --config Debug
./GenericFindReplaceDialog
```
