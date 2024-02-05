#include <wx/app.h>
#include <wx/button.h>
#include <wx/checkbox.h>
#include <wx/frame.h>
#include <wx/panel.h>
#include <wx/richtooltip.h>
#include <wx/stattext.h>

namespace ToolTipExample {
  class Frame : public wxFrame {
  public:
    Frame() : wxFrame {nullptr, wxID_ANY, "TooTip example"} {
      button->SetToolTip("button toolTip...");
      check->SetToolTip("check toolTip...");
      label->SetToolTip("label toolTip...");
    }
    
  private:
    wxPanel* panel = new wxPanel {this};
    wxButton* button = new wxButton {panel, wxID_ANY, "button", {10, 10}};
    wxCheckBox* check = new wxCheckBox {panel, wxID_ANY, "check", {10, 40}};
    wxStaticText* label = new wxStaticText {panel, wxID_ANY, "label", {10, 70}};
  };

  class Application : public wxApp {
    bool OnInit() override {return (new Frame)->Show();}
  };
}

wxIMPLEMENT_APP(ToolTipExample::Application);
