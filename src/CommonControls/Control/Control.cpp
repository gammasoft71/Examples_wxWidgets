#include <wx/wx.h>

class Form : public wxFrame {
public:
  Form() : wxFrame(nullptr, wxID_ANY, "Control example", wxDefaultPosition, wxSize(300, 300)) {
    control1->SetBackgroundColour(wxTheColourDatabase->Find("Spring Green"));
  }
  
private:
  wxPanel* panel = new wxPanel(this);
  wxControl* control1 = new wxControl(panel, wxID_ANY, wxPoint(50, 50), wxSize(100, 50));
};

class Application : public wxApp {
  bool OnInit() override {(new Form())->Show(); return true;}
};

wxIMPLEMENT_APP(Application);
