#include <wx/wx.h>
#include <wx/dirdlg.h>
#include <wx/stdpaths.h>

class Form : public wxFrame {
public:
  Form() : wxFrame(nullptr, wxID_ANY, "FolderBrowserDialog example", wxDefaultPosition, wxSize(300, 300)) {
    this->button->Bind(wxEVT_BUTTON, [&](wxCommandEvent& event) {
      wxDirDialog folderBrowserDialog(this, "");
      folderBrowserDialog.SetPath(wxStandardPaths::Get().GetDocumentsDir());
      if (folderBrowserDialog.ShowModal())
        this->label->SetLabel(wxString::Format("Path = %s", folderBrowserDialog.GetPath()));
    });
    
    this->Show();
  }
  
private:
  wxPanel* panel = new wxPanel(this);
  wxButton* button = new wxButton(this->panel, wxID_ANY, "Folder...", wxPoint(10, 10));
  wxStaticText* label = new wxStaticText(this->panel, wxID_ANY, "Path = ", wxPoint(10, 40));
};

class Application : public wxApp {
public:
  bool OnInit() override {new Form(); return true;}
};

wxIMPLEMENT_APP(Application);
