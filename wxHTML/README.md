# wxHTML examples

Shows how to use Simple HTML renderer and other wxHTML Overview such as wxHtmlHelpController, wxBestHelpController and wxHtmlListBox.

[![wxwidgets](../docs/Pictures/wxwidgets_header.png)](https://www.wxwidgets.org/)

## [HelloWorlds](HelloWorlds/README.md)

* [HelloWorldHTML](HelloWorlds/HelloWorldHTML/README.md) The classic first application "Hello, World!".

## Build and run

To build this project, open "Terminal" and type following lines:

### Windows
``` shell
mkdir build && cd build
cmake ..
start wxHTML.sln
```

Select any project and type Ctrl+F5 to build and run it.

### macOS :

``` shell
mkdir build && cd build
cmake .. -G "Xcode"
open ./wxHTML.xcodeproj
```

Select any project and type Cmd+R to build and run it.

### Linux with Code::Blocks :

``` shell
mkdir build
cd build
cmake .. -G "CodeBlocks - Unix Makefiles"
xdg-open ./wxHTML.cbp > /dev/null 2>&1
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
