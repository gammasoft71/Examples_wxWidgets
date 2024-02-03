#include <wx/app.h>
#include <wx/button.h>
#include <wx/frame.h>
#include <wx/choicdlg.h>
#include <wx/panel.h>
#include <wx/stattext.h>
#include <wx/textdlg.h>
#include <vector>

namespace MultiChoiceDialogExample {
  class Frame : public wxFrame {
  public:
    Frame() : wxFrame {nullptr, wxID_ANY, "MultiChoiceDialog example"} {
      button->Bind(wxEVT_BUTTON, [&](wxCommandEvent& event) {
        label->SetLabel("");
        auto choices = std::vector<wxString> {"item 1", "item 2", "item 3", "item 4", "item 5", "item 6", "item 7", "item 8", "item 9", "item 10"};
        auto dialog = wxMultiChoiceDialog {this, "Message text", "Caption text", static_cast<int>(choices.size()), choices.data()};
        if (dialog.ShowModal() == wxID_OK) {
          for (auto selection : dialog.GetSelections()) {
            if (!label->GetLabel().IsEmpty()) label->SetLabel(wxString::Format("%s\n", label->GetLabel()));
            label->SetLabel(wxString::Format("%s%s", label->GetLabel(), choices[selection]));
          }
        }
        if (label->GetLabel().IsEmpty()) label->SetLabel("(none)");
      });
    }

  private:
    wxPanel* panel = new wxPanel {this};
    wxButton* button = new wxButton {panel, wxID_ANY, "Choices...", {10, 10}};
    wxStaticText* label = new wxStaticText {panel, wxID_ANY, "(none)", {10, 50}};
  };

  class Application : public wxApp {
    bool OnInit() override {return (new Frame)->Show();}
  };
}

wxIMPLEMENT_APP(MultiChoiceDialogExample::Application);
