#include <wx/wx.h>
#include <wx/datectrl.h>

class Form : public wxFrame {
public:
  Form() : wxFrame(nullptr, wxID_ANY, "DateTimePicker example", wxDefaultPosition, wxSize(300, 300)) {
    this->label1->SetLabelText(this->dateTimePicker1->GetValue().FormatDate());
    this->Show();
  }
  
private:
  wxPanel* panel = new wxPanel(this);
  wxStaticText* label1 = new wxStaticText(this->panel, wxID_ANY, "", wxPoint(30, 60));
  wxDatePickerCtrl* dateTimePicker1 = new wxDatePickerCtrl(this->panel, wxID_ANY, wxDateTime(4, wxDateTime::Apr, 1975, 0, 0, 0, 0), wxPoint(30, 30));
};

class Application : public wxApp {
public:
  bool OnInit() override {new Form(); return true;}
};

wxIMPLEMENT_APP(Application);
