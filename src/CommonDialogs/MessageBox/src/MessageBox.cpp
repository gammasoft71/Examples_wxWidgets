#include <wx/wx.h>

class Frame : public wxFrame {
public:
  Frame() : wxFrame(nullptr, wxID_ANY, "MessageBox example", wxDefaultPosition, wxSize(300, 300)) {
    buttonShowMessage->Bind(wxEVT_BUTTON, [&](wxCommandEvent& event) {
      wxMessageDialog messageDialog(this, "Hello, World!", "Message", wxOK | wxCANCEL);
      int dialogResult = messageDialog.ShowModal();
      labelDialogResult->SetLabelText(wxString::Format("DialogResult = %s", dialogResult == wxID_OK ? "wxOK" : "wxCANCEL"));
    });
  }
  
private:
  wxPanel* panel = new wxPanel(this);
  wxButton* buttonShowMessage = new wxButton(panel, wxID_ANY, "Message...", wxPoint(10, 10));
  wxStaticText* labelDialogResult = new wxStaticText(panel, wxID_ANY, wxEmptyString, wxPoint(10, 45));
};

class Application : public wxApp {
  bool OnInit() override {(new Frame())->Show(); return true;}
};

wxIMPLEMENT_APP(Application);
