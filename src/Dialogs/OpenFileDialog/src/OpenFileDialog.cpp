#include <wx/wx.h>
#include <wx/filedlg.h>

class Form : public wxFrame {
public:
  Form() : wxFrame(nullptr, wxID_ANY, "OpenFileDialog example", wxDefaultPosition, wxSize(300, 300)) {
    this->button->Bind(wxEVT_BUTTON, [&](wxCommandEvent& event) {
      wxFileDialog openFileDialog(this, wxEmptyString, "", "", "Text Files (*.txt)|*.txt|All Files (*.*)|*.*", wxFD_OPEN|wxFD_FILE_MUST_EXIST);
      if (openFileDialog.ShowModal()) {
        this->label->SetLabelText(wxString::Format("File = %s",  openFileDialog.GetPath()));
      }
    });
  }

private:
  wxPanel* panel = new wxPanel(this);
  wxButton* button = new wxButton(this->panel, wxID_ANY, "Open...", wxPoint(10, 10));
  wxStaticText* label = new wxStaticText(this->panel, wxID_ANY, "", wxPoint(10, 40));
};

class Application : public wxApp {
  bool OnInit() override {return (new Form())->Show();}
};

wxIMPLEMENT_APP(Application);
