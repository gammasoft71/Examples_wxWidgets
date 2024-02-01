#include <wx/wx.h>

namespace StaticBoxSizerVerticalExample {
  class Frame : public wxFrame {
  public:
    Frame() : wxFrame(nullptr, wxID_ANY, "StaticBoxSizerVertical example") {
      red_panel->SetBackgroundColour({255, 0, 0});
      green_panel->SetBackgroundColour({0, 128, 0});
      blue_panel->SetBackgroundColour({0, 0, 255});
      yellow_panel->SetBackgroundColour({255, 255, 0});
      
      boxSizerVertical->Add(red_panel, wxSizerFlags().Expand());
      boxSizerVertical->Add(green_panel, wxSizerFlags(70).Expand());
      boxSizerVertical->Add(blue_panel, wxSizerFlags(15).Expand());
      boxSizerVertical->Add(yellow_panel, wxSizerFlags(15).Expand());
      
      SetSizerAndFit(boxSizerVertical);
      SetSize(300, 300);
    }
    
  private:
    wxBoxSizer* boxSizerVertical = new wxBoxSizer(wxVERTICAL);
    
    wxPanel* red_panel = new wxPanel(this, wxID_ANY, wxDefaultPosition, {1, 30});
    wxPanel* green_panel = new wxPanel(this, wxID_ANY, wxDefaultPosition, wxDefaultSize);
    wxPanel* blue_panel = new wxPanel(this, wxID_ANY, wxDefaultPosition, wxDefaultSize);
    wxPanel* yellow_panel = new wxPanel(this, wxID_ANY, wxDefaultPosition, wxDefaultSize);
  };

  class Application : public wxApp {
    bool OnInit() override {
      (new Frame)->Show();
      return true;
    }
  };
}

wxIMPLEMENT_APP(StaticBoxSizerVerticalExample::Application);
