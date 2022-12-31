# wxWidgets Examples

Shows how to use wxWidgets controls only by programming code (c++17).

[![wxwidgets](docs/Pictures/wxwidgets_header.png)](https://gammasoft71.wixsite.com/gammasoft/wxwidgets)

## wxWidgets

* [Hello World](src/HelloWorlds)
* [Applications](src/Applications)
* [Dialogs](src/Dialogs)
* [Frames](src/Frames)
* [Menus and toolbars](src/MenusAndToolbars)
* [Containers](src/Containers)
* [Controls](src/Controls)
* [Book Controls](src/BookControls)
* [Picker Controls](src/PickerControls)
* [Components](src/Components)
* [Printing](src/Printing)
* [Events](src/Events)
* [Painting](src/Painting)
* [Window Docking](src/WindowDocking)
* [OpenGL](src/OpenGL)
* [User controls](src/UserControls)
* [User Dialogs](src/UserDialogs)
* [Others](src/Others)

* [All](src/README.md)

## Download

``` shell
git clone https://github.com/gammasoft71/Examples_wxWidgets Examples_wxWidgets
```

## Build and run

To build this project, open "Terminal" and type following lines:

### Windows
``` shell
mkdir build && cd build
cmake ..
start wxWidgetsExamples.sln
```

Select any project and type Ctrl+F5 to build and run it.

### macOS :

``` shell
mkdir build && cd build
cmake .. -G "Xcode"
open ./wxWidgetsExamples.xcodeproj
```

Select any project and type Cmd+R to build and run it.

### Linux with Code::Blocks :

``` shell
mkdir build
cd build
cmake .. -G "CodeBlocks - Unix Makefiles"
xdg-open ./wxWidgetsExamples.cbp > /dev/null 2>&1
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

## Remarks

This project run with [wxWidgets](https://www.wxwidgets.org) 3.2 or above and [CMake](https://cmake.org) 3.0 or above.
