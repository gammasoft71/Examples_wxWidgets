#include <wx/wx.h>

class Form : public wxFrame {
public:
  Form() : wxFrame(nullptr, wxID_ANY, "RadioButton example", wxDefaultPosition, wxSize(300, 300)) {
    this->radioButton1->SetValue(true);
    this->Bind(wxEVT_RADIOBUTTON, [&](wxCommandEvent& event) {
      this->label1->SetLabel(wxString::Format("radioButton3 state = %s", this->radioButton3->GetValue() ? "true" : "false"));
    });
    
    this->label1->SetLabel(wxString::Format("radioButton3 state = %s", this->radioButton3->GetValue() ? "true" : "false"));
  }
  
private:
  wxPanel* panel = new wxPanel(this);
  wxRadioButton* radioButton1 = new wxRadioButton(this->panel, wxID_ANY, "radioButton 1", wxPoint(30, 30));
  wxRadioButton* radioButton2 = new wxRadioButton(this->panel, wxID_ANY, "radioButton 2", wxPoint(30, 60));
  wxRadioButton* radioButton3 = new wxRadioButton(this->panel, wxID_ANY, "radioButton 3", wxPoint(30, 90));
  wxStaticText* label1 = new wxStaticText(this->panel, wxID_ANY, wxEmptyString, wxPoint(30, 150));
};

class Application : public wxApp {
  bool OnInit() override {return (new Form())->Show();}
};

wxIMPLEMENT_APP(Application);
