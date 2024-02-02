#include <wx/wx.h>
#include <wx/dirdlg.h>
#include <wx/stdpaths.h>

namespace DirDialogExample {
  class Frame : public wxFrame {
  public:
    Frame() : wxFrame(nullptr, wxID_ANY, "DirDialog example") {
      button->Bind(wxEVT_BUTTON, [&](wxCommandEvent& event) {
        wxDirDialog folderBrowserDialog(this, wxEmptyString);
        folderBrowserDialog.SetPath(wxStandardPaths::Get().GetDocumentsDir());
        if (folderBrowserDialog.ShowModal() == wxID_OK)
          label->SetLabel(wxString::Format("Path = %s", folderBrowserDialog.GetPath()));
      });
    }
    
  private:
    wxPanel* panel = new wxPanel {this};
    wxButton* button = new wxButton(panel, wxID_ANY, "Folder...", {10, 10});
    wxStaticText* label = new wxStaticText(panel, wxID_ANY, "Path = ", {10, 40});
  };

  class Application : public wxApp {
    bool OnInit() override {
      (new Frame)->Show();
      return true;
    }
  };
}

wxIMPLEMENT_APP(DirDialogExample::Application);
