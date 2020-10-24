#include <chrono>
#include <wx/app.h>
#include <wx/calctrl.h>
#include <wx/frame.h>
#include <wx/panel.h>

using namespace std::chrono;

namespace Examples {
  class Frame : public wxFrame {
  public:
    Frame() : wxFrame(nullptr, wxID_ANY, "MonthCalendar example", wxDefaultPosition, {300, 300}) {
      calendarCtrl1->SetDateRange({5, wxDateTime::Jan, 1971}, {5, wxDateTime::Jan, 2071});
    }
    
  private:
    wxPanel* panel = new wxPanel(this);
    wxCalendarCtrl* calendarCtrl1 = new wxCalendarCtrl(panel, wxID_ANY, {system_clock::to_time_t(system_clock::now())}, {10, 10});
  };

  class Application : public wxApp {
    bool OnInit() override {
      (new Frame())->Show();
      return true;
    }
  };
}

wxIMPLEMENT_APP(Examples::Application);
