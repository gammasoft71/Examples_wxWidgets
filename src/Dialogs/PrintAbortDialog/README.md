# PrintAbortDialog

Shows how to create a PrintAbortDialog dialog with wxPrintAbortDialog.

## Source

[PrintAbortDialog.cpp](PrintAbortDialog.cpp)

[CMakeLists.txt](CMakeLists.txt)

## Build and run

To build this project, open "Terminal" and type following lines:

### Windows :

``` shell
mkdir build && cd build
cmake .. 
start PrintAbortDialog.sln
```

Select PrintAbortDialog project and type Ctrl+F5 to build and run it.

### macOS :

``` shell
mkdir build && cd build
cmake .. -G "Xcode"
open ./PrintAbortDialog.xcodeproj
```

Select PrintAbortDialog project and type Cmd+R to build and run it.

### Linux with Code::Blocks :

``` shell
mkdir build && cd build
cmake .. -G "CodeBlocks - Unix Makefiles"
xdg-open ./PrintAbortDialog.cbp > /dev/null 2>&1
```

Select PrintAbortDialog project and type F9 to build and run it.

### Linux :

``` shell
mkdir build && cd build
cmake .. 
cmake --build . --config Debug
./PrintAbortDialog
```
