# ApplicationAndMain

Shows how to create a wxWidgets application and main method with wxApp.

## Source

[ApplicationAndMain.cpp](ApplicationAndMain.cpp)

[CMakeLists.txt](CMakeLists.txt)

## Output

![output](../../../docs/Pictures/ApplicationAndMain.png)

## Build and run

To build this project, open "Terminal" and type following lines:

### Windows :

``` shell
mkdir build && cd build
cmake .. 
start ApplicationAndMain.sln
```

Select ApplicationAndMain project and type Ctrl+F5 to build and run it.

### macOS :

``` shell
mkdir build && cd build
cmake .. -G "Xcode"
open ./ApplicationAndMain.xcodeproj
```

Select ApplicationAndMain project and type Cmd+R to build and run it.

### Linux with Code::Blocks :

``` shell
mkdir build && cd build
cmake .. -G "CodeBlocks - Unix Makefiles"
xdg-open ./ApplicationAndMain.cbp > /dev/null 2>&1
```

Select ApplicationAndMain project and type F9 to build and run it.

### Linux :

``` shell
mkdir build && cd build
cmake .. 
cmake --build . --config Debug
./ApplicationAndMain
```
