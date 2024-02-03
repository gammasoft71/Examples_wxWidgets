#include <wx/wx.h>
#include <wx/textdlg.h>

namespace TextEntryDialogPasswordExample {
  class Frame : public wxFrame {
  public:
    Frame() : wxFrame(nullptr, wxID_ANY, "TextEntryDialog as password example") {
      button->Bind(wxEVT_BUTTON, [&](wxCommandEvent& event) {
        wxTextEntryDialog textEntryDialog(this, "user: admin", "User password", label->GetLabel(), wxTextEntryDialogStyle|wxTE_PASSWORD);
        if (textEntryDialog.ShowModal() == wxID_OK)
          label->SetLabel(textEntryDialog.GetValue());
      });
    }

  private:
    wxPanel* panel = new wxPanel {this};
    wxButton* button = new wxButton(panel, wxID_ANY, "Password...", {10, 10});
    wxStaticText* label = new wxStaticText(panel, wxID_ANY, "sysad47@74dasys", {10, 50});
  };

  class Application : public wxApp {
    bool OnInit() override {return (new Frame)->Show();}
  };
}

wxIMPLEMENT_APP(TextEntryDialogPasswordExample::Application);
