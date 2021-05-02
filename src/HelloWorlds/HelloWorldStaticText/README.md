# HelloWorldMessageDialog

The classic first application "Hello World" with wxStaticText.

## Source

[HelloWorldMessageDialog.cpp](HelloWorldMessageDialog.cpp)

[CMakeLists.txt](CMakeLists.txt)

## Build and run

To build this project, open "Terminal" and type following lines:

### Windows :

``` shell
mkdir build && cd build
cmake .. 
start HelloWorldMessageDialog.sln
```

Select HelloWorldMessageDialog project and type Ctrl+F5 to build and run it.

### macOS :

``` shell
mkdir build && cd build
cmake .. -G "Xcode"
open ./HelloWorldMessageDialog.xcodeproj
```

Select HelloWorldMessageDialog project and type Cmd+R to build and run it.

### Linux with Code::Blocks :

``` shell
mkdir build && cd build
cmake .. -G "CodeBlocks - Unix Makefiles"
xdg-open ./HelloWorldMessageDialog.cbp > /dev/null 2>&1
```

Select HelloWorldMessageDialog project and type F9 to build and run it.

### Linux :

``` shell
mkdir build && cd build
cmake .. 
cmake --build . --config Debug
./HelloWorldMessageDialog
```
