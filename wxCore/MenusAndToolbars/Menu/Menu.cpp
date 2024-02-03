#include <map>
#include <string>
#include <wx/app.h>
#include <wx/artprov.h>
#include <wx/frame.h>
#include <wx/listbox.h>
#include <wx/menu.h>

namespace MenuExample {
  class Frame : public wxFrame {
  public:
    Frame() : wxFrame {nullptr, wxID_ANY, "Menu example"} {
      listBox1->Append("Right click to show menu");
      listBox1->Bind(wxEVT_RIGHT_DOWN, [&](wxMouseEvent& event) {
        listBox1->PopupMenu(contextualMenu);
      });
      
      auto menuFile = new wxMenu;
      auto menuItemFileNew = menuFile->Append(wxID_NEW);
      menuItemFileNew->SetBitmap(wxArtProvider::GetBitmap(wxART_NEW, wxART_MENU));
      auto menuItemFileOpen = menuFile->Append(wxID_OPEN);
      menuItemFileOpen->SetBitmap(wxArtProvider::GetBitmap(wxART_FILE_OPEN, wxART_MENU));
      auto menuFileOpenRecent = new wxMenu();
      menuFileOpenRecent->Append(ID_OPENRECENTFILE1, "File 1");
      menuFileOpenRecent->Append(ID_OPENRECENTFILE2, "File 2");
      menuFileOpenRecent->Append(ID_OPENRECENTFILE3, "File 3");
      menuFileOpenRecent->Append(ID_OPENRECENTFILE4, "File 4");
      menuFileOpenRecent->Append(ID_OPENRECENTFILE5, "File 5");
      auto menuItemFileOpenRecent = menuFile->AppendSubMenu(menuFileOpenRecent, "Open &recent");
      menuItemFileOpenRecent->SetSubMenu(menuFileOpenRecent);
      menuFile->Append(wxID_CLOSE, "&Close\tCtrl+W");
      menuFile->AppendSeparator();
      auto menuItemFileSave = menuFile->Append(wxID_SAVE);
      menuItemFileSave->SetBitmap(wxArtProvider::GetBitmap(wxART_FILE_SAVE, wxART_MENU));
      auto menuItemFileSaveAs = menuFile->Append(wxID_SAVEAS);
      menuItemFileSaveAs->SetBitmap(wxArtProvider::GetBitmap(wxART_FILE_SAVE_AS, wxART_MENU));
      menuFile->AppendSeparator();
      menuFile->Append(wxID_PAGE_SETUP, "Page Setup...\tCtrl+Shift+P");
      auto menuItemFilePrint = menuFile->Append(wxID_PRINT);
      menuItemFilePrint->SetBitmap(wxArtProvider::GetBitmap(wxART_PRINT, wxART_MENU));
      menuFile->AppendSeparator();
      auto menuItemFileQuit = menuFile->Append(ID_EXIT, "&Exit");
      menuItemFileQuit->SetBitmap(wxArtProvider::GetBitmap(wxART_QUIT, wxART_MENU));
      
      auto menuEdit = new wxMenu;
      auto menuItemEditUndo = menuEdit->Append(wxID_UNDO);
      menuItemEditUndo->SetBitmap(wxArtProvider::GetBitmap(wxART_UNDO, wxART_MENU));
      auto menuItemEditRedo = menuEdit->Append(wxID_REDO);
      menuItemEditRedo->SetBitmap(wxArtProvider::GetBitmap(wxART_REDO, wxART_MENU));
      menuEdit->AppendSeparator();
      auto menuItemEditCut = menuEdit->Append(wxID_CUT);
      menuItemEditCut->SetBitmap(wxArtProvider::GetBitmap(wxART_CUT, wxART_MENU));
      auto menuItemEditCopy = menuEdit->Append(wxID_COPY);
      menuItemEditCopy->SetBitmap(wxArtProvider::GetBitmap(wxART_COPY, wxART_MENU));
      auto menuItemEditPaste = menuEdit->Append(wxID_PASTE);
      menuItemEditPaste->SetBitmap(wxArtProvider::GetBitmap(wxART_PASTE, wxART_MENU));
      menuEdit->AppendSeparator();
      menuEdit->Append(wxID_SELECTALL);
      menuEdit->AppendSeparator();
      menuEdit->Append(wxID_PREFERENCES, "&Settings...\tCtrl+,");
      
      auto menuView = new wxMenu;
      auto menuItemViewBackward = menuView->Append(wxID_BACKWARD);
      menuItemViewBackward->SetBitmap(wxArtProvider::GetBitmap(wxART_GO_BACK, wxART_MENU));
      auto menuItemViewForward = menuView->Append(wxID_FORWARD);
      menuItemViewForward->SetBitmap(wxArtProvider::GetBitmap(wxART_GO_FORWARD, wxART_MENU));
      menuView->AppendSeparator();
      menuView->Append(ID_SHOW, "Show");
      menuView->Append(ID_HIDE, "Hide");
      
      auto menuOptions = new wxMenu();
      menuOptions->Append(ID_OPTIONA, "Option A\tAlt+1", "", wxITEM_CHECK);
      menuOptions->Append(ID_OPTIONB, "Option B\tAlt+2", "", wxITEM_CHECK);
      menuOptions->Append(ID_OPTIONC, "Option C\tAlt+3", "", wxITEM_CHECK);
      menuOptions->AppendSeparator();
      menuOptions->Append(ID_OPTIOND, "Option D\tAlt+4", "", wxITEM_RADIO);
      menuOptions->Append(ID_OPTIONE, "Option E\tAlt+5", "", wxITEM_RADIO);
      menuOptions->Append(ID_OPTIONF, "Option F\tAlt+6", "", wxITEM_RADIO);
      menuOptions->AppendSeparator();
      menuOptions->Append(ID_OPTIONG, "Option G\tAlt+7", "", wxITEM_RADIO);
      menuOptions->Append(ID_OPTIONH, "Option H\tAlt+8", "", wxITEM_RADIO);
      menuOptions->Append(ID_OPTIONI, "Option I\tAlt+9", "", wxITEM_RADIO);
      
      menuOptions->Check(ID_OPTIONA, true);
      menuOptions->Check(ID_OPTIONC, true);
      menuOptions->Check(ID_OPTIONE, true);
      menuOptions->Check(ID_OPTIONI, true);
      
      auto menuHelp = new wxMenu;
      menuHelp->Append(wxID_HELP_CONTEXT, "Context");
      menuHelp->Append(wxID_HELP_INDEX, "Index");
      menuHelp->Append(wxID_HELP_SEARCH, "Search");
      menuHelp->AppendSeparator();
      menuHelp->Append(ID_ABOUT, "About");
      
      contextualMenu->AppendSubMenu(menuFile, "&File");
      contextualMenu->AppendSubMenu(menuEdit, "&Edit");
      contextualMenu->AppendSubMenu(menuView, "&View");
      contextualMenu->AppendSubMenu(menuOptions, "&Options");
      contextualMenu->AppendSubMenu(menuHelp, "&Help");

      contextualMenu->Bind(wxEVT_MENU, [&](wxCommandEvent& event) {
        static auto names = std::map<int, std::string> {{wxID_NEW, "File/New"}, {wxID_OPEN, "File/Open..."}, {ID_OPENRECENTFILE1, "File/Open recent/File 1"}, {ID_OPENRECENTFILE2, "File/Open recent/File 2"}, {ID_OPENRECENTFILE3, "File/Open recent/File 3"}, {ID_OPENRECENTFILE4, "File/Open recent/File 4"}, {ID_OPENRECENTFILE5, "File/Open recent/File 5"}, {wxID_CLOSE, "File/Close"}, {wxID_SAVE, "File/Save"}, {wxID_SAVEAS, "File/Save as..."}, {wxID_PAGE_SETUP, "File/Page setup..."}, {wxID_PRINT, "File/Print..."}, {ID_EXIT, "File/Quit"}, {wxID_UNDO, "Edit/Undo"}, {wxID_REDO, "Edit/Redo"}, {wxID_CUT, "Edit/Cut"}, {wxID_COPY, "Edit/Copy"}, {wxID_PASTE, "Edit/Paste"}, {wxID_SELECTALL, "Edit/Select All"}, {wxID_PREFERENCES, "Edit/Settings..."}, {wxID_BACKWARD, "View/Back"}, {wxID_FORWARD, "View/Forward"}, {ID_SHOW, "View/Show"}, {ID_HIDE, "View/Hide"}, {ID_OPTIONA, "Options/Option A"}, {ID_OPTIONB, "Options/Option B"}, {ID_OPTIONC, "Options/Option C"}, {ID_OPTIOND, "Options/Option D"}, {ID_OPTIONE, "Options/Option E"}, {ID_OPTIONF, "Options/Option F"}, {ID_OPTIONG, "Options/Option G"}, {ID_OPTIONH, "Options/Option H"}, {ID_OPTIONI, "Options/Option I"}, {wxID_HELP_CONTEXT, "Help/Context"}, {wxID_HELP_INDEX, "Help/Index"}, {wxID_HELP_SEARCH, "Help/Search"}, {ID_ABOUT, "Help/About"}, {wxID_ANY, "Any"}};
        listBox1->Append(names.find(event.GetId()) != names.end() ? names[event.GetId()] : "Unknown");
        event.StopPropagation();
      });
    }

  private:
    wxListBox* listBox1 = new wxListBox {this, wxID_ANY};
    wxMenu* contextualMenu = new wxMenu;
    
    inline static const int ID_OPENRECENTFILE1 = 1;
    inline static const int ID_OPENRECENTFILE2 = 2;
    inline static const int ID_OPENRECENTFILE3 = 3;
    inline static const int ID_OPENRECENTFILE4 = 4;
    inline static const int ID_OPENRECENTFILE5 = 5;
    inline static const int ID_SHOW = 6;
    inline static const int ID_HIDE = 7;
    inline static const int ID_OPTIONA = 8;
    inline static const int ID_OPTIONB = 9;
    inline static const int ID_OPTIONC = 10;
    inline static const int ID_OPTIOND = 11;
    inline static const int ID_OPTIONE = 12;
    inline static const int ID_OPTIONF = 13;
    inline static const int ID_OPTIONG = 14;
    inline static const int ID_OPTIONH = 15;
    inline static const int ID_OPTIONI = 16;
    inline static const int ID_ABOUT = 17;
    inline static const int ID_EXIT = 18;
  };

  class Application : public wxApp {
    bool OnInit() override {return (new Frame)->Show();}
  };
}

wxIMPLEMENT_APP(MenuExample::Application);
