#include <wx/app.h>
#include <wx/frame.h>
#include <wx/panel.h>
#include <wx/stattext.h>
#include <wx/stdpaths.h>

// Workaround : with wxWidgets version <= 3.1.4 when showHidden is set the check box is not set
#if __WXGTK__
#include <wx/filectrl.h>
using FileCtrl = wxFileCtrl;
#else
#define private public
#include <wx/filectrl.h>
#undef private
#include <wx/checkbox.h>
class FileCtrl : public wxFileCtrl {
public:
  FileCtrl(wxWindow*parent, wxWindowID id, const wxString& defaultDirectory = wxEmptyString, const wxString& defaultFilename = wxEmptyString, const wxString& wildCard = wxFileSelectorDefaultWildcardStr, long style = wxFC_DEFAULT_STYLE, const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxDefaultSize, const wxString& name = wxFileCtrlNameStr) : wxFileCtrl(parent, id, defaultDirectory, defaultFilename, wildCard, style, pos, size, name) {
    // Workaround : with wxWidgets version <= 3.1.4 folder, exacutable and link are set with specific color (respectively Blue, red and middle gray) on macOS (not standard)
#if __APPLE__
    for (int i = 0; i < GetFileList()->GetItemCount(); i++)
      GetFileList()->SetItemTextColour(i, GetForegroundColour());
    GetFileList()->Bind(wxEVT_LIST_INSERT_ITEM, [&](wxListEvent& event) {
      GetFileList()->SetItemTextColour(event.GetIndex(), GetForegroundColour());
    });
#endif
  }
  
  void ShowHidden(bool show) override {
    m_check->SetValue(show);
    wxFileCtrl::ShowHidden(show);
  }
};
#endif

namespace Examples {
  class Frame : public wxFrame {
  public:
    Frame() : wxFrame(nullptr, wxID_ANY, "FileCtrl example") {
      SetClientSize({800, 450});
      fileCtrl1->SetPosition({10, 10});
      fileCtrl1->SetSize({780, 390});
      //fileCtrl1->ShowHidden(true);
      fileCtrl1->Bind(wxEVT_FILECTRL_FILEACTIVATED, [&](wxFileCtrlEvent& event) {
        staticText1->SetLabel(fileCtrl1->GetFilename());
      });
    }
    
  private:
    wxPanel* panel = new wxPanel(this);
    FileCtrl* fileCtrl1 = new FileCtrl(panel, wxID_ANY, wxStandardPaths::Get().GetDocumentsDir(), wxEmptyString, "Text Files (*.txt)|*.txt|All Files (*.*)|*.*", wxFC_DEFAULT_STYLE);
    wxStaticText* staticText1 = new wxStaticText(panel, wxID_ANY, "", {10, 410});
  };

  class Application : public wxApp {
    bool OnInit() override {
      (new Frame())->Show();
      return true;
    }
  };
}

wxIMPLEMENT_APP(Examples::Application);
