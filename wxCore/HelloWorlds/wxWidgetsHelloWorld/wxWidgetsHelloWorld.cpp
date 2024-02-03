#include <wx/wx.h>

namespace wxWidgetsHelloWorldExample {
  class Frame : public wxFrame {
  public:
    Frame(): wxFrame(nullptr, wxID_ANY, "Hello World") {
      auto menuFile = new wxMenu();
      menuFile->Append(ID_HELLO, "&Hello...\tCtrl-H", "Help string shown in status bar for this menu item");
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

      Bind(wxEVT_MENU, &Frame::OnHello, this, ID_HELLO);
      Bind(wxEVT_MENU, &Frame::OnAbout, this, wxID_ABOUT);
      Bind(wxEVT_MENU, &Frame::OnExit, this, wxID_EXIT);
    }
    
  private:
    void OnAbout(wxCommandEvent& event) {
      wxMessageBox("This is a wxWidgets Hello World example", "About Hello World", wxOK | wxICON_INFORMATION);
    }
    
    void OnExit(wxCommandEvent& event) {
      Close(true);
    }
    
    void OnHello(wxCommandEvent& event) {
      wxLogMessage("Hello world from wxWidgets!");
    }
    
    inline static const int ID_HELLO = 1;
  };

  class Application : public wxApp {
    bool OnInit() override {return (new Frame)->Show();}
  };
}

wxIMPLEMENT_APP(wxWidgetsHelloWorldExample::Application);
