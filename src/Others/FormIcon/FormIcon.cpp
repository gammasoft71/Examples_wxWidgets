#include <wx/wx.h>
#include "Gammasoft.xpm"

class Application : public wxApp {
  bool OnInit() override {
    wxFrame* frame = new wxFrame(nullptr, wxID_ANY, "Form Icon example");
    frame->SetIcon(wxIcon(GammasoftIcon_xpm));
    return frame->Show();
  }
};

wxIMPLEMENT_APP(Application);
