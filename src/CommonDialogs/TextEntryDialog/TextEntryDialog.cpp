#include <wx/wx.h>
#include <wx/textdlg.h>

class Frame : public wxFrame {
public:
  Frame() : wxFrame(nullptr, wxID_ANY, "TextEntryDialog example", wxDefaultPosition, {300, 300}) {
    button->Bind(wxEVT_BUTTON, [&](wxCommandEvent& event) {
      wxTextEntryDialog textEntryDialog(this, "Message text", "Caption text", label->GetLabel(), wxTextEntryDialogStyle);
      if (textEntryDialog.ShowModal())
        label->SetLabel(textEntryDialog.GetValue());
    });
  }

private:
  wxPanel* panel = new wxPanel(this);
  wxButton* button = new wxButton(panel, wxID_ANY, "Text...", {10, 10});
  wxStaticText* label = new wxStaticText(panel, wxID_ANY, "Default value", {10, 50});
};

class Application : public wxApp {
  bool OnInit() override {(new Frame())->Show(); return true;}
};

wxIMPLEMENT_APP(Application);
