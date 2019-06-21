#include <wx/wx.h>

class Form : public wxFrame {
public:
  Form() : wxFrame(nullptr, wxID_ANY, "Click anywhere on the form", wxDefaultPosition, wxSize(300, 300)) {
    this->Bind(wxEVT_LEFT_UP, [&](wxMouseEvent& event) {
      wxMessageBox("The form is clicked", "FormClick", wxOK) ;
    });
  }
};

class Application : public wxApp {
  bool OnInit() override {return (new Form())->Show();}
};

wxIMPLEMENT_APP(Application);
