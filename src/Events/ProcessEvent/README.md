# ProcessEvent

Shows how to override ProcessEvent method.

## Source

[ProcessEvent.cpp](ProcessEvent.cpp)

[CMakeLists.txt](CMakeLists.txt)

## Build and run

To build this project, open "Terminal" and type following lines:

### Windows :

``` shell
mkdir build && cd build
cmake .. 
start ProcessEvent.sln
```

Select ProcessEvent project and type Ctrl+F5 to build and run it.

### macOS :

``` shell
mkdir build && cd build
cmake .. -G "Xcode"
open ./ProcessEvent.xcodeproj
```

Select ProcessEvent project and type Cmd+R to build and run it.

### Linux with Code::Blocks :

``` shell
mkdir build && cd build
cmake .. -G "CodeBlocks - Unix Makefiles"
xdg-open ./ProcessEvent.cbp > /dev/null 2>&1
```

Select ProcessEvent project and type F9 to build and run it.

### Linux :

``` shell
mkdir build && cd build
cmake .. 
cmake --build . --config Debug
./ProcessEvent
```
