#include <wx/wx.h>
#include <wx/artprov.h>
#include <map>

namespace Examples {
  enum wxOwnedID {
    wxID_OPENRECENT = 2,
    wxID_SHOW,
    wxID_HIDE,
  };

  class Frame : public wxFrame {
  public:
    Frame() : wxFrame(nullptr, wxID_ANY, "MainMenu example", wxDefaultPosition) {
      SetClientSize(300, 300);
      
      auto menuItemFileNew = menuFile->Append(wxID_NEW, "New\tCtrl+N");
      menuItemFileNew->SetBitmap(wxArtProvider::GetBitmap(wxART_NEW));
      auto menuItemFileOpen = menuFile->Append(wxID_OPEN, "Open...\tCtrl+o");
      menuItemFileOpen->SetBitmap(wxArtProvider::GetBitmap(wxART_FILE_OPEN));
      menuFile->Append(wxID_OPENRECENT, "Open recent");
      menuFile->Append(wxID_CLOSE, "Close\tCtrl+W");
      menuFile->AppendSeparator();
      auto menuItemFileSave = menuFile->Append(wxID_SAVE, "Save\tCtrl+s");
      menuItemFileSave->SetBitmap(wxArtProvider::GetBitmap(wxART_FILE_SAVE));
      auto menuItemFileSaveAs = menuFile->Append(wxID_SAVEAS, "Save as...");
      menuItemFileSaveAs->SetBitmap(wxArtProvider::GetBitmap(wxART_FILE_SAVE_AS));
      menuFile->AppendSeparator();
      auto menuItemFileQuit = menuFile->Append(wxID_EXIT, "Quit\tAlt+F4");
      menuItemFileQuit->SetBitmap(wxArtProvider::GetBitmap(wxART_QUIT));

      auto menuItemEditUndo = menuEdit->Append(wxID_UNDO, "Undo\tCtrl+z");
      menuItemEditUndo->SetBitmap(wxArtProvider::GetBitmap(wxART_UNDO));
      auto menuItemEditRedo = menuEdit->Append(wxID_REDO, "Redo\tCtrl+y");
      menuItemEditRedo->SetBitmap(wxArtProvider::GetBitmap(wxART_REDO));
      menuEdit->AppendSeparator();
      auto menuItemEditCut = menuEdit->Append(wxID_CUT, "Cut\tCtrl+x");
      menuItemEditCut->SetBitmap(wxArtProvider::GetBitmap(wxART_CUT));
      auto menuItemEditCopy = menuEdit->Append(wxID_COPY, "Copy\tCtrl+c");
      menuItemEditCopy->SetBitmap(wxArtProvider::GetBitmap(wxART_COPY));
      auto menuItemEditPaste = menuEdit->Append(wxID_PASTE, "Paste\tCtrl+v");
      menuItemEditPaste->SetBitmap(wxArtProvider::GetBitmap(wxART_PASTE));
      menuEdit->AppendSeparator();
      menuEdit->Append(wxID_SELECTALL, "Select All\tCtrl+a");

      menuView->Append(wxID_SHOW, "Show");
      menuView->Append(wxID_HIDE, "Hide");

      mainMenu->Append(menuFile, "&File");
      mainMenu->Append(menuEdit, "&Edit");
      mainMenu->Append(menuView, "&View");

  #if defined(__WXOSX__)
      mainMenu->Append(menuWindow, "&Window");
      menuWindow->Append(wxID_ABOUT, "About");
  #endif

      mainMenu->Append(menuHelp, "&Help");
  #if !defined(__WXOSX__)
      menuHelp->Append(wxID_ABOUT, "About");
  #endif

      SetMenuBar(mainMenu);

      mainMenu->Bind(wxEVT_MENU, [&](wxCommandEvent& event) {
        static std::map<int, std::string> names = {{wxID_NEW, "File/New"}, {wxID_OPEN, "File/Open..."}, {wxID_OPENRECENT, "File/Open recent"}, {wxID_CLOSE, "File/Close"}, {wxID_SAVE, "File/Save"}, {wxID_SAVEAS, "File/Save as..."}, {wxID_EXIT, "File/Quit"}, {wxID_UNDO, "Edit/Undo"}, {wxID_REDO, "Edit/Redo"}, {wxID_CUT, "Edit/Cut"}, {wxID_COPY, "Edit/Copy"}, {wxID_PASTE, "Edit/Paste"}, {wxID_SELECTALL, "Edit/Select All"}, {wxID_SHOW, "View/Show"}, {wxID_HIDE, "View/Hide"}, {wxID_ABOUT, "Help/About"}, {wxID_ANY, "Any"}};
        listBox1->Append(names.find(event.GetId()) != names.end() ? names[event.GetId()] : "Unknown");
        if (event.GetId() == wxID_EXIT) Close();
      });
    }

  private:
    wxPanel* panel = new wxPanel(this);
    wxMenuBar* mainMenu = new wxMenuBar();
    wxMenu* menuFile = new wxMenu();
    wxMenu* menuEdit = new wxMenu();
    wxMenu* menuView = new wxMenu();
    wxMenu* menuWindow = new wxMenu();
    wxMenu* menuHelp = new wxMenu();
    wxListBox* listBox1 = new wxListBox(panel, wxID_ANY, {10, 10}, {280, 260});
  };

  class Application : public wxApp {
    bool OnInit() override {
      (new Frame())->Show();
      return true;
    }
  };
}

wxIMPLEMENT_APP(Examples::Application);
