#include <wx/app.h>
#include <wx/frame.h>
#include <wx/panel.h>
#include <wx/stattext.h>
#include <wx/stdpaths.h>
#include <wx/dirctrl.h>

namespace DirCtrlExample {
  class Frame : public wxFrame {
  public:
    Frame() : wxFrame {nullptr, wxID_ANY, "DirCtrl example"} {
      SetClientSize({350, 450});
      dirCtrl1->SetPosition({10, 10});
      dirCtrl1->SetSize({330, 390});
      dirCtrl1->Bind(wxEVT_DIRCTRL_SELECTIONCHANGED, [&](wxTreeEvent& event) {
        staticText1->SetLabel(dirCtrl1->GetPath());
      });
      dirCtrl1->SetPath(wxStandardPaths::Get().GetDocumentsDir());
    }
    
  private:
    wxPanel* panel = new wxPanel {this};
    wxGenericDirCtrl* dirCtrl1 = new wxGenericDirCtrl {panel, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxDIRCTRL_DIR_ONLY|wxDIRCTRL_EDIT_LABELS};
    wxStaticText* staticText1 = new wxStaticText {panel, wxID_ANY, "", {10, 410}};
  };

  class Application : public wxApp {
    bool OnInit() override {return (new Frame)->Show();}
  };
}

wxIMPLEMENT_APP(DirCtrlExample::Application);
