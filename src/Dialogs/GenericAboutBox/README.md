# GenericAboutBox

Shows how to create a GenericAboutBox dialog with wxGenericAboutBox.

## Source

[GenericAboutBox.cpp](GenericAboutBox.cpp)

[CMakeLists.txt](CMakeLists.txt)

## Output

![output](../../../docs/Pictures/GenericAboutBox.png)

## Build and run

To build this project, open "Terminal" and type following lines:

### Windows :

``` shell
mkdir build && cd build
cmake .. 
start GenericAboutBox.sln
```

Select GenericAboutBox project and type Ctrl+F5 to build and run it.

### macOS :

``` shell
mkdir build && cd build
cmake .. -G "Xcode"
open ./GenericAboutBox.xcodeproj
```

Select GenericAboutBox project and type Cmd+R to build and run it.

### Linux with Code::Blocks :

``` shell
mkdir build && cd build
cmake .. -G "CodeBlocks - Unix Makefiles"
xdg-open ./GenericAboutBox.cbp > /dev/null 2>&1
```

Select GenericAboutBox project and type F9 to build and run it.

### Linux :

``` shell
mkdir build && cd build
cmake .. 
cmake --build . --config Debug
./GenericAboutBox
```
