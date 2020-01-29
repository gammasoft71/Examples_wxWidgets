#include <wx/app.h>
#include <wx/choice.h>
#include <wx/frame.h>
#include <wx/panel.h>

namespace Examples {
  class Frame : public wxFrame {
  public:
    Frame() : wxFrame(nullptr, wxID_ANY, "Choice example", wxDefaultPosition, {300, 300}) {
      for (auto item : {"item 1", "item 2", "item 3", "item 4", "item 5", "item 6", "item 7", "item 8", "item 9", "item 10"})
        choice1->Append(item);
      choice1->SetSelection(0);
      choice1->Bind(wxEVT_CHOICE, [&](wxCommandEvent& e) {
        choice2->SetSelection(choice1->GetSelection());
      });

      for (auto item : {"item 1", "item 2", "item 3", "item 4", "item 5", "item 6", "item 7", "item 8", "item 9", "item 10"})
        choice2->Append(item);
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
