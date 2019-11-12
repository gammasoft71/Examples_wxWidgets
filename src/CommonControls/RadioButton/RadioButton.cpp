#include <wx/app.h>
#include <wx/frame.h>
#include <wx/panel.h>
#include <wx/sizer.h>
#include <wx/radiobut.h>
#include <wx/stattext.h>

class Frame : public wxFrame {
public:
  Frame() : wxFrame(nullptr, wxID_ANY, "RadioButton example", wxDefaultPosition, wxSize(300, 300)) {
    radioButton1->SetValue(true);
    Bind(wxEVT_RADIOBUTTON, [&](wxCommandEvent& event) {
      staticText1->SetLabel(wxString::Format("radioButton3 state = %s", radioButton3->GetValue() ? "true" : "false"));
    });
    
    staticText1->SetLabel(wxString::Format("radioButton3 state = %s", radioButton3->GetValue() ? "true" : "false"));
  }
  
private:
  wxPanel* panel = new wxPanel(this);
  wxRadioButton* radioButton1 = new wxRadioButton(panel, wxID_ANY, "radioButton 1", wxPoint(30, 30));
  wxRadioButton* radioButton2 = new wxRadioButton(panel, wxID_ANY, "radioButton 2", wxPoint(30, 60));
  wxRadioButton* radioButton3 = new wxRadioButton(panel, wxID_ANY, "radioButton 3", wxPoint(30, 90));
  wxStaticText* staticText1 = new wxStaticText(panel, wxID_ANY, wxEmptyString, wxPoint(30, 150));
};

class Application : public wxApp {
  bool OnInit() override {(new Frame())->Show(); return true;}
};

wxIMPLEMENT_APP(Application);
