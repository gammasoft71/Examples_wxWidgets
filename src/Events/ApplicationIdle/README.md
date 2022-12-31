# ApplicationIdle

Shows how to create an application and catch idle event.

## Source

[ApplicationIdle.cpp](ApplicationIdle.cpp)

[CMakeLists.txt](CMakeLists.txt)

## Output

![output](../../../docs/Pictures/ApplicationIdle.png)

## Build and run

To build this project, open "Terminal" and type following lines:

### Windows :

``` shell
mkdir build && cd build
cmake .. 
start ApplicationIdle.sln
```

Select ApplicationIdle project and type Ctrl+F5 to build and run it.

### macOS :

``` shell
mkdir build && cd build
cmake .. -G "Xcode"
open ./ApplicationIdle.xcodeproj
```

Select ApplicationIdle project and type Cmd+R to build and run it.

### Linux with Code::Blocks :

``` shell
mkdir build && cd build
cmake .. -G "CodeBlocks - Unix Makefiles"
xdg-open ./ApplicationIdle.cbp > /dev/null 2>&1
```

Select ApplicationIdle project and type F9 to build and run it.

### Linux :

``` shell
mkdir build && cd build
cmake .. 
cmake --build . --config Debug
./ApplicationIdle
```
