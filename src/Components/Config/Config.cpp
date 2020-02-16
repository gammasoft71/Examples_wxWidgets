#include <wx/wx.h>
#include <wx/clrpicker.h>
#include <wx/config.h>

namespace Examples {
  class Frame : public wxFrame {
  public:
    Frame() : wxFrame(nullptr, wxID_ANY, "Config example") {
      read_config();
      
      colourPicker->Bind(wxEVT_COLOURPICKER_CHANGED, [&](wxColourPickerEvent& event) {
        SetBackgroundColour(event.GetColour());
        Refresh();
      });
      
      saveButton->Bind(wxEVT_BUTTON, [&](wxCommandEvent& event) {
        save_config();
      });
      
      reloadButton->Bind(wxEVT_BUTTON, [&](wxCommandEvent& event) {
        read_config();
      });
      
      resetButton->Bind(wxEVT_BUTTON, [&](wxCommandEvent& event) {
        reset_config();
      });
    }

  private:
    void read_config() {
      auto backgroundColor = GetBackgroundColour();
      config.Read("BackgroundColor", &backgroundColor, defaultBackgroundColor);
      wxWindow::SetBackgroundColour(backgroundColor);
      SetPosition(wxPoint(config.Read("Left", 100), config.Read("Top", 50)));
      SetSize(config.Read("Width", 360), config.Read("Height", 80));
      Refresh();
      colourPicker->SetColour(this->GetBackgroundColour());
    }
    
    void save_config() {
      config.Write("BackgroundColor", GetBackgroundColour());
      config.Write("Left", this->GetPosition().x);
      config.Write("Top", this->GetPosition().y);
      config.Write("Width", this->GetSize().GetWidth());
      config.Write("Height", this->GetSize().GetHeight());
      config.Flush();
    }
    
    void reset_config() {
      config.DeleteAll();
      read_config();
    }

    wxConfig config;
    wxColour defaultBackgroundColor = GetBackgroundColour();
    wxPanel* panel = new wxPanel(this);
    wxColourPickerCtrl* colourPicker = new wxColourPickerCtrl(panel, wxID_ANY, {0, 0, 0}, {10, 10}, {75, 25});
    wxButton* saveButton = new wxButton(panel, wxID_ANY, "&Save", {90, 10}, {75, 25});
    wxButton* reloadButton = new wxButton(panel, wxID_ANY, "&Reload", {170, 10}, {75, 25});
    wxButton* resetButton = new wxButton(panel, wxID_ANY, "R&eset", {250, 10}, {75, 25});
  };

  class Application : public wxApp {
    bool OnInit() override {
      (new Frame())->Show();
      return true;
    }
  };
}

wxIMPLEMENT_APP(Examples::Application);
