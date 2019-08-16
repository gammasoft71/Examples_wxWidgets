#include <wx/wx.h>

class Form : public wxFrame {
public:
  Form() : wxFrame(nullptr, wxID_ANY, "CheckBox example", wxDefaultPosition, wxSize(300, 300)) {
    this->checkBox1->Set3StateValue(wxCHK_CHECKED);
    this->checkBox2->Set3StateValue(wxCHK_UNCHECKED);
    this->checkBox3->Set3StateValue(wxCHK_UNDETERMINED);
    this->checkBox3->Bind(wxEVT_CHECKBOX, [&](wxCommandEvent& event) {
      this->label1->SetLabel(wxString::Format("checkBox3 state = %s", ToString(this->checkBox3->Get3StateValue())));
    });

    this->label1->SetLabel(wxString::Format("checkBox3 state = %s", ToString(this->checkBox3->Get3StateValue())));
  }
  
private:
  static wxString ToString(wxCheckBoxState state) {
    switch (state) {
      case wxCHK_UNCHECKED: return "Unchecked"; break;
      case wxCHK_CHECKED: return "Checked"; break;
      case wxCHK_UNDETERMINED: return "Indeterminate"; break;
      default: return "(unknown)"; break;
    }
  }
  
  wxPanel* panel = new wxPanel(this);
  wxCheckBox* checkBox1 = new wxCheckBox(this->panel, wxID_ANY, "Checked", wxPoint(30, 30), wxDefaultSize, wxCHK_3STATE);
  wxCheckBox* checkBox2 = new wxCheckBox(this->panel, wxID_ANY, "Unchecked", wxPoint(30, 60), wxDefaultSize, wxCHK_3STATE);
  wxCheckBox* checkBox3 = new wxCheckBox(this->panel, wxID_ANY, "Indeterminate", wxPoint(30, 90), wxDefaultSize, wxCHK_3STATE);
  wxStaticText* label1 = new wxStaticText(this->panel, wxID_ANY, wxEmptyString, wxPoint(30, 150));
};

class Application : public wxApp {
  bool OnInit() override {return (new Form())->Show();}
};

wxIMPLEMENT_APP(Application);
