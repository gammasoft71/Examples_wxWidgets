#include <wx/wx.h>
#include <wx/filedlg.h>

class Frame : public wxFrame {
public:
  Frame() : wxFrame(nullptr, wxID_ANY, "SaveFileDialog example", wxDefaultPosition, {300, 300}) {
    button->Bind(wxEVT_BUTTON, [&](wxCommandEvent& event) {
      wxFileDialog saveFileDialog(this, wxEmptyString, "", "MyFile.txt", "Text Files (*.txt)|*.txt|All Files (*.*)|*.*", wxFD_SAVE);
      if (saveFileDialog.ShowModal()) {
        label->SetLabelText(wxString::Format("File = %s",  saveFileDialog.GetPath()));
      }
    });
  }

private:
  wxPanel* panel = new wxPanel(this);
  wxButton* button = new wxButton(panel, wxID_ANY, "Save...", {10, 10});
  wxStaticText* label = new wxStaticText(panel, wxID_ANY, "", wxPoint(10, 40));
};

class Application : public wxApp {
  bool OnInit() override {(new Frame())->Show(); return true;}
};

wxIMPLEMENT_APP(Application);
