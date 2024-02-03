#include <wx/app.h>
#include <wx/frame.h>
#include <wx/panel.h>
#include <wx/sizer.h>
#include <wx/radiobut.h>
#include <wx/stattext.h>

namespace RadioButtonExample {
  class Frame : public wxFrame {
  public:
    Frame() : wxFrame(nullptr, wxID_ANY, "RadioButton example") {
      radioButton1->SetValue(true);
      Bind(wxEVT_RADIOBUTTON, [&](wxCommandEvent& event) {
        staticText1->SetLabel(wxString::Format("radioButton3 state = %s", radioButton3->GetValue() ? "true" : "false"));
      });
      
      staticText1->SetLabel(wxString::Format("radioButton3 state = %s", radioButton3->GetValue() ? "true" : "false"));
    }
    
  private:
    wxPanel* panel = new wxPanel {this};
    wxRadioButton* radioButton1 = new wxRadioButton(panel, wxID_ANY, "radioButton 1", {30, 30});
    wxRadioButton* radioButton2 = new wxRadioButton(panel, wxID_ANY, "radioButton 2", {30, 60});
    wxRadioButton* radioButton3 = new wxRadioButton(panel, wxID_ANY, "radioButton 3", {30, 90});
    wxStaticText* staticText1 = new wxStaticText(panel, wxID_ANY, wxEmptyString, {30, 150});
  };

  class Application : public wxApp {
    bool OnInit() override {return (new Frame)->Show();}
  };
}

wxIMPLEMENT_APP(RadioButtonExample::Application);
