# ActivityIndicator

Shows how to create a ActivityIndicator widget with wxActivityIndicator.

## Source

[ActivityIndicator.cpp](ActivityIndicator.cpp)

[CMakeLists.txt](CMakeLists.txt)

## Output

![output](../../../docs/Pictures/ActivityIndicator.png)

## Build and run

To build this project, open "Terminal" and type following lines:

### Windows :

``` shell
mkdir build && cd build
cmake .. 
start ActivityIndicator.sln
```

Select ActivityIndicator project and type Ctrl+F5 to build and run it.

### macOS :

``` shell
mkdir build && cd build
cmake .. -G "Xcode"
open ./ActivityIndicator.xcodeproj
```

Select ActivityIndicator project and type Cmd+R to build and run it.

### Linux with Code::Blocks :

``` shell
mkdir build && cd build
cmake .. -G "CodeBlocks - Unix Makefiles"
xdg-open ./ActivityIndicator.cbp > /dev/null 2>&1
```

Select ActivityIndicator project and type F9 to build and run it.

### Linux :

``` shell
mkdir build && cd build
cmake .. 
cmake --build . --config Debug
./ActivityIndicator
```
