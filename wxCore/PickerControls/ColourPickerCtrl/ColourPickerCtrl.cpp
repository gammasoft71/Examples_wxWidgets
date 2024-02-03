#include <wx/wx.h>
#include <wx/clrpicker.h>

namespace ColourPickerCtrlExample {
  class Frame : public wxFrame {
  public:
    Frame() : wxFrame(nullptr, wxID_ANY, "ColourPicker example") {
      testZone->SetBackgroundColour(wxTheColourDatabase->Find("Red"));
      picker->SetColour(testZone->GetBackgroundColour());
      picker->Bind(wxEVT_COLOURPICKER_CHANGED, [&](wxColourPickerEvent& event) {
        testZone->SetBackgroundColour(event.GetColour());
        testZone->Refresh();
      });
    }
    
  private:
    wxPanel* panel = new wxPanel {this};
    wxPanel* testZone = new wxPanel(panel, wxID_ANY, {10, 50}, {200, 100}, wxTAB_TRAVERSAL | wxBORDER_SUNKEN);
    wxColourPickerCtrl* picker = new wxColourPickerCtrl(panel, wxID_ANY, {0, 0, 0}, {10, 10}, wxDefaultSize, wxCLRP_SHOW_ALPHA);
  };

  class Application : public wxApp {
    bool OnInit() override {return (new Frame)->Show();}
  };
}

wxIMPLEMENT_APP(ColourPickerCtrlExample::Application);
