#include <wx/wx.h>
#include <wx/calctrl.h>

class Form : public wxFrame {
public:
  Form() : wxFrame(nullptr, wxID_ANY, "MonthCalendar example", wxDefaultPosition, wxSize(300, 300)) {
    this->monthCalendar1->SetDateRange(wxDateTime(5, wxDateTime::Jan, 1971), wxDateTime(5, wxDateTime::Jan, 2071));
  }
  
private:
  wxPanel* panel = new wxPanel(this);
  wxCalendarCtrl* monthCalendar1 = new wxCalendarCtrl(this->panel, wxID_ANY, wxDateTime::Now(), wxPoint(10, 10));
};

class Application : public wxApp {
  bool OnInit() override {return (new Form())->Show();}
};

wxIMPLEMENT_APP(Application);
