#include <wx/wx.h>

class Form : public wxFrame {
public:
  Form() : wxFrame(nullptr, wxID_ANY, "MessageBox example", wxDefaultPosition, wxSize(300, 300)) {
    this->buttonShowMessage->Bind(wxEVT_BUTTON, [&](wxCommandEvent& event) {
      int dialogResult = wxMessageBox("Hello, World!", "Message", wxOK | wxCANCEL, this);
      this->labelDialogResult->SetLabelText(wxString::Format("DialogResult = %s", dialogResult == wxOK ? "wxOK" : "wxCANCEL"));
    });
    this->Show();
  }
  
private:
  wxPanel* panel = new wxPanel(this);
  wxButton* buttonShowMessage = new wxButton(this->panel, wxID_ANY, "Message...", wxPoint(10, 10));
  wxStaticText* labelDialogResult = new wxStaticText(this->panel, wxID_ANY, "", wxPoint(10, 45));
};

class Application : public wxApp {
public:
  bool OnInit() override {new Form(); return true;}
};

wxIMPLEMENT_APP(Application);