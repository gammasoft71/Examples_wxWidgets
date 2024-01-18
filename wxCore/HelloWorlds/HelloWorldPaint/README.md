# HelloWorldPaint

The classic first application "Hello World" with GDI+drawing objects.

## Source

[HelloWorldPaint.cpp](HelloWorldPaint.cpp)

[CMakeLists.txt](CMakeLists.txt)

## Output

![output](../../../docs/Pictures/HelloWorldPaint.png)

## Build and run

To build this project, open "Terminal" and type following lines:

### Windows :

``` shell
mkdir build && cd build
cmake .. 
start HelloWorldPaint.sln
```

Select HelloWorldPaint project and type Ctrl+F5 to build and run it.

### macOS :

``` shell
mkdir build && cd build
cmake .. -G "Xcode"
open ./HelloWorldPaint.xcodeproj
```

Select HelloWorldPaint project and type Cmd+R to build and run it.

### Linux with Code::Blocks :

``` shell
mkdir build && cd build
cmake .. -G "CodeBlocks - Unix Makefiles"
xdg-open ./HelloWorldPaint.cbp > /dev/null 2>&1
```

Select HelloWorldPaint project and type F9 to build and run it.

### Linux :

``` shell
mkdir build && cd build
cmake .. 
cmake --build . --config Debug
./HelloWorldPaint
```
