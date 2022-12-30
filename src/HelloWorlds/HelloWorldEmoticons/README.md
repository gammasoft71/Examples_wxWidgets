# HelloWorldEmoticons

The classic first application "Hello World" with emoticons.

## Source

[HelloWorldEmoticons.cpp](HelloWorldEmoticons.cpp)

[CMakeLists.txt](CMakeLists.txt)

## Output

![output](../../../docs/Pictures/HelloWorldEmoticons.png)

## Build and run

To build this project, open "Terminal" and type following lines:

### Windows :

``` shell
mkdir build && cd build
cmake .. 
start HelloWorldEmoticons.sln
```

Select HelloWorldEmoticons project and type Ctrl+F5 to build and run it.

### macOS :

``` shell
mkdir build && cd build
cmake .. -G "Xcode"
open ./HelloWorldEmoticons.xcodeproj
```

Select HelloWorldEmoticons project and type Cmd+R to build and run it.

### Linux with Code::Blocks :

``` shell
mkdir build && cd build
cmake .. -G "CodeBlocks - Unix Makefiles"
xdg-open ./HelloWorldEmoticons.cbp > /dev/null 2>&1
```

Select HelloWorldEmoticons project and type F9 to build and run it.

### Linux :

``` shell
mkdir build && cd build
cmake .. 
cmake --build . --config Debug
./HelloWorldEmoticons
```
