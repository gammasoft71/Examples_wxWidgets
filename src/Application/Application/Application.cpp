#include <wx/wx.h>

class Application : public wxApp {
  bool OnInit() override {return (new wxFrame(nullptr, wxID_ANY, wxEmptyString))->Show();}
};

wxIMPLEMENT_APP(Application);
