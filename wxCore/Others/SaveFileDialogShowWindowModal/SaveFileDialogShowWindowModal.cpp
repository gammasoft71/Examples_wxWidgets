#include <wx/wx.h>
#include <wx/filedlg.h>
#include <wx/windowptr.h>

// Workaround : with wxWidgets version <= 3.2.0 wxFileDialog ShowWindowModal method doesn't exists on other platform that macOS
#if defined(__APPLE__)
using FileDialog = wxFileDialog;
#else
class FileDialog : public wxFileDialog {
public:
  FileDialog(wxWindow *parent, const wxString& message = wxFileSelectorPromptStr, const wxString& defaultDir = wxEmptyString, const wxString& defaultFile = wxEmptyString, const wxString& wildCard = wxFileSelectorDefaultWildcardStr, long style = wxFD_DEFAULT_STYLE, const wxPoint& pos = wxDefaultPosition, const wxSize& sz = wxDefaultSize, const wxString& name = wxFileDialogNameStr) : wxFileDialog(parent, message, defaultDir, defaultFile, wildCard, style, pos, sz, name) {}
  void ShowWindowModal() {
    SetReturnCode(ShowModal());
    wxWindowModalDialogEvent event(wxEVT_WINDOW_MODAL_DIALOG_CLOSED, this->GetId());
    event.SetEventObject(this);
    wxPostEvent(this, event);
  }
};
#endif

namespace SaveFileDialogShowWindowModalExample {
  class Frame : public wxFrame {
  public:
    Frame() : wxFrame(nullptr, wxID_ANY, "SaveFileDialog (ShowWindowModal) example") {
      button->Bind(wxEVT_BUTTON, [&](wxCommandEvent& event) {
        wxWindowPtr<FileDialog> saveFileDialog(new FileDialog(this, wxEmptyString, "", "MyFile.txt", "Text Files (*.txt)|*.txt|All Files (*.*)|*.*", wxFD_SAVE));
        saveFileDialog->ShowWindowModal();
        saveFileDialog->Bind(wxEVT_WINDOW_MODAL_DIALOG_CLOSED, [this, saveFileDialog](wxWindowModalDialogEvent& event) {
          if (event.GetReturnCode() == wxID_OK) {
            label->SetLabelText(wxString::Format("File = %s",  saveFileDialog->GetPath()));
          }
        });
      });
    }

  private:
    wxPanel* panel = new wxPanel {this};
    wxButton* button = new wxButton(panel, wxID_ANY, "Save...", {10, 10});
    wxStaticText* label = new wxStaticText(panel, wxID_ANY, "", {10, 40});
  };

  class Application : public wxApp {
    bool OnInit() override {
      (new Frame)->Show();
      return true;
    }
  };
}

wxIMPLEMENT_APP(SaveFileDialogShowWindowModalExample::Application);
