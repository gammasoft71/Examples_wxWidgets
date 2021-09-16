#include <wx/wx.h>

namespace Examples {
  // Workaround : with wxWidgets version <= 3.1.4 font is in pixels and not in points on macOS
  int PointsToNativeFontGraphicsUntit(int size) {
    return wxPlatformInfo::Get().GetOperatingSystemFamilyName() != "Macintosh" ? size : static_cast<float>(size) / wxScreenDC().GetPPI().GetHeight() * 96.0f;
  }

  class Frame : public wxFrame {
  public:
    Frame() : wxFrame(nullptr, wxID_ANY, "Hello world (emoticons)") {
      staticText1->SetFont({PointsToNativeFontGraphicsUntit(72), wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL});
      SetClientSize(staticText1->GetSize());
    }
    
  private:
    wxPanel* panel = new wxPanel(this);
    wxStaticText* staticText1 = new wxStaticText(panel, wxID_ANY, L"\U0001F44B, \U0001F30E\U00002757");
  };

  class Application : public wxApp {
    bool OnInit() override {
      (new Frame())->Show();
      return true;
    }
  };
}

wxIMPLEMENT_APP(Examples::Application);
