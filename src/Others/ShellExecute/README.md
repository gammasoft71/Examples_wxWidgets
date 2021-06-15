# ShellExecute

Shows how to launch process with wxShellExecute.

## Source

[ShellExecute.cpp](ShellExecute.cpp)

[CMakeLists.txt](CMakeLists.txt)

## Build and run

To build this project, open "Terminal" and type following lines:

### Windows :

``` shell
mkdir build && cd build
cmake .. 
start ShellExecute.sln
```

Select ShellExecute project and type Ctrl+F5 to build and run it.

### macOS :

``` shell
mkdir build && cd build
cmake .. -G "Xcode"
open ./ShellExecute.xcodeproj
```

Select ShellExecute project and type Cmd+R to build and run it.

### Linux with Code::Blocks :

``` shell
mkdir build && cd build
cmake .. -G "CodeBlocks - Unix Makefiles"
xdg-open ./ShellExecute.cbp > /dev/null 2>&1
```

Select ShellExecute project and type F9 to build and run it.

### Linux :

``` shell
mkdir build && cd build
cmake .. 
cmake --build . --config Debug
./ShellExecute
```
