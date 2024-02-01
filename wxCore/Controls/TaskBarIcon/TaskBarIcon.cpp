#include "Gammasoft.xpm"
#include <wx/wx.h>
#include <wx/taskbar.h>

// Workaround : with wxWidgets version <= 3.2.0 wxTaskBarIcon mouse double click doesn't work on macOS
class TaskBarIcon : public wxTaskBarIcon {
public:
  TaskBarIcon(wxTaskBarIconType iconType = wxTBI_DEFAULT_TYPE) : wxTaskBarIcon(iconType) {
    timer.Bind(wxEVT_TIMER, [&](wxTimerEvent& event) {
      wxPostEvent(this, wxTaskBarIconEvent(wxEVT_TASKBAR_LEFT_DOWN, this));
      wxPostEvent(this, wxTaskBarIconEvent(wxEVT_TASKBAR_LEFT_UP, this));
    });
  }
  
protected:
  wxMenu* CreatePopupMenu() override {
    if (wxPlatformInfo::Get().GetOperatingSystemFamilyName() == "Macintosh") {
      if (!timer.IsRunning()) {
        timer.StartOnce(wxSystemSettings::GetMetric(wxSYS_DCLICK_MSEC));
      } else {
        timer.Stop();
        wxPostEvent(this, wxTaskBarIconEvent(wxEVT_TASKBAR_LEFT_DCLICK, this));
      }
    }
    return wxTaskBarIcon::CreatePopupMenu();
  }
  
private:
  wxTimer timer;
};

namespace TaskBarIconExample {
  class Frame : public wxFrame {
  public:
    Frame() : wxFrame(nullptr, wxID_ANY, "TaskBarIcon example") {
      taskBarIcon.SetIcon(wxBitmap {GammasoftIcon});
      taskBarIcon.Bind(wxEVT_TASKBAR_LEFT_DCLICK, [&](wxTaskBarIconEvent& event) {
        Show(!IsShown());
      });
    }
    
  private:
    wxPanel* panel = new wxPanel(this);
    wxStaticText* staticText1 = new wxStaticText(panel, wxID_ANY, "Double click on Gammasoft tray icon\nto show or hide this frame.", {10, 10});
    //wxTaskBarIcon taskBarIcon;
    TaskBarIcon taskBarIcon;
  };

  class Application : public wxApp {
    bool OnInit() override {
      (new Frame)->Show();
      return true;
    }
  };
}

wxIMPLEMENT_APP(TaskBarIconExample::Application);
