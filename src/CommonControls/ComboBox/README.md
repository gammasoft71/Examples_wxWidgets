# ComboBox

Shows how to create a ComboBox widget with wxComboBox.

## Source

[ComboBox.cpp](ComboBox.cpp)

[CMakeLists.txt](CMakeLists.txt)

## Build and run

To build this project, open "Terminal" and type following lines:

### Windows :

``` shell
mkdir build && cd build
cmake .. 
start ComboBox.sln
```

Select ComboBox project and type Ctrl+F5 to build and run it.

### macOS :

``` shell
mkdir build && cd build
cmake .. -G "Xcode"
open ./ComboBox.xcodeproj
```

Select ComboBox project and type Cmd+R to build and run it.

### Linux with Code::Blocks :

``` shell
mkdir build && cd build
cmake .. -G "CodeBlocks - Unix Makefiles"
xdg-open ./ComboBox.cbp > /dev/null 2>&1
```

Select ComboBox project and type F9 to build and run it.

### Linux :

``` shell
mkdir build && cd build
cmake .. 
cmake --build . --config Debug
./ComboBox
```
