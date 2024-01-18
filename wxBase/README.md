# wxBase Examples

Shows how to use wxBase library.

[![wxwidgets](docs/Pictures/wxwidgets_header.png)](https://www.wxwidgets.org/)

## [HelloWorlds](HelloWorlds/README.md)

* [HelloWorldConsole](HelloWorlds/HelloWorldConsole/README.md) The classic first application "Hello, World!" with wxPrintf method.

## Build and run

To build this project, open "Terminal" and type following lines:

### Windows
``` shell
mkdir build && cd build
cmake ..
start HelloWorlds.sln
```

Select any project and type Ctrl+F5 to build and run it.

### macOS :

``` shell
mkdir build && cd build
cmake .. -G "Xcode"
open ./HelloWorlds.xcodeproj
```

Select any project and type Cmd+R to build and run it.

### Linux with Code::Blocks :

``` shell
mkdir build
cd build
cmake .. -G "CodeBlocks - Unix Makefiles"
xdg-open ./HelloWorlds.cbp > /dev/null 2>&1
```

Select any project and type F10 to build and run it.

### Linux :

``` shell
mkdir build
cd build
cmake ..
cmake --build . --config Debug
./AnyProject
```
