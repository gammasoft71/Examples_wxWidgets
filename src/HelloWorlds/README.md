# wxWidgiets "Hello, world!" Examples

[This folder](.) contains wxWidgets "Hello, world!" examples.

* [HelloWorldEmoticons](HelloWorldEmoticons/README.md) The classic first application HelloWorld with emoticons.
* [HelloWorldGenericStaticText](HelloWorldGenericStaticText/README.md) The classic first application HelloWorld with wxGenericStaticText.
* [HelloWorldMessageDialog](HelloWorldMessageDialog/README.md) The classic first application HelloWorld with wxMessageDialog.
* [HelloWorldMessageDialog2](HelloWorldMessageDialog2/README.md) The classic first application HelloWorld with wxMessageDialog.
* [HelloWorldPaint](HelloWorldPaint/README.md) The classic first application HelloWorld with wxEVT_PAINT event.
* [HelloWorldSay](HelloWorldSay/README.md) The classic first application "Hello, World!" with Say.
* [HelloWorldStaticText](HelloWorldStaticText/README.md) The classic first application HelloWorld with wxStaticText.
* [wxWidgetsHelloWorld](wxWidgetsHelloWorld/README.md) The classic first application HelloWorld presented as skeleton by wxWidgets.

## Build and run

To build this project, open "Terminal" and type following lines:

### Windows
``` shell
mkdir build && cd build
cmake ..
start HelloWorlds.sln
```

Select any project and type Ctrl+F5 to build and run it.

### macOS :

``` shell
mkdir build && cd build
cmake .. -G "Xcode"
open ./HelloWorlds.xcodeproj
```

Select any project and type Cmd+R to build and run it.

### Linux with Code::Blocks :

``` shell
mkdir build
cd build
cmake .. -G "CodeBlocks - Unix Makefiles"
xdg-open ./HelloWorlds.cbp > /dev/null 2>&1
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
