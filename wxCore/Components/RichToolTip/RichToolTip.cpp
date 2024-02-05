#include <wx/app.h>
#include <wx/button.h>
#include <wx/checkbox.h>
#include <wx/frame.h>
#include <wx/panel.h>
#include <wx/richtooltip.h>
#include <wx/stattext.h>

namespace RichTooolTipExample {
  class Frame : public wxFrame {
  public:
    Frame() : wxFrame {nullptr, wxID_ANY, "TooTip example"} {
      button->Bind(wxEVT_ENTER_WINDOW, [&](wxMouseEvent& event) {
        auto toolTip = wxRichToolTip {"ToolTip title", "button toolTip..."};
        toolTip.ShowFor(button);
      });
      
      check->Bind(wxEVT_ENTER_WINDOW, [&](wxMouseEvent& event) {
        auto toolTip = wxRichToolTip {"ToolTip title", "check toolTip..." };
        toolTip.SetIcon();
        toolTip.ShowFor(check);
      });
      
      label->Bind(wxEVT_ENTER_WINDOW, [&](wxMouseEvent& event) {
        auto toolTip = wxRichToolTip {"ToolTip title", "label toolTip..."};
        toolTip.SetIcon(wxICON_WARNING);
        toolTip.ShowFor(label);
      });
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

wxIMPLEMENT_APP(RichTooolTipExample::Application);
