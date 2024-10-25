# StackTrace

Shows how to use wxStackWalker.

## Source

[StackTrace.cpp](StackTrace.cpp)

[CMakeLists.txt](CMakeLists.txt)

## Output

```
Stack Trace :
   at method3() [0x00000000] in StackTrace.cpp:line 63
   at method2() [0x00000000] in StackTrace.cpp:line 68
   at method1() [0x00000000] in StackTrace.cpp:line 72
   at main [0x00000000] in StackTrace.cpp:line 76
   at start [0x00000000] in :line 0
```

## Build and run

To build this project, open "Terminal" and type following lines:

### Windows :

``` shell
mkdir build && cd build
cmake .. 
start StackTrace.sln
```

Select StackTrace project and type Ctrl+F5 to build and run it.

### macOS :

``` shell
mkdir build && cd build
cmake .. -G "Xcode"
open ./StackTrace.xcodeproj
```

Select StackTrace project and type Cmd+R to build and run it.

### Linux with Code::Blocks :

``` shell
mkdir build && cd build
cmake .. -G "CodeBlocks - Unix Makefiles"
xdg-open ./StackTrace.cbp > /dev/null 2>&1
```

Select StackTrace project and type F9 to build and run it.

### Linux :

``` shell
mkdir build && cd build
cmake .. 
cmake --build . --config Debug
./StackTrace
```
