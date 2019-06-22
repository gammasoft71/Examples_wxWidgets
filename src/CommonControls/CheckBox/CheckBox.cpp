#include <wx/wx.h>

class Form : public wxFrame {
public:
  Form() : wxFrame(nullptr, wxID_ANY, "CheckBox example", wxDefaultPosition, wxSize(300, 300)) {
    this->checkBox1->Set3StateValue(wxCHK_CHECKED);
    this->checkBox2->Set3StateValue(wxCHK_UNCHECKED);
    this->checkBox3->Set3StateValue(wxCHK_UNDETERMINED);
  }
  
private:
  wxPanel* panel = new wxPanel(this);
  wxCheckBox* checkBox1 = new wxCheckBox(this->panel, wxID_ANY, "Checked", wxPoint(30, 30), wxSize(130, 24), wxCHK_3STATE);
  wxCheckBox* checkBox2 = new wxCheckBox(this->panel, wxID_ANY, "Unchecked", wxPoint(30, 60), wxSize(130, 24), wxCHK_3STATE);
  wxCheckBox* checkBox3 = new wxCheckBox(this->panel, wxID_ANY, "Indeterminate", wxPoint(30, 90), wxSize(130, 24), wxCHK_3STATE);
};

class Application : public wxApp {
  bool OnInit() override {return (new Form())->Show();}
};

wxIMPLEMENT_APP(Application);
