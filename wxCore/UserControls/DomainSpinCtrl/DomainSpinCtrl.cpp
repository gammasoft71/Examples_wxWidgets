#include "wxDomainSpinCtrl.h"
#include <wx/wx.h>

using namespace std;

namespace Examples {
  class Frame : public wxFrame {
  public:
    Frame() : wxFrame(nullptr, wxID_ANY, "DomainSpinCtrl example") {
      domainSpinCtrl->SetItems(vector {"item 1", "item 2", "item 3", "item 4", "item 5", "item 6", "item 7", "item 8", "item 9", "item 10"});
      domainSpinCtrl->Bind(wxEVT_TEXT, [&](wxCommandEvent& event) {
        wxMessageOutputDebug().Printf("id = %d", event.GetId());
        staticText1->SetLabel(domainSpinCtrl->GetValue());
      });
      domainSpinCtrl->SetSelectedIndex(5);

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
