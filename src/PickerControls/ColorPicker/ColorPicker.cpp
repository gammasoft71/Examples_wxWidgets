#include <wx/wx.h>
#include <wx/clrpicker.h>

class Frame : public wxFrame {
public:
  Frame() : wxFrame(nullptr, wxID_ANY, "ColorPicker example", wxDefaultPosition, wxSize(300, 300)) {
    picker->Bind(wxEVT_COLOURPICKER_CHANGED, [this](wxColourPickerEvent& event) {
      test_zone->SetBackgroundColour(event.GetColour());
      test_zone->Refresh();
    });
  }
  
private:
  wxPanel* panel = new wxPanel(this);
  wxPanel* test_zone = new wxPanel(panel, wxID_ANY, {10, 50}, {200, 100}, wxTAB_TRAVERSAL | wxBORDER_SIMPLE);
  wxColourPickerCtrl* picker = new wxColourPickerCtrl(panel, wxID_ANY, test_zone->GetBackgroundColour(), {10, 10});
};

class Application : public wxApp {
  bool OnInit() override {(new Frame())->Show(); return true;}
};

wxIMPLEMENT_APP(Application);
