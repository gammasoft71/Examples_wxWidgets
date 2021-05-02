# ApplicationAndException

Shows how to create a simple wxWidgets application and how to manage exception.

## Source

[ApplicationAndException.cpp](ApplicationAndException.cpp)

[CMakeLists.txt](CMakeLists.txt)

## Build and run

To build this project, open "Terminal" and type following lines:

### Windows :

``` shell
mkdir build && cd build
cmake .. 
start ApplicationAndException.sln
```

Select ApplicationAndException project and type Ctrl+F5 to build and run it.

### macOS :

``` shell
mkdir build && cd build
cmake .. -G "Xcode"
open ./ApplicationAndException.xcodeproj
```

Select ApplicationAndException project and type Cmd+R to build and run it.

### Linux with Code::Blocks :

``` shell
mkdir build && cd build
cmake .. -G "CodeBlocks - Unix Makefiles"
xdg-open ./ApplicationAndException.cbp > /dev/null 2>&1
```

Select ApplicationAndException project and type F9 to build and run it.

### Linux :

``` shell
mkdir build && cd build
cmake .. 
cmake --build . --config Debug
./ApplicationAndException
```
