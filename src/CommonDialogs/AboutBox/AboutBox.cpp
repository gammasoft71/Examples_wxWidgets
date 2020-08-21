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
        if (wxPlatformInfo::Get().GetOperatingSystemFamilyName() != "Macintosh") {
          aboutInfo.AddArtist("Gammasoft");
          aboutInfo.AddDeveloper("Gammasoft");
          aboutInfo.AddDeveloper("Contributors");
          aboutInfo.AddDocWriter("Gammasoft");
        }
        aboutInfo.SetCopyright("Copyright (c) 2019 Gammasoft.\nAll rights reserved.");
        if (wxPlatformInfo::Get().GetOperatingSystemFamilyName() == "Unix") {
          aboutInfo.SetIcon({gammasoft_64x64_xpm});
          aboutInfo.SetWebSite("https://gammasoft71.wixsite.com/gammasoft");
          aboutInfo.SetLicence("MIT License\n"
                               "\n"
                               "Copyright (c) 2019 Gammasoft.\n"
                               "\n"
                               "Permission is hereby granted, free of charge, to any person obtaining\n"
                               "a copy of this software and associated documentation files (the\n"
                               "\"Software\"), to deal in the Software without restriction, including\n"
                               "without limitation the rights to use, copy, modify, merge, publish,\n"
                               "distribute, sublicense, and/or sell copies of the Software, and to\n"
                               "permit persons to whom the Software is furnished to do so, subject\n"
                               "to the following conditions:\n"
                               "\n"
                               "The above copyright notice and this permission notice shall be\n"
                               "included in all copies or substantial portions of the Software.\n"
                               "\n"
                               "THE SOFTWARE IS PROVIDED \"AS IS\", WITHOUT WARRANTY OF\n"
                               "ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO\n"
                               "THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A\n"
                               "PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT\n"
                               "SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR\n"
                               "ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN\n"
                               "ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,\n"
                               "OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE\n"
                               "OR OTHER DEALINGS IN THE SOFTWARE."
                               );
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
