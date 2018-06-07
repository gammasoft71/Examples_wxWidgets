#include <wx/wx.h>

class Form : public wxFrame {
public:
  Form() : wxFrame(nullptr, wxID_ANY, "My first application", wxDefaultPosition, wxSize(300, 300)) {
    this->label1->SetFont(wxFont(45, wxFONTFAMILY_DEFAULT, wxFONTSTYLE_ITALIC, wxFONTWEIGHT_BOLD, false, "Arial"));
    this->label1->SetForegroundColour(wxColourDatabase().Find("FOREST GREEN"));

    this->CenterOnScreen();
    this->Show();
  }
  
private:
  wxPanel* panel = new wxPanel(this);
  wxStaticText* label1 = new wxStaticText(this->panel, wxID_ANY, "Hello, World!", wxPoint(10, 100));
};

class Application : public wxApp {
public:
  bool OnInit() override {new Form(); return true;}
};

wxIMPLEMENT_APP(Application);
