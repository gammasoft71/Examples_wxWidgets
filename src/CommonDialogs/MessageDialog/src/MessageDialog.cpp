#include <wx/wx.h>

class Frame : public wxFrame {
public:
  Frame() : wxFrame(nullptr, wxID_ANY, "MessageDialog example", wxDefaultPosition, {300, 300}) {
    buttonShowMessage->Bind(wxEVT_BUTTON, [&](wxCommandEvent& event) {
      labelDialogResult->SetLabelText("Result = ");
      wxMessageDialog messageDialog(this, "Hello, World!", "Message", wxOK | wxCANCEL);
      int result = messageDialog.ShowModal();
      labelDialogResult->SetLabelText(wxString::Format("Result = %s", result == wxID_OK ? "wxOK" : "wxCANCEL"));
    });
  }
  
private:
  wxPanel* panel = new wxPanel(this);
  wxButton* buttonShowMessage = new wxButton(panel, wxID_ANY, "Message...", {10, 10});
  wxStaticText* labelDialogResult = new wxStaticText(panel, wxID_ANY, "Result = ", wxPoint(10, 45));
};

class Application : public wxApp {
  bool OnInit() override {(new Frame())->Show(); return true;}
};

wxIMPLEMENT_APP(Application);
