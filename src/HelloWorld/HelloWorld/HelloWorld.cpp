#include <wx/wx.h>

class Form : public wxFrame {
public:
  Form() : wxFrame(nullptr, wxID_ANY, "My first application", wxDefaultPosition, wxSize(300, 300)) {
    this->label1.SetFont(wxFont(45, wxFONTFAMILY_DEFAULT, wxFONTSTYLE_ITALIC, wxFONTWEIGHT_BOLD, false, "Arial"));
    this->label1.SetForegroundColour(wxTheColourDatabase->Find("FOREST GREEN"));

    this->CenterOnScreen();
  }
  
private:
  wxPanel panel {this};
  wxStaticText label1 {&this->panel, wxID_ANY, "Hello, World!", wxPoint(10, 100)};
};

class Application : public wxApp {
  bool OnInit() override {return (new Form())->Show();}
};

wxIMPLEMENT_APP(Application);
