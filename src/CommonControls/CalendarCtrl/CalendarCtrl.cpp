#include <wx/app.h>
#include <wx/calctrl.h>
#include <wx/frame.h>
#include <wx/panel.h>

class Frame : public wxFrame {
public:
  Frame() : wxFrame(nullptr, wxID_ANY, "MonthCalendar example", wxDefaultPosition, wxSize(300, 300)) {
    calendarCtrl1->SetDateRange(wxDateTime(5, wxDateTime::Jan, 1971), wxDateTime(5, wxDateTime::Jan, 2071));
  }
  
private:
  wxPanel* panel = new wxPanel(this);
  wxCalendarCtrl* calendarCtrl1 = new wxCalendarCtrl(panel, wxID_ANY, wxDateTime::Now(), wxPoint(10, 10));
};

class Application : public wxApp {
  bool OnInit() override {(new Frame())->Show(); return true;}
};

wxIMPLEMENT_APP(Application);
