#include <wx/wx.h>
#include <wx/timectrl.h>
#include <wx/dateevt.h>

namespace Examples {
  class Frame : public wxFrame {
  public:
    Frame() : wxFrame(nullptr, wxID_ANY, "TimePickerCtrl example", wxDefaultPosition, {300, 300}) {
      timePicker1->SetTime(12, 34, 56);
      timePicker1->Bind(wxEVT_TIME_CHANGED, [&](wxDateEvent& event) {
        staticText1->SetLabelText(timePicker1->GetValue().FormatTime());
      });
      staticText1->SetLabelText(timePicker1->GetValue().FormatTime());
    }
    
  private:
    wxPanel* panel = new wxPanel(this);
    wxTimePickerCtrl* timePicker1 = new wxTimePickerCtrl(panel, wxID_ANY, wxDefaultDateTime, {30, 30}, wxDefaultSize, wxTP_DEFAULT);
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
