# HelloWorldConsole

The classic first application "Hello World" with emoticons.

## Source

[HelloWorldConsole.cpp](HelloWorldConsole.cpp)

[CMakeLists.txt](CMakeLists.txt)

## Output

```
Hello, World!
```

## Build and run

To build this project, open "Terminal" and type following lines:

### Windows :

``` shell
mkdir build && cd build
cmake .. 
start HelloWorldConsole.sln
```

Select HelloWorldConsole project and type Ctrl+F5 to build and run it.

### macOS :

``` shell
mkdir build && cd build
cmake .. -G "Xcode"
open ./HelloWorldConsole.xcodeproj
```

Select HelloWorldConsole project and type Cmd+R to build and run it.

### Linux with Code::Blocks :

``` shell
mkdir build && cd build
cmake .. -G "CodeBlocks - Unix Makefiles"
xdg-open ./HelloWorldConsole.cbp > /dev/null 2>&1
```

Select HelloWorldConsole project and type F9 to build and run it.

### Linux :

``` shell
mkdir build && cd build
cmake .. 
cmake --build . --config Debug
./HelloWorldConsole
```
