# HelloWorldInWxWidgets

The classic first application wxWidgets "Hello World".

## Source

[HelloWorldInWxWidgets.cpp](HelloWorldInWxWidgets.cpp)

[CMakeLists.txt](CMakeLists.txt)

## Build and run

To build this project, open "Terminal" and type following lines:

### Windows :

``` shell
mkdir build && cd build
cmake .. 
start HelloWorldInWxWidgets.sln
```

Select HelloWorldInWxWidgets project and type Ctrl+F5 to build and run it.

### macOS :

``` shell
mkdir build && cd build
cmake .. -G "Xcode"
open ./HelloWorldInWxWidgets.xcodeproj
```

Select HelloWorldInWxWidgets project and type Cmd+R to build and run it.

### Linux with Code::Blocks :

``` shell
mkdir build && cd build
cmake .. -G "CodeBlocks - Unix Makefiles"
xdg-open ./HelloWorldInWxWidgets.cbp > /dev/null 2>&1
```

Select HelloWorldInWxWidgets project and type F9 to build and run it.

### Linux :

``` shell
mkdir build && cd build
cmake .. 
cmake --build . --config Debug
./HelloWorldInWxWidgets
```
