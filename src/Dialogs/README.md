# Dialog Examples

[This folder](.) contains dialog examples.

* [AboutBox](AboutBox/README.md) shows how to create a AboutBox with wxAboutBox.
* [BusyInfo](BusyInfo/README.md) shows how to create a BusyInfo with wxBusyInfo.
* [ColourDialog](ColourDialog/README.md) shows how to create a ColourDialog with wxColourDialog.
* [DirDialog](DirDialog/README.md) shows how to create a DirDialog with wxDirDialog.
* [FindReplaceDialog](FindReplaceDialog/README.md) shows how to create a FindReplaceDialog with wxFindReplaceDialog.
* [FontDialog](FontDialog/README.md) shows how to create a FontDialog with wxFontDialog.
* [GenericAboutBox](GenericAboutBox/README.md) shows how to create a GenericAboutBox with wxGenericAboutBox.
* [GenericFindReplaceDialog](GenericFindReplaceDialog/README.md) shows how to create a GenericFindReplaceDialog with wxGeenericFindReplaceDialog.
* [GenericProgressDialog](GenericProgressDialog/README.md) shows how to create a GenericProgressDialog with wxGenericProgressDialog.
* [MessageDialog](MessageDialog/README.md) shows how to create a MessageDialog with wxMessageDialog.
* [MultiChoiceDialog](MultiChoiceDialog/README.md) shows how to create a MultiChoiceDialog with wxMultiChoiceDialog.
* [NotificationMessage](NotificationMessage/README.md) shows how to create a NotificationMessage with wxNotificationMessage.
* [NumberEntryDialog](NumberEntryDialog/README.md) shows how to create a NumberEntryDialog with wxNumberEntryDialog.
* [OpenFileDialog](OpenFileDialog/README.md) shows how to create a OpenFileDialog with wxOpenFileDialog.
* [PasswordEntryDialog](PasswordEntryDialog/README.md) shows how to create a PasswordEntryDialog with wxPasswordEntryDialog.
* [ProgressDialog](ProgressDialog/README.md) shows how to create a ProgressDialog with wxProgressDialog.
* [RearrangeDialog](RearrangeDialog/README.md) shows how to create a RearrangeDialog with wxRearrangeDialog.
* [SaveFileDialog](SaveFileDialog/README.md) shows how to create a SaveFileDialog with wxSaveFileDialog.
* [SingleChoiceDialog](SingleChoiceDialog/README.md) shows how to create a DirDialog with wxSingleChoiceDialog.
* [SymbolPickerDialog](SymbolPickerDialog/README.md) shows how to create a SymbolPickerDialog with wxSymbolPickerDialog.
* [TextEntryDialog](TextEntryDialog/README.md) shows how to create a TextEntryDialog with wxTextEntryDialog.
* [Wizard](Wizard/README.md) shows how to create a Wizard with wxWizard.

## Build and run

To build this project, open "Terminal" and type following lines:

### Windows
``` shell
mkdir build && cd build
cmake ..
start Dialogs.sln
```

Select any project and type Ctrl+F5 to build and run it.

### macOS :

``` shell
mkdir build && cd build
cmake .. -G "Xcode"
open ./Dialogs.xcodeproj
```

Select any project and type Cmd+R to build and run it.

### Linux with Code::Blocks :

``` shell
mkdir build
cd build
cmake .. -G "CodeBlocks - Unix Makefiles"
xdg-open ./Dialogs.cbp > /dev/null 2>&1
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
