#include <chrono>
#include <wx/wx.h>
#include <wx/datectrl.h>
#include <wx/dateevt.h>

using namespace std::chrono;

namespace Examples {
  class Frame : public wxFrame {
  public:
    Frame() : wxFrame(nullptr, wxID_ANY, "DatePickerCtrl example") {
      datePicker1->SetRange({4, wxDateTime::Apr, 1975}, {system_clock::to_time_t(system_clock::now())});
      datePicker1->SetValue({4, wxDateTime::Apr, 1975});
      datePicker1->Bind(wxEVT_DATE_CHANGED, [&](wxDateEvent& event) {
        staticText1->SetLabelText(datePicker1->GetValue().FormatDate());
      });
      staticText1->SetLabelText(datePicker1->GetValue().FormatDate());
    }
    
  private:
    wxPanel* panel = new wxPanel(this);
    wxDatePickerCtrl* datePicker1 = new wxDatePickerCtrl(panel, wxID_ANY, wxDefaultDateTime, {30, 30}, wxDefaultSize, wxDP_DROPDOWN | wxDP_SHOWCENTURY);
    wxStaticText* staticText1 = new wxStaticText(panel, wxID_ANY, wxEmptyString, {30, 70});
  };

  class Application : public wxApp {
    bool OnInit() override {
      (new Frame())->Show();
      return true;
    }
  };
}

wxIMPLEMENT_APP(Examples::Application);
