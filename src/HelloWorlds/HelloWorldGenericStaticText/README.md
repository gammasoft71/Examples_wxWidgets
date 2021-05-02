# HelloWorldGenericStaticText

The classic first application "Hello World" with wxGenericStaticText.

## Source

[HelloWorldGenericStaticText.cpp](HelloWorldGenericStaticText.cpp)

[CMakeLists.txt](CMakeLists.txt)

## Build and run

To build this project, open "Terminal" and type following lines:

### Windows :

``` shell
mkdir build && cd build
cmake .. 
start HelloWorldGenericStaticText.sln
```

Select HelloWorldGenericStaticText project and type Ctrl+F5 to build and run it.

### macOS :

``` shell
mkdir build && cd build
cmake .. -G "Xcode"
open ./HelloWorldGenericStaticText.xcodeproj
```

Select HelloWorldGenericStaticText project and type Cmd+R to build and run it.

### Linux with Code::Blocks :

``` shell
mkdir build && cd build
cmake .. -G "CodeBlocks - Unix Makefiles"
xdg-open ./HelloWorldGenericStaticText.cbp > /dev/null 2>&1
```

Select HelloWorldGenericStaticText project and type F9 to build and run it.

### Linux :

``` shell
mkdir build && cd build
cmake .. 
cmake --build . --config Debug
./HelloWorldGenericStaticText
```
