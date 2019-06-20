#include <wx/wx.h>

class Form : public wxFrame {
public:
  Form() : wxFrame(nullptr, wxID_ANY, "Click anywhere on the form", wxDefaultPosition, wxSize(300, 300)) {
    this->panel->Bind(wxEVT_LEFT_UP, [&](wxMouseEvent& event) {
      wxMessageBox("The form is clicked", "FormClick", wxOK) ;
    });
    
    this->Show();
  }
  
private:
  wxPanel* panel = new wxPanel(this);
};

class Application : public wxApp {
public:
  bool OnInit() override {new Form(); return true;}
};

wxIMPLEMENT_APP(Application);
