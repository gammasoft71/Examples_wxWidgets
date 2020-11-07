#include <vector>
#include <wx/wx.h>
#include <wx/numdlg.h>

namespace Examples {
class Frame : public wxFrame {
public:
  Frame() : wxFrame(nullptr, wxID_ANY, "NumberEntryDialog example") {
    button->Bind(wxEVT_BUTTON, [&](wxCommandEvent& event) {
      label->SetLabel("Number = ");
      wxNumberEntryDialog dialog(this, "Message text", "Prompt text", "Caption text", 50, 10, 100);
      if (dialog.ShowModal() == wxID_OK)
        label->SetLabel(wxString::Format("Number = %ld", dialog.GetValue()));
    });
  }
  
private:
  wxPanel* panel = new wxPanel(this);
  wxButton* button = new wxButton(panel, wxID_ANY, "Number...", {10, 10});
  wxStaticText* label = new wxStaticText(panel, wxID_ANY, "Number = ", {10, 50});
};

class Application : public wxApp {
  bool OnInit() override {
    (new Frame())->Show();
    return true;
  }
};
}

wxIMPLEMENT_APP(Examples::Application);
