# wxWidgets Examples

Shows how to use wxWidgets controls only by programming code (c++17).

## Hello World

["Hello World"](src/HelloWorld/HelloWorld) The classic first application HelloWorld with wxStaticText.

## Application and messages

[Application](src/Application/Application) Shows how to create a simple wxWidgets application with wxApp.

[ApplicationAndMain](src/Application/ApplicationAndMain) Shows how to create a wxWidgets application and main method with wxApp.

[ApplicationIcon](src/Application/ApplicationIcon) Shows how to create a wxWidgets application and icon with wxApp.

[ApplicationIdle](src/Application/ApplicationIdle) Shows how to create an application and Idle event with wxApp.

## Common Controls

[Button](src/CommonControls/Button) Shows how to create a wxWidgets Button and Event Click with wxButton.

[CheckBox](src/CommonControls/CheckBox) Shows how to create a wxWidgets CheckBox with wxCheckBox.

[CheckedListBox](src/CommonControls/CheckedListBox) Shows how to create a wxWidgets CheckListBox with wxCheckListButton.

[ComboBox](src/CommonControls/ComboBox) Shows how to create a wxWidgets ComboBox with wxComboBox.

[Control](src/CommonControls/Control) Shows how to create a wxWidgets Control with wwxControl.

[DateTimePicker](src/CommonControls/DateTimePicker) Shows how to create a wxWidgets DateTimePicker with wxDatePicker.

[DomainUpDown](src/CommonControls/DomainUpDown) Shows how to create a wxWidgets DomainUpDown with own [wxDomainSpinCtrl](src/CommonControls/DomainUpDown/wxDomainSpinCtrl.h) (wxPanel with wxTextCtrl and wxSpinButton).

[HScrollBar](src/CommonControls/HScrollBar) Shows how to create a wxWidgets HScrollBar with wxScrollBar.

[Label](src/CommonControls/Label) Shows how to create a wxWidgets Label with wxStaticText.

[LinkLabel](src/CommonControls/LinkLabel) Shows how to create a wxWidgets LinkLabel with wxHyperLinkCtrl.

[ListBox](src/CommonControls/ListBox) Shows how to create a wxWidgets ListBox with wxListBox.

[ListView](src/CommonControls/ListView) Shows how to create a wxWidgets ListView with wxListCtrl.

[MonthCalendar](src/CommonControls/MonthCalendar) Shows how to create a wxWidgets MonthCalendar with wxCalendarCtrl.

[NotifyIcon](src/CommonControls/NotifyIcon) Shows how to create a wxWidgets NotifyIcon with own [wxNotifyIcon](src/CommonControls/NotifyIcon/wxNotifyIcon.h) (wxTaskBarIcon).

[NumericUpDown](src/CommonControls/NumericUpDown) Shows how to create a wxWidgets NumericUpDown with wxSpinCtrl and wxSpinCtrlDouble.

[PictureBox](src/CommonControls/PictureBox) Shows how to create a wxWidgets CheckBox with wxStaticBitmap.

[ProgressBar](src/CommonControls/ProgressBar) Shows how to create a wxWidgets ProgressBar with wxGauge.

[RadioButton](src/CommonControls/RadioButton) Shows how to create a wxWidgets RadioButton with wxRadioButton.

[RichTextBox](src/CommonControls/RichTextBox) Shows how to create a wxWidgets RichTextBox with wxRichTextCtrl.

[TextBox](src/CommonControls/TextBox) Shows how to create a wxWidgets TextBox with wxTextCtrl.

[ToolTip](src/CommonControls/ToolTip) Shows how to create a wxWidgets ToolTip with wxRichToolTip.

[TrackBar](src/CommonControls/TrackBar) Shows how to create a wxWidgets TrackBar with wxSlider.

[TreeView](src/CommonControls/TreeView) Shows how to create a wxWidgets TreeView with wxTreeCtrl.

[VScrollBar](src/CommonControls/VScrollBar) Shows how to create a wxWidgets VScrollBar with wxScrollBar.

[WebBrowser](src/CommonControls/WebBrowser) Shows how to create a wxWidgets WebBrowser with wxWebView.

## Containers

[Form](src/Containers/Form) Shows how to create a simple wxWidgets Form with wxFrame.

[GroupBox](src/Containers/GroupBox) Shows how to create a simple wxWidgets GroupBox with wxRadioBox.

[Panel](src/Containers/Panel) Shows how to create a simple wxWidgets Panel with wxPanel.

[TabControl](src/Containers/TabControl) Shows how to create a simple wxWidgets TabControl with TabPages with wxNotebook.

## Menus and toolbars

[MainMenu](src/MenusAndToolbars/MainMenu) Shows how to create a wxWidgets MainMenu with wxMenu.

## Components

[Timer](src/Componenets/Timer) Shows how to create a simple wxWidgets Timer with wxTimer.

## Dialogs

[ColorDialog](src/Dialogs/ColorDialog) Shows how to create a ColorDialog with wxColourDialog.

[MessageBox](src/Dialogs/MessageBox) Shows how to create a MessageBox with wxMessageBox.

## Download

``` shell
git clone https://github.com/gammasoft71/Examples.wxWidgets Examples.wxWidgets
```

## Generate and build

To build this project, open "Terminal" and type following lines:

### Windows
``` cmake
mkdir build
cd build
cmake ..
open Examples.wxWidgets.sln
```

### macOS :

``` cmake
mkdir build
cd build
cmake .. -G "Xcode"
open ./Examples.wxWidgets.xcodeproj
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
