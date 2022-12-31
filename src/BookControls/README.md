# Book control Examples

[This folder](.) contains book control examples.

* [Choicebook](Choicebook/README.md) shows how to create a Choicebook widget with wxChoiceBook.
* [Listbook](Listbook/README.md) shows how to create a Listbook widget with wxListBook.
* [Notebook](Notebook/README.md) shows how to create a Notebook widget with wxNoteBook.
* [Simplebook](Simplebook/README.md) shows how to create a Simplebook widget with wxSimplebook.
* [Toolbook](Toolbook/README.md) shows how to create a Toolbook widget with wxToolbook.
* [Treebook](Treebook/README.md) shows how to create a Treebook widget with wxTreebook.

## Build and run

To build this project, open "Terminal" and type following lines:

### Windows
``` shell
mkdir build && cd build
cmake ..
start BookControls.sln
```

Select any project and type Ctrl+F5 to build and run it.

### macOS :

``` shell
mkdir build && cd build
cmake .. -G "Xcode"
open ./BookControls.xcodeproj
```

Select any project and type Cmd+R to build and run it.

### Linux with Code::Blocks :

``` shell
mkdir build
cd build
cmake .. -G "CodeBlocks - Unix Makefiles"
xdg-open ./BookControls.cbp > /dev/null 2>&1
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
