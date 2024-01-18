# User control Examples

[This folder](.) contains user control examples.

* [DomainSpinCtrl](DomainSpinCtrl/README.md) shows how to create a DomainSpinCtrl widget with own [wxDomainSpinCtrl](DomainSpinCtrl/wxDomainSpinCtrl.h) (wxPanel with wxTextCtrl and wxSpinButton).
* [Line](Line/README.md) shows how to create a custom control Line from wxPanel.
* [NumericTextCtrl](NumericTextCtrl/README.md) shows how to create a custom control NumericTextCtrl from wxTextCtrl.

## Build and run

To build this project, open "Terminal" and type following lines:

### Windows
``` shell
mkdir build && cd build
cmake ..
start UserControls.sln
```

Select any project and type Ctrl+F5 to build and run it.

### macOS :

``` shell
mkdir build && cd build
cmake .. -G "Xcode"
open ./UserControls.xcodeproj
```

Select any project and type Cmd+R to build and run it.

### Linux with Code::Blocks :

``` shell
mkdir build
cd build
cmake .. -G "CodeBlocks - Unix Makefiles"
xdg-open ./UserControls.cbp > /dev/null 2>&1
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
