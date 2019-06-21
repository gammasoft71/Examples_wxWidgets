#include <wx/wx.h>

class Form : public wxFrame {
public:
  Form() : wxFrame(nullptr, wxID_ANY, "Label example", wxDefaultPosition, wxSize(300, 300)) {this->Show();}
  
private:
  wxPanel panel {this};
  wxStaticText label1 {&this->panel, wxID_ANY, "label1", wxPoint(10, 10)};
};

class Application : public wxApp {
  bool OnInit() override {new Form(); return true;}
};

wxIMPLEMENT_APP(Application);
