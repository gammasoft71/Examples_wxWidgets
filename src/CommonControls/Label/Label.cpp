#include <wx/wx.h>

class Form : public wxFrame {
public:
  Form() : wxFrame(nullptr, wxID_ANY, "Label example", wxDefaultPosition, wxSize(300, 300)) {}
  
private:
  wxPanel* panel = new wxPanel(this);
  wxStaticText* label1 = new wxStaticText(panel, wxID_ANY, "label1", wxPoint(10, 10));
};

class Application : public wxApp {
  bool OnInit() override {(new Form())->Show(); return true;}
};

wxIMPLEMENT_APP(Application);
