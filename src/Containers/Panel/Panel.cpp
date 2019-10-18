#include <wx/wx.h>

class Form : public wxFrame {
public:
  Form() : wxFrame(nullptr, wxID_ANY, "Panel example", wxDefaultPosition) {
    SetClientSize(wxSize(640, 480));
  }
  
private:
  wxPanel* panel = new wxPanel(this);
  wxPanel* panel1 = new wxPanel(panel, wxID_ANY, wxPoint(10, 10), wxSize(305, 460), wxBORDER_SIMPLE);
  wxPanel* panel2 = new wxPanel(panel, wxID_ANY, wxPoint(325, 10), wxSize(305, 460), wxBORDER_THEME);
};

class Application : public wxApp {
  bool OnInit() override {(new Form())->Show(); return true;}
};

wxIMPLEMENT_APP(Application);
