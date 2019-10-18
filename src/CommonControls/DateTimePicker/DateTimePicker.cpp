#include <wx/wx.h>
#include <wx/datectrl.h>
#include <wx/dateevt.h>

class Form : public wxFrame {
public:
  Form() : wxFrame(nullptr, wxID_ANY, "DateTimePicker example", wxDefaultPosition, wxSize(300, 300)) {
    datePicker1->SetRange(wxDateTime(4, wxDateTime::Apr, 1975), wxDateTime::Now());
    datePicker1->SetValue(wxDateTime(4, wxDateTime::Apr, 1975));
    datePicker1->Bind(wxEVT_DATE_CHANGED, [&](wxDateEvent& event) {
      label1->SetLabelText(datePicker1->GetValue().FormatDate());
    });
    label1->SetLabelText(datePicker1->GetValue().FormatDate());
  }
  
private:
  wxPanel* panel = new wxPanel(this);
  wxDatePickerCtrl* datePicker1 = new wxDatePickerCtrl(panel, wxID_ANY, wxDefaultDateTime, wxPoint(30, 30));
  wxStaticText* label1 = new wxStaticText(panel, wxID_ANY, wxEmptyString, wxPoint(30, 60));
};

class Application : public wxApp {
  bool OnInit() override {(new Form())->Show(); return true;}
};

wxIMPLEMENT_APP(Application);
