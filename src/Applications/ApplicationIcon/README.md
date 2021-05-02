# ApplicationIcon

Shows how to create a simple wxWidgets application and icon with wxApp.

## Source

[ApplicationIcon.cpp](ApplicationIcon.cpp)

[CMakeLists.txt](CMakeLists.txt)

[Resources/Gammasoft.icns](Resources/Gammasoft.icns)

[Resources/Gammasoft.ico](Resources/Gammasoft.ico)

[Resources/Gammasoft.png](Resources/Gammasoft.png)

## Build and run

To build this project, open "Terminal" and type following lines:

### Windows :

``` shell
mkdir build && cd build
cmake .. 
start ApplicationIcon.sln
```

Select Application project and type Ctrl+F5 to build and run it.

### macOS :

``` shell
mkdir build && cd build
cmake .. -G "Xcode"
open ./ApplicationIcon.xcodeproj
```

Select ApplicationIcon project and type Cmd+R to build and run it.

### Linux with Code::Blocks :

``` shell
mkdir build && cd build
cmake .. -G "CodeBlocks - Unix Makefiles"
xdg-open ./ApplicationIcon.cbp > /dev/null 2>&1
```

Select ApplicationIcon project and type F9 to build and run it.

### Linux :

``` shell
mkdir build && cd build
cmake .. 
cmake --build . --config Debug
./ApplicationIcon
```
