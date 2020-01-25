#include <wx/wx.h>
#include <wx/filepicker.h>

namespace Examples {
  class Frame : public wxFrame {
  public:
    Frame() : wxFrame(nullptr, wxID_ANY, "FilePickerCtrl example", wxDefaultPosition, {300, 300}) {
      picker->Bind(wxEVT_FILEPICKER_CHANGED, [&](wxFileDirPickerEvent& event) {
        label->SetLabel(wxString::Format("File = %s", event.GetPath()));
      });
    }
    
  private:
    wxPanel* panel = new wxPanel(this);
    wxStaticText* label = new wxStaticText(panel, wxID_ANY, "File = ", wxPoint(10, 50));
    wxFilePickerCtrl* picker = new wxFilePickerCtrl(panel, wxID_ANY, wxEmptyString, wxEmptyString, "Text Files (*.txt)|*.txt|All Files (*.*)|*.*", {10, 10}, wxDefaultSize, wxFLP_DEFAULT_STYLE|wxFLP_SMALL);
  };

  class Application : public wxApp {
    bool OnInit() override {
      (new Frame())->Show();
      return true;
    }
  };
}

wxIMPLEMENT_APP(Examples::Application);
