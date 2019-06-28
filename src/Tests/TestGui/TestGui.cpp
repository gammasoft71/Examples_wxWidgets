#include <wx/wx.h>

class Form : public wxFrame {
public:
  Form() : wxFrame(nullptr, wxID_ANY, "Test gui", wxDefaultPosition, wxSize(300, 300)) {
  }

private:
  wxPanel* panel = new wxPanel(this);
};

class Application : public wxApp {
  bool OnInit() override {return (new Form())->Show();}
};

wxIMPLEMENT_APP(Application);
