#include <wx/wx.h>
#include "wxDomainSpinCtrl.h"

class Form : public wxFrame {
public:
  Form() : wxFrame(nullptr, wxID_ANY, "DomainUpDown example", wxDefaultPosition, wxSize(300, 300)) {
    this->domainUpDown.SetItems({"item1", "item2", "item3", "item4"});
    this->domainUpDown.SetSelectedIndex(1);
    this->domainUpDown.Bind(wxEVT_TEXT, [&](wxCommandEvent& event) {
      this->label1.SetLabel(this->domainUpDown.GetValue());
    });
    
    this->label1.SetLabel(this->domainUpDown.GetValue());
    
    this->Show();
  }
  
private:
  wxPanel panel = {this};
  wxDomainSpinCtrl domainUpDown {&this->panel, wxID_ANY, wxPoint(10, 10)};
  wxStaticText label1 {&this->panel, wxID_ANY, wxEmptyString, wxPoint(10, 40)};
};

class Application : public wxApp {
  bool OnInit() override {new Form(); return true;}
};

wxIMPLEMENT_APP(Application);
