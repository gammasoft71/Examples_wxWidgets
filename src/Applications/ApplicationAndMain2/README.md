# ApplicationAndMain2

Shows how to create a wxWidgets application and main method with wxApp.

## Source

[ApplicationAndMain2.cpp](ApplicationAndMain2.cpp)

[Application.h](Application.h)

[CMakeLists.txt](CMakeLists.txt)

## Output

![output](../../../docs/Pictures/ApplicationAndMain2.png)

## Build and run

To build this project, open "Terminal" and type following lines:

### Windows :

``` shell
mkdir build && cd build
cmake .. 
start ApplicationAndMain2.sln
```

Select ApplicationAndMain2 project and type Ctrl+F5 to build and run it.

### macOS :

``` shell
mkdir build && cd build
cmake .. -G "Xcode"
open ./ApplicationAndMain2.xcodeproj
```

Select ApplicationAndMain2 project and type Cmd+R to build and run it.

### Linux with Code::Blocks :

``` shell
mkdir build && cd build
cmake .. -G "CodeBlocks - Unix Makefiles"
xdg-open ./ApplicationAndMain2.cbp > /dev/null 2>&1
```

Select ApplicationAndMain2 project and type F9 to build and run it.

### Linux :

``` shell
mkdir build && cd build
cmake .. 
cmake --build . --config Debug
./ApplicationAndMain2
```
