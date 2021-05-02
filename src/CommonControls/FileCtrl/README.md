# FileCtrl

Shows how to create a FileCtrl widget with wxFileCtrl.

## Source

[FileCtrl.cpp](FileCtrl.cpp)

[CMakeLists.txt](CMakeLists.txt)

## Build and run

To build this project, open "Terminal" and type following lines:

### Windows :

``` shell
mkdir build && cd build
cmake .. 
start FileCtrl.sln
```

Select FileCtrl project and type Ctrl+F5 to build and run it.

### macOS :

``` shell
mkdir build && cd build
cmake .. -G "Xcode"
open ./FileCtrl.xcodeproj
```

Select FileCtrl project and type Cmd+R to build and run it.

### Linux with Code::Blocks :

``` shell
mkdir build && cd build
cmake .. -G "CodeBlocks - Unix Makefiles"
xdg-open ./FileCtrl.cbp > /dev/null 2>&1
```

Select FileCtrl project and type F9 to build and run it.

### Linux :

``` shell
mkdir build && cd build
cmake .. 
cmake --build . --config Debug
./FileCtrl
```
