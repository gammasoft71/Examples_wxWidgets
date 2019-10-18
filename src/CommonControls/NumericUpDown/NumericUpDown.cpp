#include <wx/wx.h>
#include <wx/spinctrl.h>

class Form : public wxFrame {
public:
  Form() : wxFrame(nullptr, wxID_ANY, "NumericUpDown example", wxDefaultPosition, wxSize(300, 300)) {
    numericUpDown1->SetValue(50);
    
    numericUpDown2->SetRange(10.0, 11.0);
    numericUpDown2->SetDigits(2);
    numericUpDown2->SetIncrement(0.01);
  }
  
private:
  wxPanel* panel = new wxPanel(this);
  wxSpinCtrl* numericUpDown1 = new wxSpinCtrl(panel, wxID_ANY, wxEmptyString, wxPoint(80, 50));
  wxSpinCtrlDouble* numericUpDown2 = new wxSpinCtrlDouble(panel, wxID_ANY, wxEmptyString, wxPoint(80, 100));
};

class Application : public wxApp {
  bool OnInit() override {(new Form())->Show(); return true;}
};

wxIMPLEMENT_APP(Application);
