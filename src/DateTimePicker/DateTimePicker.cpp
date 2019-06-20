#include <wx/wx.h>
#include <wx/datectrl.h>
#include <wx/dateevt.h>

class Form : public wxFrame {
public:
  Form() : wxFrame(nullptr, wxID_ANY, "DateTimePicker example", wxDefaultPosition, wxSize(300, 300)) {
    this->datePicker1->SetRange(wxDateTime(4, wxDateTime::Apr, 1975), wxDateTime::Now());
    this->datePicker1->SetValue(wxDateTime(4, wxDateTime::Apr, 1975));
    this->datePicker1->Bind(wxEVT_DATE_CHANGED, [&](wxDateEvent& event) {
      this->label1->SetLabelText(this->datePicker1->GetValue().FormatDate());
    });
    this->label1->SetLabelText(this->datePicker1->GetValue().FormatDate());
    this->Show();
  }
  
private:
  wxPanel* panel = new wxPanel(this);
  wxDatePickerCtrl* datePicker1 = new wxDatePickerCtrl(this->panel, wxID_ANY, wxDefaultDateTime, wxPoint(30, 30));
  wxStaticText* label1 = new wxStaticText(this->panel, wxID_ANY, wxEmptyString, wxPoint(30, 60));
};

class Application : public wxApp {
public:
  bool OnInit() override {new Form(); return true;}
};

wxIMPLEMENT_APP(Application);
