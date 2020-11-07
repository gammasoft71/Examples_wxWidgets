#include <vector>
#include <wx/wx.h>
#include <wx/artprov.h>

namespace Examples {
  class Frame : public wxFrame {
  public:
    Frame() : wxFrame(nullptr, wxID_ANY, "Statusbar example") {
      SetStatusBar(statusBar);
    
      std::vector statusWidths = {80, 80, -1};
      std::vector statusStyles = {wxSB_SUNKEN, wxSB_SUNKEN, wxSB_SUNKEN};
      
      statusBar->SetFieldsCount(statusWidths.size());
      statusBar->SetStatusWidths(statusWidths.size(), statusWidths.data());
      statusBar->SetStatusStyles(statusStyles.size(), statusStyles.data());
      
      statusBar->SetStatusText("Status One");
      statusBar->SetStatusText("Status Two", 1);
      statusBar->SetStatusText("Status Three", 2);
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
