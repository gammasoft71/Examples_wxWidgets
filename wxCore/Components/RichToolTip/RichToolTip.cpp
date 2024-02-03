#include <wx/wx.h>
#include <wx/richtooltip.h>

namespace RichTooolTipExample {
  class Frame : public wxFrame {
  public:
    Frame() : wxFrame(nullptr, wxID_ANY, "TooTip example") {
      button->Bind(wxEVT_ENTER_WINDOW, [&](wxMouseEvent& event) {
        wxRichToolTip toolTipButton("ToolTip title", "button toolTip...");
        toolTipButton.ShowFor(button);
      });
      
      check->Bind(wxEVT_ENTER_WINDOW, [&](wxMouseEvent& event) {
        wxRichToolTip toolTipCheck("ToolTip title", "check toolTip..." );
        toolTipCheck.ShowFor(check);
      });
      
      label->Bind(wxEVT_ENTER_WINDOW, [&](wxMouseEvent& event) {
        wxRichToolTip toolTipLabel("ToolTip title", "label toolTip...");
        toolTipLabel.SetIcon(wxICON_WARNING);
        toolTipLabel.ShowFor(label);
      });
    }
    
  private:
    wxPanel* panel = new wxPanel {this};
    wxButton* button = new wxButton(panel, wxID_ANY, "button", {10, 10});
    wxCheckBox* check = new wxCheckBox(panel, wxID_ANY, "check", {10, 40});
    wxStaticText* label = new wxStaticText(panel, wxID_ANY, "label", {10, 70});
  };

  class Application : public wxApp {
    bool OnInit() override {return (new Frame)->Show();}
  };
}

wxIMPLEMENT_APP(RichTooolTipExample::Application);
