# PasswordEntryDialog

Shows how to create a PasswordEntryDialog dialog with wxPasswordEntryDialog.

## Source

[PasswordEntryDialog.cpp](PasswordEntryDialog.cpp)

[CMakeLists.txt](CMakeLists.txt)

## Build and run

To build this project, open "Terminal" and type following lines:

### Windows :

``` shell
mkdir build && cd build
cmake .. 
start PasswordEntryDialog.sln
```

Select PasswordEntryDialog project and type Ctrl+F5 to build and run it.

### macOS :

``` shell
mkdir build && cd build
cmake .. -G "Xcode"
open ./PasswordEntryDialog.xcodeproj
```

Select PasswordEntryDialog project and type Cmd+R to build and run it.

### Linux with Code::Blocks :

``` shell
mkdir build && cd build
cmake .. -G "CodeBlocks - Unix Makefiles"
xdg-open ./PasswordEntryDialog.cbp > /dev/null 2>&1
```

Select PasswordEntryDialog project and type F9 to build and run it.

### Linux :

``` shell
mkdir build && cd build
cmake .. 
cmake --build . --config Debug
./PasswordEntryDialog
```
