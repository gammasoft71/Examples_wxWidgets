
# wxWidgets Examples

Shows how to use wxWidgets controls only by programming code (c++17).

## Hello World

["Hello World"](src/HelloWorld) The classic first application HelloWorld with wxStaticText.

## Application and messages

[Application](src/Application/Application) Shows how to create a simple Gtkmm application with wxApp.

## Common Controls

[Button](src/CommonControls/Button) Shows how to create a Gtkmm Button and Event Click with wxButton.

[CheckBox](src/CommonControls/CheckBox) Shows how to create a Gtkmm CheckBox with wxCheckButton.

[Label](src/CommonControls/Label) Shows how to create a Gtkmm Label with wxStaticText.

[ProgressBar](src/CommonControls/ProgressBar) Shows how to create a Gtkmm ProgressBar with wxGauge.

[RadioButton](src/CommonControls/RadioButton) Shows how to create a Gtkmm RadioButton with wxRadioButton.

[TextBox](src/CommonControls/TextBox) Shows how to create a Gtkmm TextBox with wxTextEntry.

[TrackBar](src/CommonControls/TrackBar) Shows how to create a Gtkmm TrackBar with wxSlider.

## Containers

[Form](src/Form) Shows how to create a simple Gtkmm Form with wxFrame.

[GroupBox](src/GroupBox) Shows how to create a simple Gtkmm GroupBox with wxRadioBox.

[Panel](src/Panel) Shows how to create a simple Gtkmm Panel with wxPanel.

[TabControl](src/TabControl) Shows how to create a simple Gtkmm TabControl with TabPages with wxNotebook.

## Menus and toolbars

[MainMenu](src/MainMenu) Shows how to create a Gtkmm MainMenu with wxMenu.

## Components

[Timer](src/Timer) Shows how to create a simple Gtkmm Timer with wxTimer.

## Dialogs

[ColorDialog](src/ColorDialog) Shows how to create a ColorDialog with wxColourDialog.

[MessageBox](src/MessageBox) Shows how to create a MessageBox with wxMessageBox.

## Download

``` shell
git clone https://github.com/gammasoft71/wxWidgetsExamples wxWidgetsExamples
```

## Generate and build

To build this project, open "Terminal" and type following lines:

### macOS :

``` cmake
mkdir build
cd build
cmake .. -G "Xcode"
open ./CocoaExamples.xcodeproj
```


### Linux :

``` cmake
mkdir build
cd build
cmake .. 
cmake --build . --config Debug
```

## Remarks

This project run with [wxWidgets](https://www.wxwidgets.org) and [CMake](https://cmake.org).
