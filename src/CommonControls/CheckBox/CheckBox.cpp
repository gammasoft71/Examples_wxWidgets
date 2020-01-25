#include <wx/app.h>
#include <wx/checkbox.h>
#include <wx/frame.h>
#include <wx/panel.h>

namespace Examples {
  class Frame : public wxFrame {
  public:
    Frame() : wxFrame(nullptr, wxID_ANY, "CheckBox example", wxDefaultPosition, {300, 300}) {
      checkBox1->Bind(wxEVT_CHECKBOX, [&](wxCommandEvent& event) {
        checkBox1->SetValue(false);
      });

      checkBox2->SetValue(true);
      checkBox2->Bind(wxEVT_CHECKBOX, [&](wxCommandEvent& event) {
        checkBox2->SetLabel(ToString(checkBox2->Get3StateValue()));
      });

      checkBox3->Set3StateValue(wxCHK_UNDETERMINED);
      checkBox3->Bind(wxEVT_CHECKBOX, [&](wxCommandEvent& event) {
        checkBox3->SetLabel(ToString(checkBox3->Get3StateValue()));
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
    wxCheckBox* checkBox1 = new wxCheckBox(panel, wxID_ANY, "Unchecked", {30, 30});
    wxCheckBox* checkBox2 = new wxCheckBox(panel, wxID_ANY, "Checked", {30, 60});
    wxCheckBox* checkBox3 = new wxCheckBox(panel, wxID_ANY, "Indeterminate", {30, 90}, wxDefaultSize, wxCHK_3STATE | wxCHK_ALLOW_3RD_STATE_FOR_USER);
  };

  class Application : public wxApp {
    bool OnInit() override {
      (new Frame())->Show();
      return true;
    }
  };
}

wxIMPLEMENT_APP(Examples::Application);
