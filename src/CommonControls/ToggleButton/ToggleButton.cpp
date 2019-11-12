#include <wx/app.h>
#include <wx/tglbtn.h>
#include <wx/frame.h>
#include <wx/panel.h>

class Frame : public wxFrame {
public:
  Frame() : wxFrame(nullptr, wxID_ANY, "ToggleButton example", wxDefaultPosition, wxSize(300, 300)) {
    toggleButton1->SetValue(true);
    toggleButton1->Bind(wxEVT_TOGGLEBUTTON, [&](wxCommandEvent& event) {
      toggleButton1->SetLabel(toggleButton1->GetValue() ? "Checked" : "Unchecked");
    });

    toggleButton2->Bind(wxEVT_TOGGLEBUTTON, [this](wxCommandEvent& event) {
      toggleButton2->SetValue(false);
    });
  }
  
private:
  wxPanel* panel = new wxPanel(this);
  wxToggleButton* toggleButton1 = new wxToggleButton(panel, wxID_ANY, "Checked", wxPoint(30, 30), wxDefaultSize);
  wxToggleButton* toggleButton2 = new wxToggleButton(panel, wxID_ANY, "Unchecked", wxPoint(30, 60), wxDefaultSize);
};

class Application : public wxApp {
  bool OnInit() override {(new Frame())->Show(); return true;}
};

wxIMPLEMENT_APP(Application);
