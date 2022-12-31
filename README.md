# wxWidgets Examples

Shows how to use [wxWidgets](https://www.wxwidgets.org) controls only by programming code (c++17).

[![wxwidgets](docs/Pictures/wxwidgets_header.png)](https://www.wxwidgets.org/)

## wxWidgets

* [Hello World](src/HelloWorlds/README.md) contains wxWidgets "Hello, World!" examples.
* [Applications](src/Applications/README.md) contains applications examples.
* [Dialogs](src/Dialogs/README.md) contains dialogs examples.
* [Frames](src/Frames/README.md) contains frames examples.
* [Menus and toolbars](src/MenusAndToolbars/README.md) contains menus and toolbars examples.
* [Containers](src/Containers/README.md) contains containers examples.
* [Controls](src/Controls/README.md) contains common controls examples.
* [Book Controls](src/BookControls/README.md) contains book controls examples.
* [Picker Controls](src/PickerControls/README.md) contains picker controls examples.
* [Components](src/Components/README.md) contains components examples.
* [Printing](src/Printing/README.md) contains printing examples.
* [Events](src/Events/README.md) contains events examples.
* [Painting](src/Painting/README.md) contains painting examples.
* [Window Docking](src/WindowDocking/README.md) contains windows docking examples.
* [OpenGL](src/OpenGL/README.md) contains openGL examples.
* [User controls](src/UserControls/README.md) contains user controls examples.
* [User Dialogs](src/UserDialogs/README.md) contains user dialogs examples.
* [Others](src/Others/README.md) contains others examples.
* [All](src/README.md) contains all examples.

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
