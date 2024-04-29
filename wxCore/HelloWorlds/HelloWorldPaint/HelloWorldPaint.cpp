#include <wx/wx.h>

namespace HelloWorldPaintExample {
  class Frame : public wxFrame {
  public:
    Frame() : wxFrame {nullptr, wxID_ANY, "Hello world (paint)"} {
      Bind(wxEVT_PAINT, [&](wxPaintEvent& event) {
        wxPaintDC dc(this);
        dc.SetFont({32, wxFONTFAMILY_DEFAULT, wxFONTSTYLE_ITALIC, wxFONTWEIGHT_BOLD});
        auto text = "Hello,World!";
        dc.SetBackground({{0x0AD, 0xD8, 0xE6}, wxBRUSHSTYLE_SOLID});
        dc.Clear();
        dc.SetTextForeground({0x73, 0x90, 0x99});
        dc.DrawText(text, {((GetClientSize().GetWidth() - dc.GetTextExtent(text).GetWidth()) / 2) + 2, ((GetClientSize().GetHeight() - dc.GetTextExtent(text).GetHeight()) / 2) + 2});
        dc.SetTextForeground({0x00, 0x00, 0x8B});
        dc.DrawText(text, {((GetClientSize().GetWidth() - dc.GetTextExtent(text).GetWidth()) / 2) - 2, ((GetClientSize().GetHeight() - dc.GetTextExtent(text).GetHeight()) / 2) - 2});
      });
      Bind(wxEVT_SIZING, [&](wxSizeEvent& e) {Refresh();});
    }
  };

  class Application : public wxApp {
    bool OnInit() override {return (new Frame)->Show();}
  };
}

wxIMPLEMENT_APP(HelloWorldPaintExample::Application);
