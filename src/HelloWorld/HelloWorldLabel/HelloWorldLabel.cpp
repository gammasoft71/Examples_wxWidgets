#include <wx/wx.h>

namespace Examples {
  // Workaround : with wxWidgets version <= 3.1.4 font is in pixels and not in points on macOS
  int PointsToNativeFontGraphicsUntit(int size) {
    return wxPlatformInfo::Get().GetOperatingSystemFamilyName() != "Macintosh" ? size : static_cast<float>(size) / wxScreenDC().GetPPI().GetHeight() * 96.0f;
  }
  
  class Frame : public wxFrame {
  public:
    Frame() : wxFrame(nullptr, wxID_ANY, "Hello world (label)") {
      SetClientSize(300, 300);
      staticText1->SetFont({PointsToNativeFontGraphicsUntit(32), wxFONTFAMILY_DEFAULT, wxFONTSTYLE_ITALIC, wxFONTWEIGHT_BOLD});
      staticText1->SetForegroundColour(wxTheColourDatabase->Find("Forest Green"));
    }
    
  private:
    wxPanel* panel = new wxPanel(this);
    wxStaticText* staticText1 = new wxStaticText(panel, wxID_ANY, "Hello, World!", {5, 100});
  };

  class Application : public wxApp {
    bool OnInit() override {
      (new Frame())->Show();
      return true;
    }
  };
}

wxIMPLEMENT_APP(Examples::Application);
