#include <wx/wx.h>

namespace Examples {
  class Frame : public wxFrame {
  public:
    Frame() : wxFrame(nullptr, wxID_ANY, "StatusBar without panels example") {
      SetBackgroundColour({0xFF, 0xFF, 0xFF, 0x10});
      SetStatusBar(statusBar);
      Bind(wxEVT_LEFT_DOWN, [&](wxMouseEvent& e) {
        statusBar->SetStatusText(wxString::Format("Mouse click at position : {x=%d, y=%d}", e.GetX(), e.GetY()));
      });
      
      statusBar->SetStatusText("Click anywhere on the client frame...");
    }

  private:
    wxStatusBar* statusBar = new wxStatusBar(this);
  };

  class Application : public wxApp {
    bool OnInit() override {
      (new Frame())->Show();
      return true;
    }
  };
}

wxIMPLEMENT_APP(Examples::Application);
