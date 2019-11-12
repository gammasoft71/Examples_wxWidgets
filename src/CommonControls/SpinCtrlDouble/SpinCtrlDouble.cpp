#include <wx/app.h>
#include <wx/spinctrl.h>
#include <wx/frame.h>
#include <wx/msgout.h>
#include <wx/panel.h>

class Frame : public wxFrame {
public:
  Frame() : wxFrame(nullptr, wxID_ANY, "SpinCtrlDouble example", wxDefaultPosition, wxSize(300, 300)) {
    spinCtrlDouble1->SetRange(10.0, 11.0);
    spinCtrlDouble1->SetDigits(2);
    spinCtrlDouble1->SetIncrement(0.01);
    spinCtrlDouble1->Bind(wxEVT_SPIN, [this](wxCommandEvent& EVENT) {
      wxMessageOutputDebug().Printf("value = %f", spinCtrlDouble1->GetValue());
    });
  }
  
private:
  wxPanel* panel = new wxPanel(this);
  wxSpinCtrlDouble* spinCtrlDouble1 = new wxSpinCtrlDouble(panel, wxID_ANY, wxEmptyString, wxPoint(80, 50));
};

class Application : public wxApp {
  bool OnInit() override {(new Frame())->Show(); return true;}
};

wxIMPLEMENT_APP(Application);
