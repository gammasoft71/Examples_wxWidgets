#include <vector>
#include <wx/wx.h>
#include <wx/artprov.h>

namespace Examples {
  class Frame : public wxFrame {
  public:
    Frame() : wxFrame(nullptr, wxID_ANY, "Statusbar without panels example") {
      SetStatusBar(statusBar);    
      statusBar->SetStatusText("Shows status information without panels...");
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
