# Component Examples

[This folder](.) contains component examples.

* [ArtProvider](ArtProvider/README.md) shows how to create a simple ArtProvider component with wxArtProvider.
* [BusyCursor](BusyCursor/README.md) shows how to show or hide wxBusyCursor.
* [Config](Config/README.md) shows how to create a simple Config component with wxConfig.
* [Config2](Config2/README.md) shows how to create a simple Config component with wxConfig.
* [Cursor](Cursor/README.md) shows how to create a simple Cursor component with wxCursor.
* [ImageList](ImageList/README.md) shows how to create a simple ImageList component with wxImageList.
* [RichToolTip](RichToolTip/README.md) shows how to create a RichToolTip widget with wxRichToolTip.
* [Timer](Timer/README.md) shows how to create a simple Timer component with wxTimer.
* [ToolTip](ToolTip/README.md) shows how to create a ToolTip component.

## Build and run

To build this project, open "Terminal" and type following lines:

### Windows
``` shell
mkdir build && cd build
cmake ..
start Components.sln
```

Select any project and type Ctrl+F5 to build and run it.

### macOS :

``` shell
mkdir build && cd build
cmake .. -G "Xcode"
open ./Components.xcodeproj
```

Select any project and type Cmd+R to build and run it.

### Linux with Code::Blocks :

``` shell
mkdir build
cd build
cmake .. -G "CodeBlocks - Unix Makefiles"
xdg-open ./Components.cbp > /dev/null 2>&1
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
