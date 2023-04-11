#include <iostream>
#include <wx/wx.h>
#include <wx/richtext/richtextctrl.h>

namespace MdiFrameExample {
  class MdiChildFrame : public wxMDIChildFrame {
  public:
    MdiChildFrame(wxMDIParentFrame* parent) : wxMDIChildFrame(parent, wxID_ANY, wxEmptyString) {
    }
    
  private:
    wxRichTextCtrl* richTextBox = new wxRichTextCtrl(this);
  };

  class MdiParentFrame : public wxMDIParentFrame {
  public:
    MdiParentFrame() : wxMDIParentFrame(nullptr, wxID_ANY, "Mdi example") {
      //SetWindowMenu(nullptr);
      menuFile->Append(wxID_NEW, "New\tCtrl+N");
      menuFile->Append(wxID_CLOSE, "Close\tCtrl+W");
      menuFile->AppendSeparator();
      menuFile->Append(wxID_EXIT, "Quit\tAlt+F4");
      
      mainMenu->Append(menuFile, "&File");
#if (__APPLE__)
      mainMenu->Append(new wxMenu, "&View");
#endif
      mainMenu->Bind(wxEVT_MENU, [&](wxCommandEvent& event) {
        switch (event.GetId()) {
          case wxID_NEW: OnMenuFileNewClick(event); break;
          case wxID_CLOSE: OnMenuFileCloseClick(event); break;
          case wxID_EXIT: OnMenuFileQuitClick(event); break;
          default: break;
        }
      });

      SetMenuBar(mainMenu);
    }
    
  private:
    void OnMenuFileNewClick(wxCommandEvent& event) {
      auto child = new MdiChildFrame(this);
      child->SetLabel(wxString::Format("Child %d", ++childCounter));
      child->Show();
    }
    
    void OnMenuFileCloseClick(wxCommandEvent& event) {
      if (GetActiveChild())
        GetActiveChild()->Close();
    }
    
    void OnMenuFileQuitClick(wxCommandEvent& event) {
      Close();
    }
    
    wxMenuBar* mainMenu = new wxMenuBar();
    wxMenu* menuFile = new wxMenu();
    int childCounter = 0;
  };

  class Application : public wxApp {
    bool OnInit() override {
      (new MdiParentFrame())->Show();
      return true;
    }
  };
}

wxIMPLEMENT_APP(MdiFrameExample::Application);
