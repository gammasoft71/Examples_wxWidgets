#include <wx/wx.h>

class Form : public wxFrame {
public:
  Form() : wxFrame(nullptr, wxID_ANY, "Form example", wxDefaultPosition, wxSize(640, 480)) {
    this->button->Bind(wxEVT_BUTTON, [&](wxCommandEvent& event) {
      this->Close();
    });
    
    this->Bind(wxEVT_CLOSE_WINDOW, [&](wxCloseEvent& event) {
      if ( event.CanVeto()) {
        if (wxMessageBox("Are you sure you want exit?", "Close Form", wxICON_QUESTION | wxYES_NO) == wxYES) {
          this->wxFrame::OnCloseWindow(event);
          return;
        }
        event.Veto();
      }
    });
    
    this->Show();
  }
  
private:
  wxPanel* panel = new wxPanel(this);
  wxButton* button = new wxButton(panel, wxID_ANY, "Close", wxPoint(10, 10));
};

class Application : public wxApp {
public:
  bool OnInit() override {new Form(); return true;}
};

wxIMPLEMENT_APP(Application);
