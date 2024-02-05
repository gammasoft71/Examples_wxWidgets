#include <wx/app.h>
#include <wx/button.h>
#include <wx/choicdlg.h>
#include <wx/frame.h>
#include <wx/panel.h>
#include <wx/stattext.h>
#include <wx/textdlg.h>

using namespace std;

namespace SingleChoiceDialogExample {
  class Frame : public wxFrame {
  public:
    Frame() : wxFrame {nullptr, wxID_ANY, "SingleChoiceDialog example"} {
      button->Bind(wxEVT_BUTTON, [&](wxCommandEvent& event) {
        label->SetLabel("");
        auto choices = vector<wxString> {"item 1", "item 2", "item 3", "item 4", "item 5", "item 6", "item 7", "item 8", "item 9", "item 10"};
        auto dialog = wxSingleChoiceDialog {this, "Message text", "Caption text", choices};
        if (dialog.ShowModal() == wxID_OK)
          label->SetLabel(dialog.GetStringSelection());
        else
          label->SetLabel("none");
      });
    }
    
  private:
    wxPanel* panel = new wxPanel {this};
    wxButton* button = new wxButton {panel, wxID_ANY, "Choice...", {10, 10}};
    wxStaticText* label = new wxStaticText {panel, wxID_ANY, "(none)", {10, 50}};
  };

  class Application : public wxApp {
    bool OnInit() override {return (new Frame)->Show();}
  };
}

wxIMPLEMENT_APP(SingleChoiceDialogExample::Application);
