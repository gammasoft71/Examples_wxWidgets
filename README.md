# wxWidgets Examples

Shows how to use [wxWidgets](https://www.wxwidgets.org) controls only by programming code ([c++17](https://en.cppreference.com/w/)).

[![wxwidgets](docs/Pictures/wxwidgets_header.png)](https://www.wxwidgets.org/)

## [wxBase](wxBase/README.md) contains wxBase (Console) examples.

* [HelloWorlds](HelloWorlds/README.md)

## [wxCore](wxCore/README.md) contains wxCore (GUI) examples.

* [Hello World](wxCore/HelloWorlds/README.md) contains wxWidgets "Hello, World!" examples.
* [Applications](wxCore/Applications/README.md) contains applications examples.
* [Dialogs](wxCore/Dialogs/README.md) contains dialogs examples.
* [Frames](wxCore/Frames/README.md) contains frames examples.
* [Menus and toolbars](wxCore/MenusAndToolbars/README.md) contains menus and toolbars examples.
* [Containers](wxCore/Containers/README.md) contains containers examples.
* [Book Controls](wxCore/BookControls/README.md) contains book controls examples.
* [Controls](wxCore/Controls/README.md) contains controls examples.
* [Picker Controls](wxCore/PickerControls/README.md) contains picker controls examples.
* [Components](wxCore/Components/README.md) contains components examples.
* [Printing](wxCore/Printing/README.md) contains printing examples.
* [Events](wxCore/Events/README.md) contains events examples.
* [Painting](wxCore/Painting/README.md) contains painting examples.
* [User controls](wxCore/UserControls/README.md) contains user controls examples.
* [User Dialogs](wxCore/UserDialogs/README.md) contains user dialogs examples.
* [Others](wxCore/Others/README.md) contains others examples.

## [wxAUI](wxAUI/README.md) contains wxAUI (Advanced User Interface docking) examples.

* [Menus and toolbars](wxAUI/MenusAndToolbars/README.md) contains AUI menus and toolbars examples.
* [Containers](wxAUI/Containers/README.md) contains AUI containers examples.
* [Book Controls](wxAUI/BookControls/README.md) contains AUI book controls examples.

## [wxRichText](wxRichText/README.md) contains wxRichText (Rich Text) examples.

* [Dialogs](wxRichText/Dialogs/README.md) contains rich text dialogs examples.
* [Controls](wxRichText/Controls/README.md) contains rich text controls examples.

## [wxGL](wxGL/README.md) contains wxGL (Open GL) examples.

* [Controls](wxGL/Controls/README.md) contains GL common controls examples.

## Download

``` shell
git clone https://github.com/gammasoft71/Examples_wxWidgets
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

This project run with [wxWidgets](https://www.wxwidgets.org) 3.2 or above and [CMake](https://cmake.org) 3.20 or above.
