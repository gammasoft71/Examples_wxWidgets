#include <wx/wx.h>

class Frame : public wxFrame {
public:
  Frame() : wxFrame(nullptr, wxID_ANY, "Click anywhere on the form", wxDefaultPosition, wxSize(300, 300)) {
    panel->Bind(wxEVT_LEFT_UP, [&](wxMouseEvent& event) {
      wxMessageBox("The form is clicked", "FormClick", wxOK) ;
    });
  }
  
private:
  wxPanel* panel = new wxPanel(this);
};

class Application : public wxApp {
  bool OnInit() override {(new Frame())->Show(); return true;}
};

wxIMPLEMENT_APP(Application);
