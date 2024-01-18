#include "wxDomainSpinCtrl.h"
#include <wx/wx.h>

namespace DomainSpinCtrlExample {
class Frame : public wxFrame {
public:
  Frame() : wxFrame(nullptr, wxID_ANY, "DomainSpinCtrl example") {
    std::vector<wxString> items = {"item 1", "item 2", "item 3", "item 4",
                                   "item 5", "item 6", "item 7", "item 8",
                                   "item 9", "item 10"};

    wxArrayString wxItems;
    for (const auto &item : items) {
      wxItems.Add(item);
    }

    domainSpinCtrl->SetItems(wxItems);
    domainSpinCtrl->SetSelectedIndex(1);
    domainSpinCtrl->Bind(wxEVT_TEXT, [&](wxCommandEvent &event) {
      wxMessageOutputDebug().Printf("id = %d", event.GetId());
      staticText1->SetLabel(domainSpinCtrl->GetValue());
    });

    staticText1->SetLabel(domainSpinCtrl->GetValue());
  }

private:
  wxPanel *panel = new wxPanel(this);
  wxDomainSpinCtrl *domainSpinCtrl =
      new wxDomainSpinCtrl(panel, wxID_ANY, {10, 10});
  wxStaticText *staticText1 =
      new wxStaticText(panel, wxID_ANY, wxEmptyString, {10, 40});
};

class Application : public wxApp {
  bool OnInit() override {
    (new Frame())->Show();
    return true;
  }
};
} // namespace DomainSpinCtrlExample

wxIMPLEMENT_APP(DomainSpinCtrlExample::Application);
