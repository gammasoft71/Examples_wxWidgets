#include <wx/app.h>
#include <wx/calctrl.h>
#include <wx/frame.h>
#include <wx/panel.h>
#include <chrono>

using namespace std::chrono;

namespace CalendarCtrlExample {
  class Frame : public wxFrame {
  public:
    Frame() : wxFrame {nullptr, wxID_ANY, "MonthCalendar example"} {
      calendarCtrl1->SetDateRange({5, wxDateTime::Jan, 1971}, {5, wxDateTime::Jan, 2071});
      calendarCtrl1->Bind(wxEVT_CALENDAR_SEL_CHANGED, [&](wxCalendarEvent& e) {
        wxLogDebug("Calendar Selection Changed");
      });
      calendarCtrl1->Bind(wxEVT_CALENDAR_DOUBLECLICKED, [&](wxCalendarEvent& e) {
        wxLogDebug("Calendar double Cliccked");
      });
      calendarCtrl1->Bind(wxEVT_CALENDAR_PAGE_CHANGED, [&](wxCalendarEvent& e) {
        wxLogDebug("Calendar Page Changed");
      });
      calendarCtrl1->Bind(wxEVT_CALENDAR_WEEKDAY_CLICKED, [&](wxCalendarEvent& e) {
        wxLogDebug("Calendar Weekday Clicked");
      });
      calendarCtrl1->Bind(wxEVT_CALENDAR_WEEK_CLICKED, [&](wxCalendarEvent& e) {
        wxLogDebug("Calendar Week Clicked");
      });
    }
    
  private:
    wxPanel* panel = new wxPanel {this};
    wxCalendarCtrl* calendarCtrl1 = new wxCalendarCtrl {panel, wxID_ANY, {system_clock::to_time_t(system_clock::now())}, {10, 10}};
  };

  class Application : public wxApp {
    bool OnInit() override {return (new Frame)->Show();}
  };
}

wxIMPLEMENT_APP(CalendarCtrlExample::Application);
