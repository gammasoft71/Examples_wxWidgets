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
        aboutInfo.SetDescription("About dialog description.");
        aboutInfo.SetVersion("1.0", "1.0.0");
        aboutInfo.SetCopyright(u8"Copyright \u00A9 2019 Gammasoft.\nAll rights reserved.");
#if defined (__WXGTK__)
        aboutInfo.SetIcon({gammasoft_64x64_xpm});
        aboutInfo.SetWebSite(u8"https://gammasoft71.wixsite.com/gammasoft");
#endif
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
