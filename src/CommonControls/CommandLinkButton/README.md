# CommandLinkButton

Shows how to create a CommandLinkButton widget with wxCommandLinkButton.

## Source

[CommandLinkButton.cpp](CommandLinkButton.cpp)

[CMakeLists.txt](CMakeLists.txt)

## Output

![output](../../../docs/Pictures/CommandLinkButton.png)

## Build and run

To build this project, open "Terminal" and type following lines:

### Windows :

``` shell
mkdir build && cd build
cmake .. 
start CommandLinkButton.sln
```

Select CommandLinkButton project and type Ctrl+F5 to build and run it.

### macOS :

``` shell
mkdir build && cd build
cmake .. -G "Xcode"
open ./CommandLinkButton.xcodeproj
```

Select CommandLinkButton project and type Cmd+R to build and run it.

### Linux with Code::Blocks :

``` shell
mkdir build && cd build
cmake .. -G "CodeBlocks - Unix Makefiles"
xdg-open ./CommandLinkButton.cbp > /dev/null 2>&1
```

Select CommandLinkButton project and type F9 to build and run it.

### Linux :

``` shell
mkdir build && cd build
cmake .. 
cmake --build . --config Debug
./CommandLinkButton
```
