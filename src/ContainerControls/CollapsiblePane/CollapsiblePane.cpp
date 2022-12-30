#include <wx/wx.h>
#include <wx/collpane.h>

namespace Examples {
  class Frame : public wxFrame {
  public:
    Frame() : wxFrame(nullptr, wxID_ANY, "CollapsiblePanel example") {
      boxSizer->Add(collapsiblePane1, wxSizerFlags(0).Expand());
      boxSizer->Add(collapsiblePane2, wxSizerFlags(1).Expand());
      panel->SetSizerAndFit(boxSizer);

      buttonAdd->Bind(wxEVT_BUTTON, [&](wxCommandEvent& event) {
        auto item = new wxStaticText(collapsiblePane2->GetPane(), wxID_ANY, wxString::Format("item %d", ++count));
        boxSizerCollapsiblePane2->Add(item);
        boxSizerCollapsiblePane2->Layout();
      });
      buttonRemove->Bind(wxEVT_BUTTON, [&](wxCommandEvent& event) {
        if (collapsiblePane2->GetPane()->GetChildren().size() > 0) {
          collapsiblePane2->GetPane()->GetChildren()[0]->Destroy();
          boxSizerCollapsiblePane2->Layout();
        }
      });
      buttonExpand->Bind(wxEVT_BUTTON, [&](wxCommandEvent& event) {
        collapsiblePane2->Collapse(!collapsiblePane2->IsCollapsed());
      });

      collapsiblePane1->Bind(wxEVT_COLLAPSIBLEPANE_CHANGED, [&](wxCollapsiblePaneEvent& e) {
        boxSizer->Layout();
      });
      
      collapsiblePane2->Bind(wxEVT_COLLAPSIBLEPANE_CHANGED, [&](wxCollapsiblePaneEvent& e) {
        boxSizer->Layout();
      });
      
      collapsiblePane2->GetPane()->SetSizerAndFit(boxSizerCollapsiblePane2);
    }
    
  private:
    int count = 0;
    wxPanel* panel = new wxPanel(this);
    wxBoxSizer* boxSizer = new wxBoxSizer(wxVERTICAL);
    wxCollapsiblePane* collapsiblePane1 = new wxCollapsiblePane(panel, wxID_ANY, "CollapsiblePane1");
    wxCollapsiblePane* collapsiblePane2 = new wxCollapsiblePane(panel, wxID_ANY, "CollapsiblePane2");
    wxButton* buttonAdd = new wxButton(collapsiblePane1->GetPane(), wxID_ANY, "Add", {10, 0});
    wxButton* buttonRemove = new wxButton(collapsiblePane1->GetPane(), wxID_ANY, "Remove", {10, 30});
    wxButton* buttonExpand = new wxButton(collapsiblePane1->GetPane(), wxID_ANY, "Expand", {10, 60});
    wxBoxSizer* boxSizerCollapsiblePane2 = new wxBoxSizer(wxVERTICAL);
  };

  class Application : public wxApp {
    bool OnInit() override {
      (new Frame())->Show();
      return true;
    }
  };
}

wxIMPLEMENT_APP(Examples::Application);
