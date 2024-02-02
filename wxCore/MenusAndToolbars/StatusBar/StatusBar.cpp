#include <vector>
#include <wx/wx.h>
#include <wx/artprov.h>

namespace StatusBarExample {
  class Frame : public wxFrame {
  public:
    Frame() : wxFrame(nullptr, wxID_ANY, "StatusBar example") {
      SetStatusBar(statusBar);
    
      auto statusWidths = std::vector {80, 80, -1};
      auto statusStyles = std::vector {wxSB_SUNKEN, wxSB_SUNKEN, wxSB_SUNKEN};
      
      statusBar->SetFieldsCount(static_cast<int>(statusWidths.size()));
      statusBar->SetStatusWidths(static_cast<int>(statusWidths.size()), statusWidths.data());
      statusBar->SetStatusStyles(static_cast<int>(statusStyles.size()), statusStyles.data());
      
      statusBar->SetStatusText("Status One");
      statusBar->SetStatusText("Status Two", 1);
      statusBar->SetStatusText("Status Three", 2);
    }

  private:
    wxStatusBar* statusBar = new wxStatusBar {this};
  };

  class Application : public wxApp {
    bool OnInit() override {
      (new Frame)->Show();
      return true;
    }
  };
}

wxIMPLEMENT_APP(StatusBarExample::Application);
