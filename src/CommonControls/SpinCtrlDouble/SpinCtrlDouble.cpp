#include <wx/app.h>
#include <wx/spinctrl.h>
#include <wx/frame.h>
#include <wx/msgout.h>
#include <wx/panel.h>
#include <wx/stattext.h>

namespace Examples {
  class Frame : public wxFrame {
  public:
    Frame() : wxFrame(nullptr, wxID_ANY, "SpinCtrlDouble example", wxDefaultPosition, {300, 300}) {
      spinCtrlDouble1->SetRange(10.0, 11.0);
      spinCtrlDouble1->SetDigits(2);
      spinCtrlDouble1->SetIncrement(0.01);
      spinCtrlDouble1->Bind(wxEVT_SPIN, [&](wxCommandEvent& event) {
        text->SetLabel(wxString::Format("value = %.02f", spinCtrlDouble1->GetValue()));
      });
    }
    
  private:
    wxPanel* panel = new wxPanel(this);
    wxSpinCtrlDouble* spinCtrlDouble1 = new wxSpinCtrlDouble(panel, wxID_ANY, wxEmptyString, {80, 50});
    wxStaticText* text = new wxStaticText(panel, wxID_ANY, "value = 10.00", {80, 100});
  };

  class Application : public wxApp {
    bool OnInit() override {
      (new Frame())->Show();
      return true;
    }
  };
}

wxIMPLEMENT_APP(Examples::Application);
