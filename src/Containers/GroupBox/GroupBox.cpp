#include <wx/wx.h>

class Form : public wxFrame {
public:
  Form() : wxFrame(nullptr, wxID_ANY, "GroupBox example", wxDefaultPosition) {
    this->SetClientSize(wxSize(640, 480));
    this->Show();
  }
  
private:
  wxPanel panel {this};
  wxStaticBox groupBox1 {&this->panel, wxID_ANY, "GroupBox 1", wxPoint(10, 10), wxSize(305, 460)};
  wxStaticBox groupBox2 {&this->panel, wxID_ANY, wxEmptyString, wxPoint(325, 10), wxSize(305, 460)};
};

class Application : public wxApp {
  bool OnInit() override {new Form(); return true;}
};

wxIMPLEMENT_APP(Application);
