#include <wx/wx.h>

namespace Examples {
  // Workaround : with wxWidgets version <= 3.1.4 font is in pixels and not in points on macOS
  int PointsToNativeFontGraphicsUntit(int size) {
    return wxPlatformInfo::Get().GetOperatingSystemFamilyName() != "Macintosh" ? size : static_cast<float>(size) / wxScreenDC().GetPPI().GetHeight() * 96.0f;
  }

  class Frame : public wxFrame {
  public:
    Frame() : wxFrame(nullptr, wxID_ANY, "Hello world (paint)") {
      Bind(wxEVT_PAINT, [&](wxPaintEvent& event) {
        wxPaintDC dc(this);
        dc.SetFont({PointsToNativeFontGraphicsUntit(32), wxFONTFAMILY_DEFAULT, wxFONTSTYLE_ITALIC, wxFONTWEIGHT_BOLD});
        auto text = "Hello,World!";
        dc.SetTextForeground({0x00, 0x55, 0x29});
        dc.DrawText(text, {((GetClientSize().GetWidth() - dc.GetTextExtent(text).GetWidth()) / 2) + 2, ((GetClientSize().GetHeight() - dc.GetTextExtent(text).GetHeight()) / 2) + 2});
        dc.SetTextForeground({0x00, 0xFF, 0x7F});
        dc.DrawText(text, {((GetClientSize().GetWidth() - dc.GetTextExtent(text).GetWidth()) / 2) - 2, ((GetClientSize().GetHeight() - dc.GetTextExtent(text).GetHeight()) / 2) - 2});
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
