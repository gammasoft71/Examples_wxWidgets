#include <wx/wx.h>
#include <wx/filepicker.h>

class Form : public wxFrame {
public:
  Form() : wxFrame(nullptr, wxID_ANY, "FilePicker example", wxDefaultPosition, wxSize(300, 300)) {
    picker->Bind(wxEVT_FILEPICKER_CHANGED, [this](wxFileDirPickerEvent& event) {
      label->SetLabel(wxString::Format("File = %s", event.GetPath()));
    });
  }
  
private:
  wxPanel* panel = new wxPanel(this);
  wxStaticText* label = new wxStaticText(panel, wxID_ANY,
    "File = ", wxPoint(10, 50));
  wxFilePickerCtrl* picker = new wxFilePickerCtrl(panel, wxID_ANY, wxEmptyString, wxEmptyString, "Text Files (*.txt)|*.txt|All Files (*.*)|*.*", {10, 10});
};

class Application : public wxApp {
  bool OnInit() override {(new Form())->Show(); return true;}
};

wxIMPLEMENT_APP(Application);
