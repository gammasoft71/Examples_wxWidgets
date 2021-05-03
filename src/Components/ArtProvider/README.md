# ArtProvider

Shows how to create an ArtProvider component with wxArtProvider.

## Source

[ArtProvider.cpp](ArtProvider.cpp)

[CMakeLists.txt](CMakeLists.txt)

## Build and run

To build this project, open "Terminal" and type following lines:

### Windows :

``` shell
mkdir build && cd build
cmake .. 
start ArtProvider.sln
```

Select ArtProvider project and type Ctrl+F5 to build and run it.

### macOS :

``` shell
mkdir build && cd build
cmake .. -G "Xcode"
open ./ArtProvider.xcodeproj
```

Select ArtProvider project and type Cmd+R to build and run it.

### Linux with Code::Blocks :

``` shell
mkdir build && cd build
cmake .. -G "CodeBlocks - Unix Makefiles"
xdg-open ./ArtProvider.cbp > /dev/null 2>&1
```

Select ArtProvider project and type F9 to build and run it.

### Linux :

``` shell
mkdir build && cd build
cmake .. 
cmake --build . --config Debug
./ArtProvider
```
