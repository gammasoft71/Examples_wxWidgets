#include <wx/wx.h>
#include <wx/richtext/richtextctrl.h>

class MdiChildForm : public wxMDIChildFrame {
public:
  MdiChildForm(wxMDIParentFrame* parent) : wxMDIChildFrame(parent, wxID_ANY, wxEmptyString, wxDefaultPosition, {300, 300}) {}
  
private:
  wxRichTextCtrl* richTextBox = new wxRichTextCtrl(this);
};

class MdiParentForm : public wxMDIParentFrame {
public:
  MdiParentForm() : wxMDIParentFrame(nullptr, wxID_ANY, "MDI example", wxDefaultPosition, wxSize(800, 600)) {
    this->menuFile->Append(wxID_NEW, "New\tCtrl+N");
    this->menuFile->Append(wxID_CLOSE, "Close\tCtrl+W");
    this->menuFile->AppendSeparator();
    this->menuFile->Append(wxID_EXIT, "Quit\tAlt+F4");
    
    this->mainMenu->Append(this->menuFile, "&File");
    this->mainMenu->Bind(wxEVT_MENU, [&](wxCommandEvent& event) {
      switch (event.GetId()) {
        case wxID_NEW: this->OnMenuFileNewClick(event); break;
        case wxID_CLOSE: this->OnMenuFileCloseClick(event); break;
        case wxID_EXIT: this->OnMenuFileQuitClick(event); break;
        default: break;
      }
    });

    this->SetMenuBar(this->mainMenu);
  }
  
private:
  void OnMenuFileNewClick(wxCommandEvent& event) {
    MdiChildForm* child = new MdiChildForm(this);
    child->SetLabel(wxString::Format("Child %d", ++this->childCounter));
    child->Show();
  }
  
  void OnMenuFileCloseClick(wxCommandEvent& event) {
    if (this->GetActiveChild())
      this->GetActiveChild()->Close();
  }
  
  void OnMenuFileQuitClick(wxCommandEvent& event) {
    this->Close();
  }
  
  wxMenuBar* mainMenu = new wxMenuBar();
  wxMenu* menuFile = new wxMenu();
  int childCounter = 0;
};

class Application : public wxApp {
  bool OnInit() override {return (new MdiParentForm())->Show();}
};

wxIMPLEMENT_APP(Application);
