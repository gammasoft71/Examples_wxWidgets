#include <wx/app.h>
#include <wx/spinbutt.h>
#include <wx/frame.h>
#include <wx/msgout.h>
#include <wx/panel.h>
#include <wx/stattext.h>

namespace Examples {
  class Frame : public wxFrame {
  public:
    Frame() : wxFrame(nullptr, wxID_ANY, "SpinButton example") {
      spinButton1->SetRange(10, 20);
      spinButton1->SetValue(15);
      spinButton1->Bind(wxEVT_SPIN, [&](wxCommandEvent& event) {
        text->SetLabel(wxString::Format("value = %d", spinButton1->GetValue()));
      });
    }
    
  private:
    wxPanel* panel = new wxPanel(this);
    wxSpinButton* spinButton1 = new wxSpinButton(panel, wxID_ANY, {10, 10}, wxDefaultSize, wxSP_VERTICAL|wxSP_WRAP);
    wxStaticText* text = new wxStaticText(panel, wxID_ANY, "value = 15", {10, 50});
  };

  class Application : public wxApp {
    bool OnInit() override {
      (new Frame())->Show();
      return true;
    }
  };
}

wxIMPLEMENT_APP(Examples::Application);
