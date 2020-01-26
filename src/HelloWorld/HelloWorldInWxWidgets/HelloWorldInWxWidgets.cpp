#include <wx/wx.h>

namespace Examples {
  enum wxOwnedID {
    wxID_Hello = 1
  };

  class Frame : public wxFrame {
  public:
    Frame(): wxFrame(nullptr, wxID_ANY, "Hello World") {
      auto menuFile = new wxMenu();
      menuFile->Append(wxID_Hello, "&Hello...\tCtrl-H", "Help string shown in status bar for this menu item");
      menuFile->AppendSeparator();
      menuFile->Append(wxID_EXIT);
      auto menuHelp = new wxMenu();
      menuHelp->Append(wxID_ABOUT);
      auto menuBar = new wxMenuBar();
      menuBar->Append(menuFile, "&File");
      menuBar->Append(menuHelp, "&Help");
      SetMenuBar(menuBar);
      CreateStatusBar();
      SetStatusText("Welcome to wxWidgets!");
      Bind(wxEVT_MENU, [](wxCommandEvent& event) {
        wxLogMessage("Hello world from wxWidgets!");
      }, wxID_Hello);
      Bind(wxEVT_MENU, [](wxCommandEvent& event) {
        wxMessageBox("This is a wxWidgets Hello World example", "About Hello World", wxOK|wxICON_INFORMATION);
      }, wxID_ABOUT);
      Bind(wxEVT_MENU, [&](wxCommandEvent& event) {
        Close(true);
      }, wxID_EXIT);
    }
  };

  class Application : public wxApp {
    bool OnInit() override {
      (new Frame())->Show();
      return true;
    }
  };
}

wxIMPLEMENT_APP(Examples::Application);
