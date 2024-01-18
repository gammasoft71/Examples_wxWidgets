# wxGL examples

Shows how to use wxGLCanvas class for integrating OpenGL library.

[![wxwidgets](../docs/Pictures/wxwidgets_header.png)](https://www.wxwidgets.org/)

## [Controls](Controls/README.md)

* [GLCanvas](GLCanvas/HelloWorldOpenGL/README.md) shows how to create an open GL caneva with wxGLCanvas and wxGLContext.

## Build and run

To build this project, open "Terminal" and type following lines:

### Windows
``` shell
mkdir build && cd build
cmake ..
start wxGL.sln
```

Select any project and type Ctrl+F5 to build and run it.

### macOS :

``` shell
mkdir build && cd build
cmake .. -G "Xcode"
open ./wxGL.xcodeproj
```

Select any project and type Cmd+R to build and run it.

### Linux with Code::Blocks :

``` shell
mkdir build
cd build
cmake .. -G "CodeBlocks - Unix Makefiles"
xdg-open ./wxGL.cbp > /dev/null 2>&1
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
