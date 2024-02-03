#include <wx/wx.h>
#include <wx/clrpicker.h>
#include "Settings.hpp"

namespace Config2Example {
  class Frame : public wxFrame {
  public:
    Frame() : wxFrame(nullptr, wxID_ANY, Properties::Settings::DefaultSettings().Caption()) {
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
      Properties::Settings::DefaultSettings().Reload();
      SetPosition(Properties::Settings::DefaultSettings().Position());
      SetSize(Properties::Settings::DefaultSettings().Size());
      panel->SetBackgroundColour(Properties::Settings::DefaultSettings().BackgroundColour());
      colourPicker->SetColour(Properties::Settings::DefaultSettings().BackgroundColour());
      Refresh();
    }
    
    void save_config() {
      Properties::Settings::DefaultSettings().Position(GetPosition());
      Properties::Settings::DefaultSettings().Size(GetSize());
      Properties::Settings::DefaultSettings().BackgroundColour(panel->GetBackgroundColour());
      Properties::Settings::DefaultSettings().Save();
    }
    
    void reset_config() {
      Properties::Settings::DefaultSettings().Reset();
      reload_config();
    }

    wxPanel* panel = new wxPanel {this};
    wxColourPickerCtrl* colourPicker = new wxColourPickerCtrl(panel, wxID_ANY, {0, 0, 0}, {10, 10}, {75, 25});
    wxButton* saveButton = new wxButton(panel, wxID_ANY, "&Save", {90, 10}, {75, 25}, wxBORDER_SIMPLE);
    wxButton* reloadButton = new wxButton(panel, wxID_ANY, "&Reload", {170, 10}, {75, 25}, wxBORDER_SIMPLE);
    wxButton* resetButton = new wxButton(panel, wxID_ANY, "R&eset", {250, 10}, {75, 25}, wxBORDER_SIMPLE);
    wxColour defaultBackgroundColor = panel->GetBackgroundColour();
  };

  class Application : public wxApp {
    bool OnInit() override {return (new Frame)->Show();}
  };
}

wxIMPLEMENT_APP(Config2Example::Application);
