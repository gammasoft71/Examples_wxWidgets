#include <wx/wx.h>

namespace Examples {
  class Frame : public wxFrame {
  public:
    Frame() : wxFrame(nullptr, wxID_ANY, "RadioBox example", wxDefaultPosition, {300, 300}) {
      radioBox1->Bind(wxEVT_RADIOBOX, [&](wxCommandEvent& event) {
        wxMessageOutputDebug().Printf("(RadioBox 1) checked item = {%s}", choices1[event.GetInt()]);
      });
      
      radioBox2->Bind(wxEVT_RADIOBOX, [&](wxCommandEvent& event) {
        wxMessageOutputDebug().Printf("(RadioBox 2) checked item = {%s}", choices2[event.GetInt()]);
      });
      radioBox2->SetSelection(1);
    }
    
  private:
    wxPanel* panel = new wxPanel(this);
    std::vector<wxString> choices1 = {"Radio 1", "Radio 2", "Radio 3"};
    std::vector<wxString> choices2 = {"Radio 4", "Radio 5", "Radio 6"};
    wxRadioBox* radioBox1 = new wxRadioBox(panel, wxID_ANY, "RadioBox 1", {10, 10}, wxDefaultSize, choices1.size(), choices1.data(), 0, wxRA_SPECIFY_ROWS);
    wxRadioBox* radioBox2 = new wxRadioBox(panel, wxID_ANY, "RadioBox 2", {130, 10}, wxDefaultSize, choices2.size(), choices2.data(), 0, wxRA_SPECIFY_ROWS);
  };

  class Application : public wxApp {
    bool OnInit() override {
      (new Frame())->Show();
      return true;
    }
  };
}

wxIMPLEMENT_APP(Examples::Application);
