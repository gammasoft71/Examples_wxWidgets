#include <wx/wx.h>
#include <wx/clrpicker.h>
#include <wx/config.h>
#include <wx/settings.h>

namespace ConfigExample {
  class Frame : public wxFrame {
  public:
    Frame() : wxFrame(nullptr, wxID_ANY, "Config example") {
      reload_config();
      
      colourPicker->Bind(wxEVT_COLOURPICKER_CHANGED, [&](wxColourPickerEvent& event) {
        panel->SetBackgroundColour(event.GetColour());
        Refresh();
      });
      
      saveButton->Bind(wxEVT_BUTTON, [&](wxCommandEvent& event) {
        save_config();
      });
      
      reloadButton->Bind(wxEVT_BUTTON, [&](wxCommandEvent& event) {
        reload_config();
      });
      
      resetButton->Bind(wxEVT_BUTTON, [&](wxCommandEvent& event) {
        reset_config();
      });
    }

  private:
    void reload_config() {
      auto backgroundColor = panel->GetBackgroundColour();
      config.Read("BackgroundColor", &backgroundColor, wxSystemSettings::GetColour(wxSystemColour::wxSYS_COLOUR_BTNFACE));
      panel->SetBackgroundColour(backgroundColor);
      SetPosition(wxPoint(static_cast<int>(config.Read("Left", 100)), static_cast<int>(config.Read("Top", 50))));
      SetSize(static_cast<int>(config.Read("Width", 360)), static_cast<int>(config.Read("Height", 80)));
      Refresh();
      colourPicker->SetColour(panel->GetBackgroundColour());
    }
    
    void save_config() {
      config.Write("BackgroundColor", panel->GetBackgroundColour());
      config.Write("Left", this->GetPosition().x);
      config.Write("Top", this->GetPosition().y);
      config.Write("Width", this->GetSize().GetWidth());
      config.Write("Height", this->GetSize().GetHeight());
      config.Flush();
    }
    
    void reset_config() {
      config.DeleteAll();
      reload_config();
    }

    wxPanel* panel = new wxPanel {this};
    wxColourPickerCtrl* colourPicker = new wxColourPickerCtrl(panel, wxID_ANY, {0, 0, 0}, {10, 10}, {75, 25});
    wxButton* saveButton = new wxButton(panel, wxID_ANY, "&Save", {90, 10}, {75, 25});
    wxButton* reloadButton = new wxButton(panel, wxID_ANY, "&Reload", {170, 10}, {75, 25});
    wxButton* resetButton = new wxButton(panel, wxID_ANY, "R&eset", {250, 10}, {75, 25});
    wxConfig config;
  };

  class Application : public wxApp {
    bool OnInit() override {return (new Frame)->Show();}
  };
}

wxIMPLEMENT_APP(ConfigExample::Application);
