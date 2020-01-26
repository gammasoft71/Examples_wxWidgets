#include <wx/wx.h>
#include <wx/textdlg.h>

namespace Examples {
  class Frame : public wxFrame {
  public:
    Frame() : wxFrame(nullptr, wxID_ANY, "TextEntryDialog as password example", wxDefaultPosition, {300, 300}) {
      button->Bind(wxEVT_BUTTON, [&](wxCommandEvent& event) {
        wxTextEntryDialog textEntryDialog(this, "Message text", "Caption text", label->GetLabel(), wxTextEntryDialogStyle|wxTE_PASSWORD);
        if (textEntryDialog.ShowModal() == wxID_OK)
          label->SetLabel(textEntryDialog.GetValue());
      });
    }

  private:
    wxPanel* panel = new wxPanel(this);
    wxButton* button = new wxButton(panel, wxID_ANY, "Password...", {10, 10});
    wxStaticText* label = new wxStaticText(panel, wxID_ANY, "123456", {10, 50});
  };

  class Application : public wxApp {
    bool OnInit() override {
      (new Frame())->Show();
      return true;
    }
  };
}

wxIMPLEMENT_APP(Examples::Application);
