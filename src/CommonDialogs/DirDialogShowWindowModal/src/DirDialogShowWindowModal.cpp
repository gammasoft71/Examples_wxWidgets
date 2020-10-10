#include <wx/wx.h>
#include <wx/dirdlg.h>
#include <wx/stdpaths.h>
#include <wx/windowptr.h>

// Workaround : with wxWidgets version <= 3.1.4 wxDirDialog ShowWindowModal method doesn't exists on other platform that macOS
#if defined(__APPLE__)
using DirDialog = wxDirDialog;
#else
class DirDialog : public wxDirDialog {
public:
  DirDialog(wxWindow *parent, const wxString& message = wxDirSelectorPromptStr, const wxString& defaultPath = "", long style = wxDD_DEFAULT_STYLE, const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxDefaultSize, const wxString& name = wxDirDialogNameStr) : wxDirDialog(parent, message, defaultPath, style, pos, size, name) {}
  void ShowWindowModal() {
    ShowModal();
    wxWindowModalDialogEvent event(wxEVT_WINDOW_MODAL_DIALOG_CLOSED, this->GetId());
    event.SetEventObject(this);
    wxPostEvent(this, event);
  }
};
#endif

namespace Examples {
  class Frame : public wxFrame {
  public:
    Frame() : wxFrame(nullptr, wxID_ANY, "DirDialog (ShowWindowModal) example", wxDefaultPosition, {300, 300}) {
      button->Bind(wxEVT_BUTTON, [&](wxCommandEvent& event) {
        wxWindowPtr<DirDialog> folderBrowserDialog(new DirDialog(this, wxEmptyString));
        folderBrowserDialog->SetPath(wxStandardPaths::Get().GetDocumentsDir());
        folderBrowserDialog->ShowWindowModal();
        folderBrowserDialog->Bind(wxEVT_WINDOW_MODAL_DIALOG_CLOSED, [this,folderBrowserDialog](wxWindowModalDialogEvent& event) {
          if (event.GetReturnCode() == wxID_OK)
            label->SetLabel(wxString::Format("Path = %s", folderBrowserDialog->GetPath()));
        });
      });
    }
    
  private:
    wxPanel* panel = new wxPanel(this);
    wxButton* button = new wxButton(panel, wxID_ANY, "Folder...", {10, 10});
    wxStaticText* label = new wxStaticText(panel, wxID_ANY, "Path = ", {10, 40});
  };

  class Application : public wxApp {
    bool OnInit() override {
      (new Frame())->Show();
      return true;
    }
  };
}

wxIMPLEMENT_APP(Examples::Application);
