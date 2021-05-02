# HelloWorldEmoticons

The classic first application "Hello World" with emoticons.

## Source

[HelloWorldEmoticons.cpp](HelloWorldEmoticons.cpp)

[CMakeLists.txt](CMakeLists.txt)

## Generate and build

To build this project, open "Terminal" and type following lines:

### Windows :

``` cmake
mkdir build
cd build
cmake .. 
start HelloWorldEmoticons.sln
```

### macOS :

``` cmake
mkdir build
cd build
cmake .. -G "Xcode"
open ./HelloWorldEmoticons.xcodeproj
```

### Linux with Code::Blocks :

``` shell
mkdir build
cd build
cmake .. -G "CodeBlocks - Unix Makefiles"
xdg-open ./HelloWorldEmoticons.cbp > /dev/null 2>&1
```

### Linux :

``` cmake
mkdir build
cd build
cmake .. 
cmake --build . --config Debug
```
