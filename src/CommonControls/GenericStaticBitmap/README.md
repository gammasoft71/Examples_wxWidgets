# GenericStaticBitmap

Shows how to create a GenericStaticBitmap widget with wxGenericStaticBitmap.

## Source

[GenericStaticBitmap.cpp](GenericStaticBitmap.cpp)

[CMakeLists.txt](CMakeLists.txt)

## Build and run

To build this project, open "Terminal" and type following lines:

### Windows :

``` shell
mkdir build && cd build
cmake .. 
start ActivityIndicator.sln
```

Select GenericStaticBitmap project and type Ctrl+F5 to build and run it.

### macOS :

``` shell
mkdir build && cd build
cmake .. -G "Xcode"
open ./GenericStaticBitmap.xcodeproj
```

Select GenericStaticBitmap project and type Cmd+R to build and run it.

### Linux with Code::Blocks :

``` shell
mkdir build && cd build
cmake .. -G "CodeBlocks - Unix Makefiles"
xdg-open ./GenericStaticBitmap.cbp > /dev/null 2>&1
```

Select GenericStaticBitmap project and type F9 to build and run it.

### Linux :

``` shell
mkdir build && cd build
cmake .. 
cmake --build . --config Debug
./GenericStaticBitmap
```
