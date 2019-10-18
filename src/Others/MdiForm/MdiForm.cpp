#include <iostream>
#include <wx/wx.h>
#include <wx/richtext/richtextctrl.h>

class MdiChildForm : public wxMDIChildFrame {
public:
  MdiChildForm(wxMDIParentFrame* parent) : wxMDIChildFrame(parent, wxID_ANY, wxEmptyString, wxDefaultPosition, {300, 300}) {
    std::cout << "location [x=" << ctrl->GetPosition().x <<  ", y=" << ctrl->GetPosition().y << "]" << std::endl;
  }
  
private:
  wxRichTextCtrl* richTextBox = new wxRichTextCtrl(this);
  wxControl* ctrl = new wxControl(this, wxID_ANY);
};

class MdiParentForm : public wxMDIParentFrame {
public:
  MdiParentForm() : wxMDIParentFrame(nullptr, wxID_ANY, "Mdi example", wxDefaultPosition, wxSize(800, 600)) {
    menuFile->Append(wxID_NEW, "New\tCtrl+N");
    menuFile->Append(wxID_CLOSE, "Close\tCtrl+W");
    menuFile->AppendSeparator();
    menuFile->Append(wxID_EXIT, "Quit\tAlt+F4");
    
    mainMenu->Append(menuFile, "&File");
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
    MdiChildForm* child = new MdiChildForm(this);
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
  bool OnInit() override {(new MdiParentForm())->Show(); return true;}
};

wxIMPLEMENT_APP(Application);
