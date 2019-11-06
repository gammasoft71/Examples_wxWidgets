#include "wxDomainSpinCtrl.h"
#include <wx/wx.h>

class Form : public wxFrame {
public:
  Form() : wxFrame(nullptr, wxID_ANY, "DomainUpDown example", wxDefaultPosition, wxSize(300, 300)) {
    domainUpDown->SetItems({"item1", "item2", "item3", "item4"});
    domainUpDown->SetSelectedIndex(1);
    domainUpDown->Bind(wxEVT_TEXT, [&](wxCommandEvent& event) {
      wxMessageOutputDebug().Printf("id = %d", event.GetId());
      label1->SetLabel(domainUpDown->GetValue());
    });
    
    label1->SetLabel(domainUpDown->GetValue());
  }
  
private:
  wxPanel* panel = new wxPanel(this);
  wxDomainSpinCtrl* domainUpDown = new wxDomainSpinCtrl(panel, wxID_ANY, wxPoint(10, 10));
  wxStaticText* label1 = new wxStaticText(panel, wxID_ANY, wxEmptyString, wxPoint(10, 40));
};

class Application : public wxApp {
  bool OnInit() override {(new Form())->Show(); return true;}
};

wxIMPLEMENT_APP(Application);
