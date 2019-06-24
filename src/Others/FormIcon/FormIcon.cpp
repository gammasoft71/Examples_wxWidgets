#include <wx/wx.h>
#include "Gammasoft.xpm"

class Application : public wxApp {
  bool OnInit() override {
    wxFrame* frame = new wxFrame(nullptr, wxID_ANY, wxEmptyString);
    frame->SetIcon(wxIcon(wxICON(GammasoftIcon)));
    return frame->Show();
  }
};

wxIMPLEMENT_APP(Application);
