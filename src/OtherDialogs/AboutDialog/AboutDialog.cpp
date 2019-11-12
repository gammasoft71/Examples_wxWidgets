#include <wx/wx.h>
#include <wx/aboutdlg.h>

class Frame : public wxFrame {
public:
  Frame() : wxFrame(nullptr, wxID_ANY, "AboutBox example", wxDefaultPosition, wxSize(300, 300)) {
    button->Bind(wxEVT_BUTTON, [](wxCommandEvent& event) {
      wxAboutDialogInfo aboutInfo;
      aboutInfo.SetName(wxTheApp->GetAppName());
      aboutInfo.SetDescription(L"AboutBox example demonstrates how to use wxAboutBox.");
      aboutInfo.SetVersion(L"1.0", L"1.0.0");
      aboutInfo.SetCopyright(L"Copyright © Gammasoft 219");
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
