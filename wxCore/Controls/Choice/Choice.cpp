#include <wx/app.h>
#include <wx/choice.h>
#include <wx/frame.h>
#include <wx/panel.h>

using namespace std;

namespace ChoiceExample {
  class Frame : public wxFrame {
  public:
    Frame() : wxFrame {nullptr, wxID_ANY, "Choice example"} {
      choice1->Append(10, vector<wxString> {"Item 1", "Item 2", "Item 3", "Item 4", "Item 5", "Item 6", "Item 7", "Item 8", "Item 9", "Item 10"}.data());
      choice1->SetSelection(0);
      choice1->Bind(wxEVT_CHOICE, &Frame::OnChoicClick, this);

      choice2->SetSelection(0);
      choice2->Bind(wxEVT_CHOICE, &Frame::OnChoicClick, this);
    }

  private:
    void OnChoicClick(wxCommandEvent& e) {
      choice1->SetSelection(static_cast<wxChoice*>(e.GetEventObject())->GetSelection());
      choice2->SetSelection(static_cast<wxChoice*>(e.GetEventObject())->GetSelection());
    }
    wxPanel* panel = new wxPanel {this};
    wxChoice* choice1 = new wxChoice {panel, wxID_ANY, {10, 10}, {112, wxDefaultCoord}};
    wxChoice* choice2 = new wxChoice {panel, wxID_ANY, {10, 50}, {112, wxDefaultCoord}, 10, vector<wxString> {"Item 1", "Item 2", "Item 3", "Item 4", "Item 5", "Item 6", "Item 7", "Item 8", "Item 9", "Item 10"}.data()};
  };

  class Application : public wxApp {
    bool OnInit() override {return (new Frame)->Show();}
  };
}

wxIMPLEMENT_APP(ChoiceExample::Application);
