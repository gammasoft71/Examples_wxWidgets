# BitmapButtonWithLabel

Shows how to create a Button with Bitmap and Label widget with wxButton.

## Source

[BitmapButtonWithLabel.cpp](BitmapButtonWithLabel.cpp)

[CMakeLists.txt](CMakeLists.txt)

## Output

![output](../../../docs/Pictures/BitmapButtonWithLabel.png)

## Build and run

To build this project, open "Terminal" and type following lines:

### Windows :

``` shell
mkdir build && cd build
cmake .. 
start BitmapButtonWithLabel.sln
```

Select BitmapButtonWithLabel project and type Ctrl+F5 to build and run it.

### macOS :

``` shell
mkdir build && cd build
cmake .. -G "Xcode"
open ./BitmapButtonWithLabel.xcodeproj
```

Select BitmapButtonWithLabel project and type Cmd+R to build and run it.

### Linux with Code::Blocks :

``` shell
mkdir build && cd build
cmake .. -G "CodeBlocks - Unix Makefiles"
xdg-open ./BitmapButtonWithLabel.cbp > /dev/null 2>&1
```

Select BitmapButtonWithLabel project and type F9 to build and run it.

### Linux :

``` shell
mkdir build && cd build
cmake .. 
cmake --build . --config Debug
./BitmapButtonWithLabel
```
