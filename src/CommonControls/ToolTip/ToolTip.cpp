#include <wx/wx.h>
#include <wx/richtooltip.h>

class Frame : public wxFrame {
public:
  Frame() : wxFrame(nullptr, wxID_ANY, "TooTip example", wxDefaultPosition, wxSize(300, 300)) {

    button->Bind(wxEVT_MOTION, [&](wxMouseEvent& event) {
      wxRichToolTip toolTipButton {"ToolTip title", "button toolTip..."};
      toolTipButton.ShowFor(button);
    });
    
    check->SetToolTip("check toolTip...");
    label->SetToolTip("label toolTip...");
  }
  
private:
  wxPanel* panel = new wxPanel(this);
  wxButton* button = new wxButton(panel, wxID_ANY, "button", wxPoint(10, 10));
  wxCheckBox* check = new wxCheckBox(panel, wxID_ANY, "check", wxPoint(10, 40));
  wxStaticText* label = new wxStaticText(panel, wxID_ANY, "label", wxPoint(10, 70));
};

class Application : public wxApp {
  bool OnInit() override {(new Frame())->Show(); return true;}
};

wxIMPLEMENT_APP(Application);
