#include <wx/app.h>
#include <wx/filepicker.h>
#include <wx/frame.h>
#include <wx/panel.h>
#include <wx/stattext.h>

namespace DirPickerCtrlExample {
  class Frame : public wxFrame {
  public:
    Frame() : wxFrame {nullptr, wxID_ANY, "DirPickerCtrl example"} {
      picker->Bind(wxEVT_DIRPICKER_CHANGED, [&](wxFileDirPickerEvent& event) {
        label->SetLabel(wxString::Format("Path = %s", event.GetPath()));
      });
    }
    
  private:
    wxPanel* panel = new wxPanel {this};
    wxStaticText* label = new wxStaticText {panel, wxID_ANY, "Path = ", wxPoint(10, 50)};
    wxDirPickerCtrl* picker = new wxDirPickerCtrl {panel, wxID_ANY, wxEmptyString, wxEmptyString, {10, 10}, wxDefaultSize, wxDIRP_DEFAULT_STYLE|wxDIRP_SMALL};
  };

  class Application : public wxApp {
    bool OnInit() override {return (new Frame)->Show();}
  };
}

wxIMPLEMENT_APP(DirPickerCtrlExample::Application);
