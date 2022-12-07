#include <vector>
#include <wx/wx.h>
#include <wx/textdlg.h>

namespace Examples {
class Frame : public wxFrame {
public:
  Frame() : wxFrame(nullptr, wxID_ANY, "SingleChoiceDialog example") {
    button->Bind(wxEVT_BUTTON, [&](wxCommandEvent& event) {
      label->SetLabel("");
      std::vector<wxString> choices = {"item 1", "item 2", "item 3", "item 4", "item 5", "item 6", "item 7", "item 8", "item 9", "item 10"};
      wxSingleChoiceDialog dialog(this, "Message text", "Caption text", static_cast<int>(choices.size()), choices.data());
      if (dialog.ShowModal() == wxID_OK)
        label->SetLabel(dialog.GetStringSelection());
      else
        label->SetLabel("none");
    });
  }
  
private:
  wxPanel* panel = new wxPanel(this);
  wxButton* button = new wxButton(panel, wxID_ANY, "Choice...", {10, 10});
  wxStaticText* label = new wxStaticText(panel, wxID_ANY, "(none)", {10, 50});
};

class Application : public wxApp {
  bool OnInit() override {
    (new Frame())->Show();
    return true;
  }
};
}

wxIMPLEMENT_APP(Examples::Application);
