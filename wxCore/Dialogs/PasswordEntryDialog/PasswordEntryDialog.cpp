#include <wx/wx.h>
#include <wx/textdlg.h>

namespace PasswordEntryDialogExample {
  class Frame : public wxFrame {
  public:
    Frame() : wxFrame(nullptr, wxID_ANY, "PasswordEntryDialog example") {
      button->Bind(wxEVT_BUTTON, [&](wxCommandEvent& event) {
        wxPasswordEntryDialog passwordEntryDialog(this, "User password", "user: admin", label->GetLabel());
        if (passwordEntryDialog.ShowModal() == wxID_OK)
          label->SetLabel(passwordEntryDialog.GetValue());
      });
    }

  private:
    wxPanel* panel = new wxPanel {this};
    wxButton* button = new wxButton(panel, wxID_ANY, "Password...", {10, 10});
    wxStaticText* label = new wxStaticText(panel, wxID_ANY, "sysad47@74dasys", {10, 50});
  };

  class Application : public wxApp {
    bool OnInit() override {
      (new Frame)->Show();
      return true;
    }
  };
}

wxIMPLEMENT_APP(PasswordEntryDialogExample::Application);
