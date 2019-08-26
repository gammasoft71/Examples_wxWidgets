#include <wx/wx.h>

class Form : public wxFrame {
public:
  Form() : wxFrame(nullptr, wxID_ANY, "Panel example", wxDefaultPosition) {
    this->SetClientSize(wxSize(640, 480));
  }
  
private:
  wxPanel* panel = new wxPanel(this);
  wxPanel* panel1 = new wxPanel(this->panel, wxID_ANY, wxPoint(10, 10), wxSize(305, 460), wxBORDER_SIMPLE);
  wxPanel* panel2 = new wxPanel(this->panel, wxID_ANY, wxPoint(325, 10), wxSize(305, 460), wxBORDER_THEME);
};

class Application : public wxApp {
  bool OnInit() override {return (new Form())->Show();}
};

wxIMPLEMENT_APP(Application);
