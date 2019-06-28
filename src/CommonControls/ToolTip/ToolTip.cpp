#include <wx/wx.h>
#include <wx/richtooltip.h>

class Form : public wxFrame {
public:
  Form() : wxFrame(nullptr, wxID_ANY, "TooTip example", wxDefaultPosition, wxSize(300, 300)) {

    this->button->Bind(wxEVT_MOTION, [&](wxMouseEvent& event) {
      wxRichToolTip toolTipButton {"ToolTip title", "button toolTip..."};
      toolTipButton.ShowFor(this->button);
    });
    
    this->check->SetToolTip("check toolTip...");
    this->label->SetToolTip("label toolTip...");
  }
  
private:
  wxPanel* panel = new wxPanel(this);
  wxButton* button = new wxButton(this->panel, wxID_ANY, "button", wxPoint(10, 10));
  wxCheckBox* check = new wxCheckBox(this->panel, wxID_ANY, "check", wxPoint(10, 40));
  wxStaticText* label = new wxStaticText(this->panel, wxID_ANY, "label", wxPoint(10, 70));
};

class Application : public wxApp {
  bool OnInit() override {return (new Form())->Show();}
};

wxIMPLEMENT_APP(Application);
