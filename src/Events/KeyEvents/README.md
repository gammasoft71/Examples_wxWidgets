# KeyEvents

Shows how to create a Frame and catch key events.

## Source

[KeyEvents.cpp](KeyEvents.cpp)

[CMakeLists.txt](CMakeLists.txt)

## Output

![output](../../../docs/Pictures/KeyEvents.png)

## Build and run

To build this project, open "Terminal" and type following lines:

### Windows :

``` shell
mkdir build && cd build
cmake .. 
start KeyEvents.sln
```

Select KeyEvents project and type Ctrl+F5 to build and run it.

### macOS :

``` shell
mkdir build && cd build
cmake .. -G "Xcode"
open ./KeyEvents.xcodeproj
```

Select KeyEvents project and type Cmd+R to build and run it.

### Linux with Code::Blocks :

``` shell
mkdir build && cd build
cmake .. -G "CodeBlocks - Unix Makefiles"
xdg-open ./KeyEvents.cbp > /dev/null 2>&1
```

Select KeyEvents project and type F9 to build and run it.

### Linux :

``` shell
mkdir build && cd build
cmake .. 
cmake --build . --config Debug
./KeyEvents
```
