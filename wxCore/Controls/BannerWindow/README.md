# BannerWindow

shows how to create a wxBannerWindow.

## Source

[BannerWindow.cpp](BannerWindow.cpp)

[CMakeLists.txt](CMakeLists.txt)

## Output

![output](../../../docs/Pictures/BannerWindow.png)

## Build and run

To build this project, open "Terminal" and type following lines:

### Windows :

``` shell
mkdir build && cd build
cmake .. 
start BannerWindow.sln
```

Select BannerWindow project and type Ctrl+F5 to build and run it.

### macOS :

``` shell
mkdir build && cd build
cmake .. -G "Xcode"
open ./BannerWindow.xcodeproj
```

Select BannerWindow project and type Cmd+R to build and run it.

### Linux with Code::Blocks :

``` shell
mkdir build && cd build
cmake .. -G "CodeBlocks - Unix Makefiles"
xdg-open ./BannerWindow.cbp > /dev/null 2>&1
```

Select BannerWindow project and type F9 to build and run it.

### Linux :

``` shell
mkdir build && cd build
cmake .. 
cmake --build . --config Debug
./BannerWindow
```
