#include <wx/app.h>
#include <wx/spinctrl.h>
#include <wx/frame.h>
#include <wx/msgout.h>
#include <wx/panel.h>
#include <wx/stattext.h>

class Frame : public wxFrame {
public:
  Frame() : wxFrame(nullptr, wxID_ANY, "SpinCtrl example", wxDefaultPosition, wxSize(300, 300)) {
    spinCtrl1->SetValue(50);
    spinCtrl1->Bind(wxEVT_SPINCTRL, [this](wxCommandEvent& event) {
      text->SetLabel(wxString::Format("value = %d", spinCtrl1->GetValue()));
    });
  }
  
private:
  wxPanel* panel = new wxPanel(this);
  wxSpinCtrl* spinCtrl1 = new wxSpinCtrl(panel, 100, wxEmptyString, wxPoint(80, 50), wxDefaultSize);
  wxStaticText* text = new wxStaticText(panel, wxID_ANY, "value = 50", wxPoint(80, 100));
};

class Application : public wxApp {
  bool OnInit() override {(new Frame())->Show(); return true;}
};

wxIMPLEMENT_APP(Application);
