#include <wx/wx.h>
#include <wx/filedlg.h>

class Form : public wxFrame {
public:
  Form() : wxFrame(nullptr, wxID_ANY, "SaveFileDialog example", wxDefaultPosition, wxSize(300, 300)) {
    this->button->Bind(wxEVT_BUTTON, [&](wxCommandEvent& event) {
      wxFileDialog saveFileDialog(this, wxEmptyString, "", "MyFile.txt", "Text Files (*.txt)|*.txt|All Files (*.*)|*.*", wxFD_SAVE);
      if (saveFileDialog.ShowModal()) {
        this->label->SetLabelText(wxString::Format("File = %s",  saveFileDialog.GetPath()));
      }
    });
  }

private:
  wxPanel* panel = new wxPanel(this);
  wxButton* button = new wxButton(this->panel, wxID_ANY, "Save...", wxPoint(10, 10));
  wxStaticText* label = new wxStaticText(this->panel, wxID_ANY, "", wxPoint(10, 40));
};

class Application : public wxApp {
  bool OnInit() override {return (new Form())->Show();}
};

wxIMPLEMENT_APP(Application);
