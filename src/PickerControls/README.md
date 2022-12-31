# Picker control Examples

[This folder](.) contains picker control examples.

* [ColourPickerCtrl](ColourPickerCtrl/README.md) shows how to create a ColourPickerCtrl widget with wxColourPickerCtrl.
* [DatePickerCtrl](DatePickerCtrl/README.md) shows how to create a DatePicker widget with wxDatePickerCtrl.
* [DirPickerCtrl](DirPickerCtrl/README.md) shows how to create a DirPickerCtrl widget with wxDirPickerCtrl.
* [FilePickerCtrl](FilePickerCtrl/README.md) shows how to create a FilePickerCtrl widget with wxFilePickerCtrl.
* [FontPickerCtrl](FontPickerCtrl/README.md) shows how to create a FontPickerCtrl widget with wxFontPickerCtrl.
* [TimePickerCtrl](TimePickerCtrl/README.md) shows how to create a TimePicker widget with wxTimePickerCtrl.

## Build and run

To build this project, open "Terminal" and type following lines:

### Windows
``` shell
mkdir build && cd build
cmake ..
start PickerControls.sln
```

Select any project and type Ctrl+F5 to build and run it.

### macOS :

``` shell
mkdir build && cd build
cmake .. -G "Xcode"
open ./PickerControls.xcodeproj
```

Select any project and type Cmd+R to build and run it.

### Linux with Code::Blocks :

``` shell
mkdir build
cd build
cmake .. -G "CodeBlocks - Unix Makefiles"
xdg-open ./PickerControls.cbp > /dev/null 2>&1
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
