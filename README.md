# wxWidgets Examples

Shows how to use wxWidgets controls only by programming code (c++17).

[![wxwidgets](docs/Pictures/wxwidgets_header.png)](https://gammasoft71.wixsite.com/gammasoft/wxwidgets)

## wxWidgets

* [Hello World](src/HelloWorlds) contains wxWidgets "Hello, World!" examples.
* [Applications](src/Applications) contains applications examples.
* [Dialogs](src/Dialogs) contains dialogs examples.
* [Frames](src/Frames) contains frames examples.
* [Menus and toolbars](src/MenusAndToolbars) contains menus and toolbars examples.
* [Containers](src/Containers) contains containers examples.
* [Controls](src/Controls) contains common controls examples.
* [Book Controls](src/BookControls) contains book controls examples.
* [Picker Controls](src/PickerControls) contains picker controls examples.
* [Components](src/Components) contains components examples.
* [Printing](src/Printing) contains printing examples.
* [Events](src/Events) contains events examples.
* [Painting](src/Painting) contains painting examples.
* [Window Docking](src/WindowDocking) contains windows docking examples.
* [OpenGL](src/OpenGL) contains openGL examples.
* [User controls](src/UserControls) contains user controls examples.
* [User Dialogs](src/UserDialogs) contains user dialogs examples.
* [Others](src/Others) contains others examples.


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
