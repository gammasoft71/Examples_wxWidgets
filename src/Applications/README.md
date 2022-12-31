# Application Examples

[This folder](.) contains wxWidgets application examples.

* [Application](Application/README.md) shows how to create a simple wxWidgets application with wxApp.
* [ApplicationAndAssert](ApplicationAndAssert/README.md) shows how to create a simple wxWidgets application and how to manage assert.
* [ApplicationAndException](ApplicationAndException/README.md) shows how to create a simple wxWidgets application and how to manage exception.
* [ApplicationAndMain](ApplicationAndMain/README.md) shows how to create a wxWidgets application and main method with wxApp.
* [ApplicationAndMain2](ApplicationAndMain2/README.md) shows how to create a wxWidgets application and main method with wxApp.
* [ApplicationIcon](ApplicationIcon/README.md) shows how to create a wxWidgets application and icon with wxApp.

## Build and run

To build this project, open "Terminal" and type following lines:

### Windows
``` shell
mkdir build && cd build
cmake ..
start Applications.sln
```

Select any project and type Ctrl+F5 to build and run it.

### macOS :

``` shell
mkdir build && cd build
cmake .. -G "Xcode"
open ./Applications.xcodeproj
```

Select any project and type Cmd+R to build and run it.

### Linux with Code::Blocks :

``` shell
mkdir build
cd build
cmake .. -G "CodeBlocks - Unix Makefiles"
xdg-open ./Applications.cbp > /dev/null 2>&1
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
