#include <wx/app.h>
#include <wx/frame.h>
#include <wx/panel.h>
#include <wx/filectrl.h>
#include <wx/stdpaths.h>

namespace Examples {
  class Frame : public wxFrame {
  public:
    Frame() : wxFrame(nullptr, wxID_ANY, "FileCtrl example") {
      SetClientSize({800, 450});
      fileCtrl1->SetPosition({10, 10});
      fileCtrl1->SetSize({780, 430});
    }
    
  private:
    wxPanel* panel = new wxPanel(this);
    wxFileCtrl* fileCtrl1 = new wxFileCtrl(panel, wxID_ANY, wxStandardPaths::Get().GetDocumentsDir(), wxEmptyString, "Text Files (*.txt)|*.txt|All Files (*.*)|*.*", wxFC_DEFAULT_STYLE);
  };

  class Application : public wxApp {
    bool OnInit() override {
      (new Frame())->Show();
      return true;
    }
  };
}

wxIMPLEMENT_APP(Examples::Application);
