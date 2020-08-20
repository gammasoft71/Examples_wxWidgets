#include <wx/wx.h>

namespace Examples {
  // Workaround : with wxWidgets version <= 3.1.4 font is in pixels and not in points on macOS
  int PointsToNativeFontGraphicsUntit(int size) {
    return wxPlatformInfo::Get().GetOperatingSystemFamilyName() != "Macintosh" ? size : static_cast<float>(size) / wxScreenDC().GetPPI().GetHeight() * 96.0f;
  }

  class Frame : public wxFrame {
  public:
    Frame() : wxFrame(nullptr, wxID_ANY, "Hello world (paint)") {
      SetClientSize(300, 300);
      
      Bind(wxEVT_PAINT, [&](wxPaintEvent& event) {
        wxPaintDC dc(this);
        dc.SetFont({PointsToNativeFontGraphicsUntit(32), wxFONTFAMILY_DEFAULT, wxFONTSTYLE_ITALIC, wxFONTWEIGHT_BOLD});
        dc.SetTextForeground(wxTheColourDatabase->Find("Blue"));
        auto text = "Hello,World!";
        dc.DrawText(text, {(GetClientSize().GetWidth() - dc.GetTextExtent(text).GetWidth()) / 2, (GetClientSize().GetHeight() - dc.GetTextExtent(text).GetHeight()) / 2});
      });
    }
    
  private:
    wxPanel* panel = new wxPanel(this);
  };

  class Application : public wxApp {
    bool OnInit() override {
      (new Frame())->Show();
      return true;
    }
  };
}

wxIMPLEMENT_APP(Examples::Application);
