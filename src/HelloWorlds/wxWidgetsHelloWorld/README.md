# wxWidgetsHelloWorld

The classic first application HelloWorld presented as skeleton by wxWidgets.

## Source

[wxWidgetsHelloWorld.cpp](wxWidgetsHelloWorld.cpp)

[CMakeLists.txt](CMakeLists.txt)

## Build and run

To build this project, open "Terminal" and type following lines:

### Windows :

``` shell
mkdir build && cd build
cmake .. 
start wxWidgetsHelloWorld.sln
```

Select wxWidgetsHelloWorld project and type Ctrl+F5 to build and run it.

### macOS :

``` shell
mkdir build && cd build
cmake .. -G "Xcode"
open ./wxWidgetsHelloWorld.xcodeproj
```

Select wxWidgetsHelloWorld project and type Cmd+R to build and run it.

### Linux with Code::Blocks :

``` shell
mkdir build && cd build
cmake .. -G "CodeBlocks - Unix Makefiles"
xdg-open ./wxWidgetsHelloWorld.cbp > /dev/null 2>&1
```

Select wxWidgetsHelloWorld project and type F9 to build and run it.

### Linux :

``` shell
mkdir build && cd build
cmake .. 
cmake --build . --config Debug
./wxWidgetsHelloWorld
```
