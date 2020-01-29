#include <wx/wx.h>
#include <wx/filedlg.h>
#include <wx/sysopt.h>

namespace Examples {
  class Frame : public wxFrame {
  public:
    Frame() : wxFrame(nullptr, wxID_ANY, "OpenFileDialog example", wxDefaultPosition, {300, 300}) {
      button->Bind(wxEVT_BUTTON, [&](wxCommandEvent& event) {
        wxFileDialog openFileDialog(this, wxEmptyString, wxEmptyString, wxEmptyString, "Text Files (*.txt)|*.txt|All Files (*.*)|*.*", wxFD_OPEN|wxFD_FILE_MUST_EXIST);
        openFileDialog.SetFilterIndex(0);
        if (openFileDialog.ShowModal() == wxID_OK) {
          label->SetLabelText(wxString::Format("File = %s",  openFileDialog.GetPath()));
        }
      });
    }

  private:
    wxPanel* panel = new wxPanel(this);
    wxButton* button = new wxButton(panel, wxID_ANY, "Open...", {10, 10});
    wxStaticText* label = new wxStaticText(panel, wxID_ANY, "", {10, 40});
  };

  class Application : public wxApp {
    bool OnInit() override {
      wxSystemOptions::SetOption("osx.openfiledialog.always-show-types", 1);
      (new Frame())->Show();
      return true;
    }
  };
}

wxIMPLEMENT_APP(Examples::Application);
