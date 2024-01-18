# Window Docking

Shows how to use window docking examples.

* [AuiManager](AuiManager/README.md) shows how to create a AuiManager widget with wxAuiManager.
* [AuiNotebook](AuiNotebook/README.md) shows how to create a AuiNotebook widget with AuiNotebook.
* [AuiToolbar](AuiToolbar/README.md) shows how to create a AuiToolbar widget with wxAuiToolbar.

## Build and run

To build this project, open "Terminal" and type following lines:

### Windows
``` shell
mkdir build && cd build
cmake ..
start WindowDocking.sln
```

Select any project and type Ctrl+F5 to build and run it.

### macOS :

``` shell
mkdir build && cd build
cmake .. -G "Xcode"
open ./WindowDocking.xcodeproj
```

Select any project and type Cmd+R to build and run it.

### Linux with Code::Blocks :

``` shell
mkdir build
cd build
cmake .. -G "CodeBlocks - Unix Makefiles"
xdg-open ./WindowDocking.cbp > /dev/null 2>&1
```

Select any project and type F10 to build and run it.

### Linux :

``` shell
mkdir build
cd build
cmake ..
cmake --build . --config Debug
./AnyProject
```
