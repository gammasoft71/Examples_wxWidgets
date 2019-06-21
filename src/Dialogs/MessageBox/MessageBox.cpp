#include <wx/wx.h>

class Form : public wxFrame {
public:
  Form() : wxFrame(nullptr, wxID_ANY, "MessageBox example", wxDefaultPosition, wxSize(300, 300)) {
    this->buttonShowMessage.Bind(wxEVT_BUTTON, [&](wxCommandEvent& event) {
      int dialogResult = wxMessageBox("Hello, World!", "Message", wxOK | wxCANCEL, this);
      this->labelDialogResult.SetLabelText(wxString::Format("DialogResult = %s", dialogResult == wxOK ? "wxOK" : "wxCANCEL"));
    });
  }
  
private:
  wxPanel panel {this};
  wxButton buttonShowMessage {&this->panel, wxID_ANY, "Message...", wxPoint(10, 10)};
  wxStaticText labelDialogResult {&this->panel, wxID_ANY, wxEmptyString, wxPoint(10, 45)};
};

class Application : public wxApp {
  bool OnInit() override {return (new Form())->Show();}
};

wxIMPLEMENT_APP(Application);
