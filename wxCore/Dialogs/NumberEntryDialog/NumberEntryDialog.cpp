#include <wx/app.h>
#include <wx/button.h>
#include <wx/frame.h>
#include <wx/numdlg.h>
#include <wx/panel.h>
#include <wx/stattext.h>

namespace NumberEntryDialogExample {
class Frame : public wxFrame {
public:
  Frame() : wxFrame(nullptr, wxID_ANY, "NumberEntryDialog example") {
    button->Bind(wxEVT_BUTTON, [&](wxCommandEvent& event) {
      label->SetLabel("Number = ");
      auto dialog = wxNumberEntryDialog {this, "Message text", "Prompt text", "Caption text", 50, 10, 100};
      if (dialog.ShowModal() == wxID_OK)
        label->SetLabel(wxString::Format("Number = %ld", dialog.GetValue()));
    });
  }
  
private:
  wxPanel* panel = new wxPanel {this};
  wxButton* button = new wxButton {panel, wxID_ANY, "Number...", {10, 10}};
  wxStaticText* label = new wxStaticText {panel, wxID_ANY, "Number = ", {10, 50}};
};

class Application : public wxApp {
  bool OnInit() override {
    (new Frame)->Show();
    return true;
  }
};
}

wxIMPLEMENT_APP(NumberEntryDialogExample::Application);
