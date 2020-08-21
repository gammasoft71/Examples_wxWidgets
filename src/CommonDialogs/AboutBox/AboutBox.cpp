#include <wx/wx.h>
#include <wx/aboutdlg.h>
#include "gammasoft_64x64.xpm"

namespace Examples {
  class Frame : public wxFrame {
  public:
    Frame() : wxFrame(nullptr, wxID_ANY, "AboutBox example", wxDefaultPosition, {300, 300}) {
      button->Bind(wxEVT_BUTTON, [](wxCommandEvent& event) {
        wxAboutDialogInfo aboutInfo;
        aboutInfo.SetName(wxTheApp->GetAppName());
        aboutInfo.SetVersion("1.0", "1.0.0");
        aboutInfo.SetDescription("About dialog description.");
        aboutInfo.AddArtist("Gammasoft");
        aboutInfo.AddDeveloper("Gammasoft");
        aboutInfo.AddDeveloper("Contributors");
        aboutInfo.AddDocWriter("Gammasoft");
        aboutInfo.SetCopyright("Copyright (c) 2019 Gammasoft.\nAll rights reserved.");
        if (wxPlatformInfo::Get().GetOperatingSystemFamilyName() == "Unix") {
          aboutInfo.SetIcon({gammasoft_64x64_xpm});
          aboutInfo.SetWebSite("https://gammasoft71.wixsite.com/gammasoft");
          aboutInfo.SetLicence("MIT");
        }
        wxAboutBox(aboutInfo);
      });
    }
    
  private:
    wxPanel* panel = new wxPanel(this);
    wxButton* button = new wxButton(panel, wxID_ABOUT, wxEmptyString, {10, 10});
  };

  class Application : public wxApp {
    bool OnInit() override {
      (new Frame())->Show();
      return true;
    }
  };
}

wxIMPLEMENT_APP(Examples::Application);
