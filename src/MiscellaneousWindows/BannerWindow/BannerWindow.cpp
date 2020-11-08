#include <wx/app.h>
#include <wx/frame.h>
#include <wx/panel.h>
#include <wx/bannerwindow.h>

namespace Examples {
  class Frame : public wxFrame {
  public:
    Frame() : wxFrame(nullptr, wxID_ANY, "StaticText example") {
      banner->SetText("Banner caption", "Banner message text");
      banner->SetForegroundColour({0, 0, 0});
    }
    
  private:
    wxPanel* panel = new wxPanel(this);
    wxBannerWindow* banner = new wxBannerWindow(panel, wxID_ANY, wxTOP, wxDefaultPosition, {800, 50}, wxALIGN_CENTRE_HORIZONTAL);
  };

  class Application : public wxApp {
    bool OnInit() override {
      (new Frame())->Show();
      return true;
    }
  };
}

wxIMPLEMENT_APP(Examples::Application);
