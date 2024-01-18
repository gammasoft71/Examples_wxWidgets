# GraphicsContext

Shows how to create a form and catch paint event.

## Source

[GraphicsContext.cpp](GraphicsContext.cpp)

[CMakeLists.txt](CMakeLists.txt)

## Output

![output](../../../docs/Pictures/GRaphicContext.png)

## Build and run

To build this project, open "Terminal" and type following lines:

### Windows :

``` shell
mkdir build && cd build
cmake .. 
start GraphicsContext.sln
```

Select GraphicsContext project and type Ctrl+F5 to build and run it.

### macOS :

``` shell
mkdir build && cd build
cmake .. -G "Xcode"
open ./GraphicsContext.xcodeproj
```

Select GraphicsContext project and type Cmd+R to build and run it.

### Linux with Code::Blocks :

``` shell
mkdir build && cd build
cmake .. -G "CodeBlocks - Unix Makefiles"
xdg-open ./GraphicsContext.cbp > /dev/null 2>&1
```

Select GraphicsContext project and type F9 to build and run it.

### Linux :

``` shell
mkdir build && cd build
cmake .. 
cmake --build . --config Debug
./GraphicsContext
```
