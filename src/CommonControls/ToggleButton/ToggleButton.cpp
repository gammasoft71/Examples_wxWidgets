#include <wx/app.h>
#include <wx/tglbtn.h>
#include <wx/frame.h>
#include <wx/panel.h>

namespace Examples {
  class Frame : public wxFrame {
  public:
    Frame() : wxFrame(nullptr, wxID_ANY, "ToggleButton example", wxDefaultPosition, {300, 300}) {
      toggleButton1->Bind(wxEVT_TOGGLEBUTTON, [&](wxCommandEvent& event) {
        toggleButton1->SetValue(false);
      });

      toggleButton2->SetValue(true);
      toggleButton2->Bind(wxEVT_TOGGLEBUTTON, [&](wxCommandEvent& event) {
        toggleButton2->SetLabel(toggleButton2->GetValue() ? "Checked" : "Unchecked");
      });
    }
    
  private:
    wxPanel* panel = new wxPanel(this);
    wxToggleButton* toggleButton1 = new wxToggleButton(panel, wxID_ANY, "Unchecked", {30, 30});
    wxToggleButton* toggleButton2 = new wxToggleButton(panel, wxID_ANY, "Checked", {30, 60});
  };

  class Application : public wxApp {
    bool OnInit() override {
      (new Frame())->Show();
      return true;
    }
  };
}

wxIMPLEMENT_APP(Examples::Application);
