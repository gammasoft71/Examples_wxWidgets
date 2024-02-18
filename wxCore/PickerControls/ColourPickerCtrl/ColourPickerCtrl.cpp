#include <wx/app.h>
#include <wx/clrpicker.h>
#include <wx/frame.h>
#include <wx/panel.h>
#include <wx/stattext.h>

namespace ColourPickerCtrlExample {
  class Frame : public wxFrame {
  public:
    Frame() : wxFrame {nullptr, wxID_ANY, "ColourPicker example"} {
      testZone->SetBackgroundColour(wxTheColourDatabase->Find("red"));
      colorText->SetLabel(testZone->GetBackgroundColour().GetAsString());
      picker->SetColour(testZone->GetBackgroundColour());
      picker->Bind(wxEVT_COLOURPICKER_CHANGED, [&](wxColourPickerEvent& event) {
        testZone->SetBackgroundColour(event.GetColour());
        testZone->Refresh();
        colorText->SetLabel(event.GetColour().GetAsString(wxC2S_HTML_SYNTAX));
      });
    }
    
  private:
    wxPanel* panel = new wxPanel {this};
    wxColourPickerCtrl* picker = new wxColourPickerCtrl {panel, wxID_ANY, {0, 0, 0}, {10, 10}, wxDefaultSize, wxCLRP_SHOW_ALPHA};
    wxPanel* testZone = new wxPanel {panel, wxID_ANY, {10, 50}, {200, 100}, wxBORDER_SUNKEN | wxALIGN_CENTER | wxALIGN_CENTER_VERTICAL};
    wxStaticText* colorText = new wxStaticText {panel, wxID_ANY, wxEmptyString, {10, 160}};
  };

  class Application : public wxApp {
    bool OnInit() override {return (new Frame)->Show();}
  };
}

wxIMPLEMENT_APP(ColourPickerCtrlExample::Application);
