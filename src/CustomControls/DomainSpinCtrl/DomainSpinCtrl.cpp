#include "wxDomainSpinCtrl.h"
#include <wx/wx.h>

namespace Examples {
  class Frame : public wxFrame {
  public:
    Frame() : wxFrame(nullptr, wxID_ANY, "DomainUpDown example") {
      domainSpinCtrl->SetItems({"item 1", "item 2", "item 3", "item 4", "item 5", "item 6", "item 7", "item 8", "item 9", "item 10"});
      domainSpinCtrl->SetSelectedIndex(1);
      domainSpinCtrl->Bind(wxEVT_TEXT, [&](wxCommandEvent& event) {
        wxMessageOutputDebug().Printf("id = %d", event.GetId());
        staticText1->SetLabel(domainSpinCtrl->GetValue());
      });
      
      staticText1->SetLabel(domainSpinCtrl->GetValue());
    }
    
  private:
    wxPanel* panel = new wxPanel(this);
    wxDomainSpinCtrl* domainSpinCtrl = new wxDomainSpinCtrl(panel, wxID_ANY, {10, 10});
    wxStaticText* staticText1 = new wxStaticText(panel, wxID_ANY, wxEmptyString, {10, 40});
  };

  class Application : public wxApp {
    bool OnInit() override {
      (new Frame())->Show();
      return true;
    }
  };
}

wxIMPLEMENT_APP(Examples::Application);
