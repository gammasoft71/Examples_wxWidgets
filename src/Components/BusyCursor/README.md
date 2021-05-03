# BusyCursor

Shows how to create a BusyCursor component with wxBusyCursor.

## Source

[BusyCursor.cpp](BusyCursor.cpp)

[CMakeLists.txt](CMakeLists.txt)

## Build and run

To build this project, open "Terminal" and type following lines:

### Windows :

``` shell
mkdir build && cd build
cmake .. 
start BusyCursor.sln
```

Select BusyCursor project and type Ctrl+F5 to build and run it.

### macOS :

``` shell
mkdir build && cd build
cmake .. -G "Xcode"
open ./BusyCursor.xcodeproj
```

Select BusyCursor project and type Cmd+R to build and run it.

### Linux with Code::Blocks :

``` shell
mkdir build && cd build
cmake .. -G "CodeBlocks - Unix Makefiles"
xdg-open ./BusyCursor.cbp > /dev/null 2>&1
```

Select BusyCursor project and type F9 to build and run it.

### Linux :

``` shell
mkdir build && cd build
cmake .. 
cmake --build . --config Debug
./BusyCursor
```
