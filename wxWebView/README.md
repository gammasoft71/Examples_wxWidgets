# wxWebView examples

[This folder](.) contains web view examples.

[![wxwidgets](../docs/Pictures/wxwidgets_header.png)](https://www.wxwidgets.org/)

## [Controls](Controls/README.md)

* [WebView](Controls/WebView/README.md) shows how to create a WebView with wxWebView.
  
## Build and run

To build this project, open "Terminal" and type following lines:

### Windows
``` shell
mkdir build && cd build
cmake ..
start wxWebView.sln
```

Select any project and type Ctrl+F5 to build and run it.

### macOS :

``` shell
mkdir build && cd build
cmake .. -G "Xcode"
open ./wxWebView.xcodeproj
```

Select any project and type Cmd+R to build and run it.

### Linux with Code::Blocks :

``` shell
mkdir build
cd build
cmake .. -G "CodeBlocks - Unix Makefiles"
xdg-open ./wxWebView.cbp > /dev/null 2>&1
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
