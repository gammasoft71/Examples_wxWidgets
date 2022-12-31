# CursorFromFile

Shows how to create Cursor from cur or ani file with wxCursor.

## Source

[CursorFromFile.cpp](CursorFromFile.cpp)

[CMakeLists.txt](CMakeLists.txt)

## Output

![output](../../../docs/Pictures/CursorFromFile.png)

## Build and run

To build this project, open "Terminal" and type following lines:

### Windows :

``` shell
mkdir build && cd build
cmake .. 
start CursorFromFile.sln
```

Select CursorFromFile project and type Ctrl+F5 to build and run it.

### macOS :

``` shell
mkdir build && cd build
cmake .. -G "Xcode"
open ./CursorFromFile.xcodeproj
```

Select CursorFromFile project and type Cmd+R to build and run it.

### Linux with Code::Blocks :

``` shell
mkdir build && cd build
cmake .. -G "CodeBlocks - Unix Makefiles"
xdg-open ./CursorFromFile.cbp > /dev/null 2>&1
```

Select CursorFromFile project and type F9 to build and run it.

### Linux :

``` shell
mkdir build && cd build
cmake .. 
cmake --build . --config Debug
./CursorFromFileCursorFromFile
```
