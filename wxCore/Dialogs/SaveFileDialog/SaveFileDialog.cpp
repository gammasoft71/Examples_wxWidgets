#include <wx/app.h>
#include <wx/button.h>
#include <wx/filedlg.h>
#include <wx/frame.h>
#include <wx/panel.h>
#include <wx/stattext.h>

namespace SaveFileDialogExample {
  class Frame : public wxFrame {
  public:
    Frame() : wxFrame {nullptr, wxID_ANY, "SaveFileDialog example"} {
      button->Bind(wxEVT_BUTTON, [&](wxCommandEvent& event) {
        auto saveFileDialog = wxFileDialog {this, wxEmptyString, wxEmptyString, "MyFile.txt", "Text Files (*.txt)|*.txt|All Files (*.*)|*.*", wxFD_SAVE};
        if (saveFileDialog.ShowModal() == wxID_OK) {
          label->SetLabelText(wxString::Format("File = %s", saveFileDialog.GetPath()));
        }
      });
    }

  private:
    wxPanel* panel = new wxPanel {this};
    wxButton* button = new wxButton {panel, wxID_ANY, "Save...", {10, 10}};
    wxStaticText* label = new wxStaticText {panel, wxID_ANY, "", {10, 40}};
  };

  class Application : public wxApp {
    bool OnInit() override {return (new Frame)->Show();}
  };
}

wxIMPLEMENT_APP(SaveFileDialogExample::Application);
