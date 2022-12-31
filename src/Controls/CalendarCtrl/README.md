# CalendarCtrl

Shows how to create a CalendarCtrl widget with wxCalendarCtrl.

## Source

[CalendarCtrl.cpp](CalendarCtrl.cpp)

[CMakeLists.txt](CMakeLists.txt)

## Output

![output](../../../docs/Pictures/CalendarCtrl.png)

## Build and run

To build this project, open "Terminal" and type following lines:

### Windows :

``` shell
mkdir build && cd build
cmake .. 
start CalendarCtrl.sln
```

Select CalendarCtrl project and type Ctrl+F5 to build and run it.

### macOS :

``` shell
mkdir build && cd build
cmake .. -G "Xcode"
open ./CalendarCtrl.xcodeproj
```

Select CalendarCtrl project and type Cmd+R to build and run it.

### Linux with Code::Blocks :

``` shell
mkdir build && cd build
cmake .. -G "CodeBlocks - Unix Makefiles"
xdg-open ./CalendarCtrl.cbp > /dev/null 2>&1
```

Select CalendarCtrl project and type F9 to build and run it.

### Linux :

``` shell
mkdir build && cd build
cmake .. 
cmake --build . --config Debug
./CalendarCtrl
```
