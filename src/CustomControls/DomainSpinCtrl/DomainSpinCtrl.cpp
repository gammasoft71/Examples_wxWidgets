#include "wxDomainSpinCtrl.h"
#include <wx/wx.h>

class Frame : public wxFrame {
public:
  Frame() : wxFrame(nullptr, wxID_ANY, "DomainUpDown example", wxDefaultPosition, wxSize(300, 300)) {
    domainSpinCtrl->SetItems({"item1", "item2", "item3", "item4"});
    domainSpinCtrl->SetSelectedIndex(1);
    domainSpinCtrl->Bind(wxEVT_TEXT, [&](wxCommandEvent& event) {
      wxMessageOutputDebug().Printf("id = %d", event.GetId());
      staticText1->SetLabel(domainSpinCtrl->GetValue());
    });
    
    staticText1->SetLabel(domainSpinCtrl->GetValue());
  }
  
private:
  wxPanel* panel = new wxPanel(this);
  wxDomainSpinCtrl* domainSpinCtrl = new wxDomainSpinCtrl(panel, wxID_ANY, wxPoint(10, 10));
  wxStaticText* staticText1 = new wxStaticText(panel, wxID_ANY, wxEmptyString, wxPoint(10, 40));
};

class Application : public wxApp {
  bool OnInit() override {(new Frame())->Show(); return true;}
};

wxIMPLEMENT_APP(Application);
