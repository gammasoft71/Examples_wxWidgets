#pragma once

#include <wx/wx.h>
#include <wx/taskbar.h>

class wxNotifyIcon : public wxTaskBarIcon {
public:
  wxNotifyIcon() {}
  
  wxMenu* CreatePopupMenu() override {
#if defined(__APPLE__)
    if (!this->timer.IsRunning())
      this->timer.StartOnce(wxSystemSettings::GetMetric(wxSYS_DCLICK_MSEC));
    else {
      this->timer.Stop();
      wxPostEvent(this, wxTaskBarIconEvent(wxEVT_TASKBAR_LEFT_DCLICK, this));
    }
    
    this->timer.Bind(wxEVT_TIMER, [&](wxTimerEvent& event) {
      wxPostEvent(this, wxTaskBarIconEvent(wxEVT_TASKBAR_LEFT_DOWN, this));
      wxPostEvent(this, wxTaskBarIconEvent(wxEVT_TASKBAR_LEFT_UP, this));
    });
#endif
    
    return this->wxTaskBarIcon::CreatePopupMenu();
  }

  wxTimer timer;
};
