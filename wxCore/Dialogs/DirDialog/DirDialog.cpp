#include <wx/app.h>
#include <wx/button.h>
#include <wx/dirdlg.h>
#include <wx/frame.h>
#include <wx/panel.h>
#include <wx/stattext.h>
#include <wx/stdpaths.h>

namespace DirDialogExample {
  class Frame : public wxFrame {
  public:
    Frame() : wxFrame(nullptr, wxID_ANY, "DirDialog example") {
      button->Bind(wxEVT_BUTTON, [&](wxCommandEvent& event) {
        auto folderBrowserDialog = wxDirDialog {this, wxEmptyString};
        folderBrowserDialog.SetPath(wxStandardPaths::Get().GetDocumentsDir());
        if (folderBrowserDialog.ShowModal() == wxID_OK)
          label->SetLabel(wxString::Format("Path = %s", folderBrowserDialog.GetPath()));
      });
    }
    
  private:
    wxPanel* panel = new wxPanel {this};
    wxButton* button = new wxButton {panel, wxID_ANY, "Folder...", {10, 10}};
    wxStaticText* label = new wxStaticText {panel, wxID_ANY, "Path = ", {10, 40}};
  };

  class Application : public wxApp {
    bool OnInit() override {return (new Frame)->Show();}
  };
}

wxIMPLEMENT_APP(DirDialogExample::Application);
