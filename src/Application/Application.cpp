#include <wx/wx.h>

class Application : public wxApp {
public:
  bool OnInit() override {(new wxFrame(nullptr, wxID_ANY, ""))->Show(); return true;}
};

wxIMPLEMENT_APP(Application);
