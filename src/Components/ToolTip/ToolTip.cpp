#include <wx/wx.h>
#include <wx/richtooltip.h>

namespace Examples {
  class Frame : public wxFrame {
  public:
    Frame() : wxFrame(nullptr, wxID_ANY, "TooTip example", wxDefaultPosition, {300, 300}) {

      button->SetToolTip("button toolTip...");
      check->SetToolTip("check toolTip...");
      label->SetToolTip("label toolTip...");
    }
    
  private:
    wxPanel* panel = new wxPanel(this);
    wxButton* button = new wxButton(panel, wxID_ANY, "button", {10, 10});
    wxCheckBox* check = new wxCheckBox(panel, wxID_ANY, "check", {10, 40});
    wxStaticText* label = new wxStaticText(panel, wxID_ANY, "label", {10, 70});
  };

  class Application : public wxApp {
    bool OnInit() override {
      (new Frame())->Show();
      return true;
    }
  };
}

wxIMPLEMENT_APP(Examples::Application);
