# wxRichText examples

Shows how to use wxRichTextCanvas class for integrating OpenGL library.

[![wxwidgets](../docs/Pictures/wxwidgets_header.png)](https://www.wxwidgets.org/)

## [Dialogs](Dialogs/README.md)

* [SymbolPickerDialog](Dialogs/SymbolPickerDialog/README.md) shows how to create a SymbolPickerDialog with wxSymbolPickerDialog.

## [Controls](Controls/README.md)

* [RichTextCtrl](Controls/RichTextCtrl/README.md) shows how to create a RichTextBox widget with wxRichTextCtrl.

## Build and run

To build this project, open "Terminal" and type following lines:

### Windows
``` shell
mkdir build && cd build
cmake ..
start wxRichText.sln
```

Select any project and type Ctrl+F5 to build and run it.

### macOS :

``` shell
mkdir build && cd build
cmake .. -G "Xcode"
open ./wxRichText.xcodeproj
```

Select any project and type Cmd+R to build and run it.

### Linux with Code::Blocks :

``` shell
mkdir build
cd build
cmake .. -G "CodeBlocks - Unix Makefiles"
xdg-open ./wxRichText.cbp > /dev/null 2>&1
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
