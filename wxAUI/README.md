# wxAUI Examples

Shows how to use Advanced User Interface docking library.

[![wxwidgets](../docs/Pictures/wxwidgets_header.png)](https://www.wxwidgets.org/)

## [Menus and toolbars](MenusAndToolbars/README.md)

* [AuiToolbar](WindowDocking/AuiToolbar/README.md) shows how to create a AuiToolbar widget with wxAuiToolbar.

## [Containers](Containers/README.md)

* [AuiManager](Containers/AuiManager/README.md) shows how to create a AuiManager widget with wxAuiManager.

## [Book Controls](BookControls/README.md)

* [AuiNotebook](BookControls/AuiNotebook/README.md) shows how to create a AuiNotebook widget with AuiNotebook.

## Build and run

To build this project, open "Terminal" and type following lines:

### Windows
``` shell
mkdir build && cd build
cmake ..
start wxAUI.sln
```

Select any project and type Ctrl+F5 to build and run it.

### macOS :

``` shell
mkdir build && cd build
cmake .. -G "Xcode"
open ./wxAUI.xcodeproj
```

Select any project and type Cmd+R to build and run it.

### Linux with Code::Blocks :

``` shell
mkdir build
cd build
cmake .. -G "CodeBlocks - Unix Makefiles"
xdg-open ./wxAUI.cbp > /dev/null 2>&1
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
