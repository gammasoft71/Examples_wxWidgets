# Event Examples

[This folder](.) contains event examples.

* [ApplicationIdle](ApplicationIdle/README.md) shows how to create an application and catch idle event.
* [CustomEvent](CustomEvent/README.md) shows how to create a CustomEvent event with wxCommandEvent.
* [EvtHandlerFilterEvent](EvtHandlerFilterEvent/README.md) shows how to use EvtHandler::FilterEvent method.
* [FrameAndEvents](FrameAndREADME.md) shows how to create a Frame and catch some events.
* [FrameClick](FrameClick/README.md) shows how to create a Frame and catch click event.
* [FramePaint](FramePaint/README.md) shows how to create a Frame and catch paint event.
* [KeyEvents](KeyREADME.md) shows how to create a Frame and catch key events.
* [MouseEvents](MouseREADME.md) shows how to create a Frame and catch mouse events.
* [ProcessEvent](ProcessEvent/README.md) shows how to override ProcessEvent method.

## Build and run

To build this project, open "Terminal" and type following lines:

### Windows
``` shell
mkdir build && cd build
cmake ..
start Events.sln
```

Select any project and type Ctrl+F5 to build and run it.

### macOS :

``` shell
mkdir build && cd build
cmake .. -G "Xcode"
open ./Events.xcodeproj
```

Select any project and type Cmd+R to build and run it.

### Linux with Code::Blocks :

``` shell
mkdir build
cd build
cmake .. -G "CodeBlocks - Unix Makefiles"
xdg-open ./Events.cbp > /dev/null 2>&1
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
