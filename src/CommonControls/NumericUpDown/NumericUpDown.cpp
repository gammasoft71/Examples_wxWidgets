#include <wx/wx.h>
#include <wx/spinctrl.h>

class Form : public wxFrame {
public:
  Form() : wxFrame(nullptr, wxID_ANY, "NumericUpDown example", wxDefaultPosition, wxSize(300, 300)) {
    this->numericUpDown1->SetValue(50);
    
    this->numericUpDown2->SetRange(10.0, 11.0);
    this->numericUpDown2->SetDigits(2);
    this->numericUpDown2->SetIncrement(0.01);
  }
  
private:
  wxPanel* panel = new wxPanel(this);
  wxSpinCtrl* numericUpDown1 = new wxSpinCtrl(this->panel, wxID_ANY, wxEmptyString, wxPoint(80, 50));
  wxSpinCtrlDouble* numericUpDown2 = new wxSpinCtrlDouble(this->panel, wxID_ANY, wxEmptyString, wxPoint(80, 100));
};

class Application : public wxApp {
  bool OnInit() override {return (new Form())->Show();}
};

wxIMPLEMENT_APP(Application);
