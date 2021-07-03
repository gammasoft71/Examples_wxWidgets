# DisplayInformations

Shows how to get screen information of wxDisplay.

## Source

[DisplayInformations.cpp](DisplayInformations.cpp)

[CMakeLists.txt](CMakeLists.txt)

## Build and run

To build this project, open "Terminal" and type following lines:

### Windows :

``` shell
mkdir build && cd build
cmake .. 
start DisplayInformations.sln
```

Select DisplayInformations project and type Ctrl+F5 to build and run it.

### macOS :

``` shell
mkdir build && cd build
cmake .. -G "Xcode"
open ./DisplayInformations.xcodeproj
```

Select DisplayInformations project and type Cmd+R to build and run it.

### Linux with Code::Blocks :

``` shell
mkdir build && cd build
cmake .. -G "CodeBlocks - Unix Makefiles"
xdg-open ./DisplayInformations.cbp > /dev/null 2>&1
```

Select DisplayInformations project and type F9 to build and run it.

### Linux :

``` shell
mkdir build && cd build
cmake .. 
cmake --build . --config Debug
./DisplayInformations
```
