#include "Application.h"
#include <wx/wx.h>
#include <wx/display.h>
#include <wx/log.h>

class MainFrame : public wxFrame {
public:
  MainFrame() : wxFrame {nullptr, wxID_ANY, wxEmptyString} {
    red_panel->SetBackgroundColour({255, 0, 0});
    green_panel->SetBackgroundColour({0, 128, 0});
    blue_panel->SetBackgroundColour({0, 0, 255});
    yellow_panel->SetBackgroundColour({255, 255, 0});
    
    wxSizerFlags sizerFlags = wxSizerFlags(1).Expand().Border(wxDOWN, 5);
    boxSizerVertical->Add(red_panel, sizerFlags);
    boxSizerVertical->Add(green_panel, sizerFlags);
    boxSizerVertical->Add(blue_panel, sizerFlags);
    boxSizerVertical->Add(yellow_panel, sizerFlags);
    
    SetSizerAndFit(boxSizerVertical);
    SetSize(300, 300);
  }

private:
  wxBoxSizer* boxSizerVertical = new wxBoxSizer(wxVERTICAL);

  wxPanel* red_panel = new wxPanel(this, wxID_ANY, wxDefaultPosition, wxDefaultSize);
  wxPanel* green_panel = new wxPanel(this, wxID_ANY, wxDefaultPosition, wxDefaultSize);
  wxPanel* blue_panel = new wxPanel(this, wxID_ANY, wxDefaultPosition, wxDefaultSize);
  wxPanel* yellow_panel = new wxPanel(this, wxID_ANY, wxDefaultPosition, wxDefaultSize);
};

int main() {
  auto application = new wxApplication;
  application->MainLoop(new MainFrame);
}
