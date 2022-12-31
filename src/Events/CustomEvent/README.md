# CustomEvent

shows how to create a CustomEvent event with wxCommandEvent.

## Source

[CustomEvent.cpp](CustomEvent.cpp)

[CMakeLists.txt](CMakeLists.txt)

## Output

![output](../../../docs/Pictures/CustomEvent.png)

## Build and run

To build this project, open "Terminal" and type following lines:

### Windows :

``` shell
mkdir build && cd build
cmake .. 
start CustomEvent.sln
```

Select CustomEvent project and type Ctrl+F5 to build and run it.

### macOS :

``` shell
mkdir build && cd build
cmake .. -G "Xcode"
open ./CustomEvent.xcodeproj
```

Select CustomEvent project and type Cmd+R to build and run it.

### Linux with Code::Blocks :

``` shell
mkdir build && cd build
cmake .. -G "CodeBlocks - Unix Makefiles"
xdg-open ./CustomEvent.cbp > /dev/null 2>&1
```

Select CustomEvent project and type F9 to build and run it.

### Linux :

``` shell
mkdir build && cd build
cmake .. 
cmake --build . --config Debug
./CustomEvent
```
