#include <wx/wx.h>
#include <wx/textdlg.h>

namespace TextEntryDialogMultilineExample {
  class Frame : public wxFrame {
  public:
    Frame() : wxFrame(nullptr, wxID_ANY, "TextEntryDialog multiline example") {
      button->Bind(wxEVT_BUTTON, [&](wxCommandEvent& event) {
        wxTextEntryDialog textEntryDialog(this, "Message text", "Caption text", label->GetLabel(), wxTextEntryDialogStyle|wxTE_MULTILINE);
        if (textEntryDialog.ShowModal() == wxID_OK)
          label->SetLabel(textEntryDialog.GetValue());
      });
    }

  private:
    wxPanel* panel = new wxPanel {this};
    wxButton* button = new wxButton(panel, wxID_ANY, "Text...", {10, 10});
    wxStaticText* label = new wxStaticText(panel, wxID_ANY, "line 1\nline 2", {10, 50});
  };

  class Application : public wxApp {
    bool OnInit() override {return (new Frame)->Show();}
  };
}

wxIMPLEMENT_APP(TextEntryDialogMultilineExample::Application);
