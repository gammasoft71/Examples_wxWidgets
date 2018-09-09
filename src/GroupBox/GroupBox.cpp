#include <wx/wx.h>

class Form : public wxFrame {
public:
  Form() : wxFrame(nullptr, wxID_ANY, "Panel example", wxDefaultPosition, wxSize(640, 480)) {this->Show();}
  
private:
  wxPanel* panel = new wxPanel(this);
  wxStaticBox* groupBox1 = new wxStaticBox(this->panel, wxID_ANY, "GroupBox 1", wxPoint(10, 10), wxSize(305, 440));
  wxStaticBox* groupBox2 = new wxStaticBox(this->panel, wxID_ANY, "", wxPoint(325, 10), wxSize(305, 440));
};

class Application : public wxApp {
public:
  bool OnInit() override {new Form(); return true;}
};

wxIMPLEMENT_APP(Application);
