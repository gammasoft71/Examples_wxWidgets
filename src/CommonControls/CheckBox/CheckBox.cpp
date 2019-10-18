#include <wx/wx.h>
#include <wx/tglbtn.h>

class Form : public wxFrame {
public:
  Form() : wxFrame(nullptr, wxID_ANY, "CheckBox example", wxDefaultPosition, wxSize(300, 300)) {
    checkBox1->Bind(wxEVT_CHECKBOX, [this](wxCommandEvent& event) {
      checkBox1->SetValue(false);
    });

    checkBox2->SetValue(true);
    checkBox2->Bind(wxEVT_CHECKBOX, [this](wxCommandEvent& event) {
      checkBox2->SetLabel(ToString(checkBox2->Get3StateValue()));
    });

    checkBox3->Set3StateValue(wxCHK_UNDETERMINED);
    checkBox3->Bind(wxEVT_CHECKBOX, [this](wxCommandEvent& event) {
      checkBox3->SetLabel(ToString(checkBox3->Get3StateValue()));
    });

    checkBox4->SetValue(true);
    checkBox4->Bind(wxEVT_TOGGLEBUTTON, [&](wxCommandEvent& event) {
      checkBox4->SetLabel(checkBox4->GetValue() ? "Checked" : "Unchecked");
    });

    checkBox5->Bind(wxEVT_TOGGLEBUTTON, [this](wxCommandEvent& event) {
      checkBox5->SetValue(false);
    });
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
  wxCheckBox* checkBox1 = new wxCheckBox(panel, wxID_ANY, "Unchecked", wxPoint(30, 30), wxDefaultSize);
  wxCheckBox* checkBox2 = new wxCheckBox(panel, wxID_ANY, "Checked", wxPoint(30, 60), wxDefaultSize);
  wxCheckBox* checkBox3 = new wxCheckBox(panel, wxID_ANY, "Indeterminate", wxPoint(30, 90), wxDefaultSize, wxCHK_3STATE | wxCHK_ALLOW_3RD_STATE_FOR_USER);
  wxToggleButton* checkBox4 = new wxToggleButton(panel, wxID_ANY, "Checked", wxPoint(30, 120), wxDefaultSize);
  wxToggleButton* checkBox5 = new wxToggleButton(panel, wxID_ANY, "Unchecked", wxPoint(30, 150), wxDefaultSize);
};

class Application : public wxApp {
  bool OnInit() override {(new Form())->Show(); return true;}
};

wxIMPLEMENT_APP(Application);
