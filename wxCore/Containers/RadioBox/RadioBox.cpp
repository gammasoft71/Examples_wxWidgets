#include <wx/app.h>
#include <wx/frame.h>
#include <wx/panel.h>
#include <wx/radiobox.h>

using namespace std;

namespace RadioBoxExample {
  class Frame : public wxFrame {
  public:
    Frame() : wxFrame {nullptr, wxID_ANY, "RadioBox example"} {
      radioBox1->Bind(wxEVT_RADIOBOX, [&](wxCommandEvent& event) {
        wxMessageOutputDebug().Printf("(RadioBox 1) checked item = {%s}", choices1[event.GetInt()]);
      });
      
      radioBox2->Bind(wxEVT_RADIOBOX, [&](wxCommandEvent& event) {
        wxMessageOutputDebug().Printf("(RadioBox 2) checked item = {%s}", choices2[event.GetInt()]);
      });
      radioBox2->SetSelection(1);
    }
    
  private:
    wxPanel* panel = new wxPanel {this};
    vector<wxString> choices1 = {"Radio 1", "Radio 2", "Radio 3"};
    vector<wxString> choices2 = {"Radio 4", "Radio 5", "Radio 6"};
    wxRadioBox* radioBox1 = new wxRadioBox {panel, wxID_ANY, "RadioBox 1", {10, 10}, wxDefaultSize, static_cast<int>(choices1.size()), choices1.data(), 0, wxRA_SPECIFY_ROWS};
    wxRadioBox* radioBox2 = new wxRadioBox {panel, wxID_ANY, "RadioBox 2", {130, 10}, wxDefaultSize, static_cast<int>(choices2.size()), choices2.data(), 0, wxRA_SPECIFY_COLS};
  };

  class Application : public wxApp {
    bool OnInit() override {return (new Frame)->Show();}
  };
}

wxIMPLEMENT_APP(RadioBoxExample::Application);
