# StaticBitmap

Shows how to create a StaticBitmap widget with wxStaticBitmap.

## Source

[Logo.xpm](Logo.xpm)

[StaticBitmap.cpp](StaticBitmap.cpp)

[CMakeLists.txt](CMakeLists.txt)

## Build and run

To build this project, open "Terminal" and type following lines:

### Windows :

``` shell
mkdir build && cd build
cmake .. 
start StaticBitmap.sln
```

Select StaticBitmap project and type Ctrl+F5 to build and run it.

### macOS :

``` shell
mkdir build && cd build
cmake .. -G "Xcode"
open ./StaticBitmap.xcodeproj
```

Select StaticBitmap project and type Cmd+R to build and run it.

### Linux with Code::Blocks :

``` shell
mkdir build && cd build
cmake .. -G "CodeBlocks - Unix Makefiles"
xdg-open ./StaticBitmap.cbp > /dev/null 2>&1
```

Select StaticBitmap project and type F9 to build and run it.

### Linux :

``` shell
mkdir build && cd build
cmake .. 
cmake --build . --config Debug
./StaticBitmap
```
