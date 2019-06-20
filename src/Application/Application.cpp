#include <wx/wx.h>

class Application : public wxApp {
public:
  bool OnInit() override {(new wxFrame(nullptr, wxID_ANY, wxEmptyString))->Show(); return true;}
};

wxIMPLEMENT_APP(Application);
