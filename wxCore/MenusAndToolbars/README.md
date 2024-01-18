# Menus and toolbars Examples

[This folder](.) contains menus and toolbars examples.

* [MainMenu](MainMenu/README.md) shows how to create a MainMenu widget with wxMenu.
* [Menu](Menu/README.md) shows how to create a (contextual) Menu widget with wxMenu.
* [StatusBar](StatusBar/README.md) shows how to create a StatusBar widget with wxStatusBar.
* [StatusBarWithoutPanels](StatusBarWithoutPanels/README.md) shows how to create a StatusBar widget with wxStatusBar.
* [ToolBar](ToolBar/README.md) shows how to create a ToolBar widget with wxToolBar.

## Build and run

To build this project, open "Terminal" and type following lines:

### Windows
``` shell
mkdir build && cd build
cmake ..
start MenusAndToolbars.sln
```

Select any project and type Ctrl+F5 to build and run it.

### macOS :

``` shell
mkdir build && cd build
cmake .. -G "Xcode"
open ./MenusAndToolbars.xcodeproj
```

Select any project and type Cmd+R to build and run it.

### Linux with Code::Blocks :

``` shell
mkdir build
cd build
cmake .. -G "CodeBlocks - Unix Makefiles"
xdg-open ./MenusAndToolbars.cbp > /dev/null 2>&1
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
