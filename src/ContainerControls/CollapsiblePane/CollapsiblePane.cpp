#include <wx/wx.h>
#include <wx/collpane.h>

namespace Examples {
  class Frame : public wxFrame {
  public:
    Frame() : wxFrame(nullptr, wxID_ANY, "CollapsiblePane example") {
      collapsiblePane1->SetSize(200, 100);
      button1->Bind(wxEVT_BUTTON, [&](wxCommandEvent& event) {
        collapsiblePane1->Collapse();
      });
      
      collapsiblePane1->Bind(wxEVT_COLLAPSIBLEPANE_CHANGED, [&](wxCollapsiblePaneEvent& e) {
        wxMessageOutputDebug().Printf("collapsiblePane1 is %s", e.GetCollapsed() ? "collapsed" : "expanded");
      });
    }
    
  private:
    wxPanel* panel = new wxPanel(this);
    wxCollapsiblePane* collapsiblePane1 = new wxCollapsiblePane(panel, wxID_ANY, "CollapsiblePane1", {10, 10});
    wxButton* button1 = new wxButton(collapsiblePane1->GetPane(), wxID_ANY, "button1", {10, 10});
  };

  class Application : public wxApp {
    bool OnInit() override {
      (new Frame())->Show();
      return true;
    }
  };
}

wxIMPLEMENT_APP(Examples::Application);
