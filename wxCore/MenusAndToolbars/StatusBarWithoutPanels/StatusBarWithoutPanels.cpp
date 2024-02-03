#include <wx/app.h>
#include <wx/frame.h>

namespace StatusBarWithoutPanelsExample {
  class Frame : public wxFrame {
  public:
    Frame() : wxFrame(nullptr, wxID_ANY, "StatusBar without panels example") {
      SetStatusBar(statusBar);
      Bind(wxEVT_LEFT_DOWN, [&](wxMouseEvent& e) {statusBar->SetStatusText(wxString::Format("Mouse click at position : {x=%d, y=%d}", e.GetX(), e.GetY()));});
      
      statusBar->SetStatusText("Click anywhere on the client frame...");
    }

  private:
    wxStatusBar* statusBar = new wxStatusBar {this};
  };

  class Application : public wxApp {
    bool OnInit() override {return (new Frame)->Show();}
  };
}

wxIMPLEMENT_APP(StatusBarWithoutPanelsExample::Application);
