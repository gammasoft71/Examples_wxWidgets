#include <wx/app.h>
#include <wx/choice.h>
#include <wx/frame.h>
#include <wx/panel.h>

namespace Examples {
  class Frame : public wxFrame {
  public:
    Frame() : wxFrame(nullptr, wxID_ANY, "Choice example", wxDefaultPosition, {300, 300}) {
      choice1->Append({"item1", "item2", "item3", "item4", "item5", "item6", "item7", "item8", "item9", "item10"});
      choice1->SetSelection(0);
      choice1->Bind(wxEVT_CHOICE, [&](wxCommandEvent& e) {
        choice2->SetSelection(choice1->GetSelection());
      });

      choice2->Append({"item1", "item2", "item3", "item4", "item5", "item6", "item7", "item8", "item9", "item10"});
      choice2->SetSelection(0);
      choice2->Bind(wxEVT_CHOICE, [&](wxCommandEvent& e) {
        choice1->SetSelection(choice2->GetSelection());
      });
    }
    
  private:
    wxPanel* panel = new wxPanel(this);
    wxChoice* choice1 = new wxChoice(panel, wxID_ANY, {10, 10});
    wxChoice* choice2 = new wxChoice(panel, wxID_ANY, {10, 50});
  };

  class Application : public wxApp {
    bool OnInit() override {
      (new Frame())->Show();
      return true;
    }
  };
}

wxIMPLEMENT_APP(Examples::Application);
