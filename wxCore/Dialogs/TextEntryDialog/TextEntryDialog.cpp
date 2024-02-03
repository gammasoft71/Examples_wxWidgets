#include <wx/app.h>
#include <wx/button.h>
#include <wx/frame.h>
#include <wx/panel.h>
#include <wx/stattext.h>
#include <wx/textdlg.h>

namespace TextEntryDialogExample {
  class Frame : public wxFrame {
  public:
    Frame() : wxFrame {nullptr, wxID_ANY, "TextEntryDialog example"} {
      button->Bind(wxEVT_BUTTON, [&](wxCommandEvent& event) {
        auto textEntryDialog = wxTextEntryDialog {this, "Message text", "Caption text", label->GetLabel(), wxTextEntryDialogStyle};
        if (textEntryDialog.ShowModal() == wxID_OK)
          label->SetLabel(textEntryDialog.GetValue());
      });
    }

  private:
    wxPanel* panel = new wxPanel {this};
    wxButton* button = new wxButton {panel, wxID_ANY, "Text...", {10, 10}};
    wxStaticText* label = new wxStaticText {panel, wxID_ANY, "Default value", {10, 50}};
  };

  class Application : public wxApp {
    bool OnInit() override {return (new Frame)->Show();}
  };
}

wxIMPLEMENT_APP(TextEntryDialogExample::Application);
