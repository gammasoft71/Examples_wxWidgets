#include <wx/wx.h>
#include <wx/dirdlg.h>
#include <wx/stdpaths.h>

class Form : public wxFrame {
public:
  Form() : wxFrame(nullptr, wxID_ANY, "FolderBrowserDialog example", wxDefaultPosition, wxSize(300, 300)) {
    this->button.Bind(wxEVT_BUTTON, [&](wxCommandEvent& event) {
      wxDirDialog folderBrowserDialog(this, wxEmptyString);
      folderBrowserDialog.SetPath(wxStandardPaths::Get().GetDocumentsDir());
      if (folderBrowserDialog.ShowModal())
        this->label.SetLabel(wxString::Format("Path = %s", folderBrowserDialog.GetPath()));
    });
  }
  
private:
  wxPanel panel {this};
  wxButton button {&this->panel, wxID_ANY, "Folder...", wxPoint(10, 10)};
  wxStaticText label {&this->panel, wxID_ANY, "Path = ", wxPoint(10, 40)};
};

class Application : public wxApp {
  bool OnInit() override {return (new Form())->Show();}
};

wxIMPLEMENT_APP(Application);
