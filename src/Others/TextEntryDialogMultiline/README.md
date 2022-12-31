# TextEntryDialogMultiline

Shows how to create a multiline TextEntryDialog dialog with wxTextEntryDialog.

## Source

[TextEntryDialogMultiline.cpp](TextEntryDialogMultiline.cpp)

[CMakeLists.txt](CMakeLists.txt)

## Output

![output](../../../docs/Pictures/TextEntryDialogMultiline.png)

## Build and run

To build this project, open "Terminal" and type following lines:

### Windows :

``` shell
mkdir build && cd build
cmake .. 
start TextEntryDialogMultiline.sln
```

Select TextEntryDialogMultiline project and type Ctrl+F5 to build and run it.

### macOS :

``` shell
mkdir build && cd build
cmake .. -G "Xcode"
open ./TextEntryDialogMultiline.xcodeproj
```

Select TextEntryDialogMultiline project and type Cmd+R to build and run it.

### Linux with Code::Blocks :

``` shell
mkdir build && cd build
cmake .. -G "CodeBlocks - Unix Makefiles"
xdg-open ./TextEntryDialogMultiline.cbp > /dev/null 2>&1
```

Select TextEntryDialogMultiline project and type F9 to build and run it.

### Linux :

``` shell
mkdir build && cd build
cmake .. 
cmake --build . --config Debug
./TextEntryDialogMultiline
```
