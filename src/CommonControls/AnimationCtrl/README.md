# AnimationCtrl

Shows how to create a AnimationCtrl widget with wxAnimationCtrl.

## Source

[AnimationCtrl.cpp](AnimationCtrl.cpp)

[CMakeLists.txt](CMakeLists.txt)

## Build and run

To build this project, open "Terminal" and type following lines:

### Windows :

``` shell
mkdir build && cd build
cmake .. 
start AnimationCtrl.sln
```

Select AnimationCtrl project and type Ctrl+F5 to build and run it.

### macOS :

``` shell
mkdir build && cd build
cmake .. -G "Xcode"
open ./AnimationCtrl.xcodeproj
```

Select AnimationCtrl project and type Cmd+R to build and run it.

### Linux with Code::Blocks :

``` shell
mkdir build && cd build
cmake .. -G "CodeBlocks - Unix Makefiles"
xdg-open ./AnimationCtrl.cbp > /dev/null 2>&1
```

Select AnimationCtrl project and type F9 to build and run it.

### Linux :

``` shell
mkdir build && cd build
cmake .. 
cmake --build . --config Debug
./AnimationCtrl
```
