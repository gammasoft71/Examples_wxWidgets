#pragma once

#include <wx/wx.h>
#include <wx/taskbar.h>

class wxNotifyIcon : public wxTaskBarIcon {
public:
  wxNotifyIcon(wxTaskBarIconType iconType = wxTBI_DEFAULT_TYPE) : wxTaskBarIcon(iconType) {
    timer.Bind(wxEVT_TIMER, [&](wxTimerEvent& event) {
      wxPostEvent(this, wxTaskBarIconEvent(wxEVT_TASKBAR_LEFT_DOWN, this));
      wxPostEvent(this, wxTaskBarIconEvent(wxEVT_TASKBAR_LEFT_UP, this));
    });
  }
  
protected:
#if defined(__APPLE__)
  wxMenu* CreatePopupMenu() override {
    if (!timer.IsRunning()) {
      timer.StartOnce(wxSystemSettings::GetMetric(wxSYS_DCLICK_MSEC));
    } else {
      timer.Stop();
      wxPostEvent(this, wxTaskBarIconEvent(wxEVT_TASKBAR_LEFT_DCLICK, this));
    }
    return wxTaskBarIcon::CreatePopupMenu();
  }
#endif

private:
  wxTimer timer;
};
