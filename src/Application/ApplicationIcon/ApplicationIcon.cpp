#include <wx/wx.h>

class Application : public wxApp {
  bool OnInit() override {
    wxFrame* frame = new wxFrame(nullptr, wxID_ANY, wxEmptyString);
    wxImage::AddHandler(new wxPNGHandler());
    frame->SetIcon(wxIcon("Resources/Gammasoft.png", wxBITMAP_TYPE_PNG));
    return frame->Show();
  }
};

wxIMPLEMENT_APP(Application);
