#include <wx/wx.h>
#include <wx/aboutdlg.h>

class Frame : public wxFrame {
  #include "Gammasoft.xpm"
public:
  Frame() : wxFrame(nullptr, wxID_ANY, "About example", wxDefaultPosition, wxSize(300, 300)) {
    SetIcon(gammasoft_32x32);
    button->Bind(wxEVT_BUTTON, [](wxCommandEvent& event) {
      wxAboutDialogInfo aboutInfo;
      aboutInfo.SetName(wxTheApp->GetAppName());
      aboutInfo.SetDescription("AboutBox example demonstrates how to use wxAboutBox.");
      aboutInfo.SetVersion("1.0", "1.0.0");
      aboutInfo.SetCopyright("Copyright © Gammasoft 219");
      wxAboutBox(aboutInfo);
    });
  }
  
private:
  wxPanel* panel = new wxPanel(this);
  wxButton* button = new wxButton(panel, wxID_ANY, "About...", wxPoint(10, 10));
};

class Application : public wxApp {
  bool OnInit() override {(new Frame())->Show(); return true;}
};

wxIMPLEMENT_APP(Application);
