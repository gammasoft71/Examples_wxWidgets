# TreeCtrl

Shows how to create a TreeCtrl widget with wxTreeCtrl.

## Source

[TreeCtrl.cpp](TreeCtrl.cpp)

[CMakeLists.txt](CMakeLists.txt)

## Build and run

To build this project, open "Terminal" and type following lines:

### Windows :

``` shell
mkdir build && cd build
cmake .. 
start TreeCtrl.sln
```

Select TreeCtrl project and type Ctrl+F5 to build and run it.

### macOS :

``` shell
mkdir build && cd build
cmake .. -G "Xcode"
open ./TreeCtrl.xcodeproj
```

Select TreeCtrl project and type Cmd+R to build and run it.

### Linux with Code::Blocks :

``` shell
mkdir build && cd build
cmake .. -G "CodeBlocks - Unix Makefiles"
xdg-open ./TreeCtrl.cbp > /dev/null 2>&1
```

Select TreeCtrl project and type F9 to build and run it.

### Linux :

``` shell
mkdir build && cd build
cmake .. 
cmake --build . --config Debug
./TreeCtrl
```
