#include <wx/wx.h>

class Form : public wxFrame {
public:
  Form() : wxFrame(nullptr, wxID_ANY, "Panel example", wxDefaultPosition) {
    this->SetClientSize(wxSize(640, 480));
    this->panel1.SetWindowStyle(wxBORDER_SIMPLE);
    this->panel2.SetWindowStyle(wxBORDER_SUNKEN);
  }
  
private:
  wxPanel panel {this};
  wxPanel panel1 {&this->panel, wxID_ANY, wxPoint(10, 10), wxSize(305, 460)};
  wxPanel panel2 {&this->panel, wxID_ANY, wxPoint(325, 10), wxSize(305, 460)};
};

class Application : public wxApp {
  bool OnInit() override {return (new Form())->Show();}
};

wxIMPLEMENT_APP(Application);
