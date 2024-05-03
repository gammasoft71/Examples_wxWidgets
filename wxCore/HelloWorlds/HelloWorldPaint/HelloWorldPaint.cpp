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
        auto shadowRect = GetClientRect();
        shadowRect.Offset(wxPoint {2, 2});
        dc.DrawLabel(text, shadowRect, wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL);
        dc.SetTextForeground({0x00, 0x00, 0x8B});
        dc.DrawLabel(text, GetClientRect(), wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL);
      });
      Bind(wxEVT_SIZING, [&](wxSizeEvent& e) {Refresh();});
    }
  };

  class Application : public wxApp {
    bool OnInit() override {return (new Frame)->Show();}
  };
}

wxIMPLEMENT_APP(HelloWorldPaintExample::Application);
