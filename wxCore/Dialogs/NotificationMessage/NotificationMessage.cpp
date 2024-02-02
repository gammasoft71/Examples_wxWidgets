#include <wx/app.h>
#include <wx/button.h>
#include <wx/frame.h>
#include <wx/msgout.h>
#include <wx/notifmsg.h>
#include <wx/panel.h>
#include <wx/timer.h>
#if defined(__APPLE__)
#include <wx/generic/notifmsg.h>
#endif

namespace NotificationMessageExample {
#if defined(__APPLE__)
  using wxOwnNotificationMessageBase = wxGenericNotificationMessage;
#else
  using wxOwnNotificationMessageBase = wxNotificationMessage;
#endif
  
  class wxOwnNotificationMessage : public wxOwnNotificationMessageBase {
  public:
    wxOwnNotificationMessage() : wxOwnNotificationMessage(wxString())  {}
    wxOwnNotificationMessage(const wxString& title, const wxString& message = wxString(), wxWindow *parent = nullptr, int flags = wxICON_INFORMATION) : wxOwnNotificationMessageBase(title, message, parent, flags) {
      autoCloseTimer.Bind(wxEVT_TIMER, [&](wxTimerEvent& event) {
        autoCloseTimer.Stop();
        Close();
        wxPostEvent(this, wxCommandEvent(wxEVT_NOTIFICATION_MESSAGE_DISMISSED));
      });
      
      Bind(wxEVT_NOTIFICATION_MESSAGE_CLICK, [&](wxCommandEvent& e) {
        autoCloseTimer.Stop();
        e.Skip();
      });
      
      Bind(wxEVT_NOTIFICATION_MESSAGE_ACTION, [&](wxCommandEvent& e) {
        autoCloseTimer.Stop();
        e.Skip();
      });
    }
    
    int32_t TimeoutValue() const noexcept {return timeoutValue;}
    void TimeoutValue(int32_t value) noexcept {timeoutValue = value;}
    
    bool Show(int timeout = Timeout_Auto) {
      wxOwnNotificationMessageBase::Show(Timeout_Never);
      if (timeout == Timeout_Auto) {
        autoCloseTimer.StartOnce(timeoutValue);
      }
      return true;
    }
    
  private:
    int32_t timeoutValue = 3000;
    wxTimer autoCloseTimer;
  };
  
  class MainFrame : public wxFrame {
  public:
    MainFrame() : wxFrame(nullptr, wxID_ANY, "Notification message example") {
      notificationMessage->AddAction(wxID_OK, "Ok");
      notificationMessage->AddAction(wxID_CANCEL, "Cancel");
      notificationMessage->Bind(wxEVT_NOTIFICATION_MESSAGE_ACTION, [&](wxCommandEvent& e) {
        wxMessageOutputDebug().Printf("Action [%d] clicked", e.GetId());
        notificationMessage->Close();
        e.Skip(true);
      });
      
      notificationMessage->Bind(wxEVT_NOTIFICATION_MESSAGE_CLICK, [&](wxCommandEvent& e) {
        wxMessageOutputDebug().Output("Message click");
        e.Skip(true);
      });
      
      notificationMessage->Bind(wxEVT_NOTIFICATION_MESSAGE_DISMISSED, [&](wxCommandEvent& e) {
        wxMessageOutputDebug().Output("Close on timeout");
        e.Skip(true);
      });
      
      button->SetLabel("Notification");
      button->Bind(wxEVT_BUTTON, [&](wxCommandEvent& event) {
        notificationMessage->Show(wxNotificationMessage::Timeout_Auto);
      });
      
      Bind(wxEVT_DESTROY, [&](wxCommandEvent& e) {
        notificationMessage->Close();
        delete notificationMessage;
      });      
    }
    
  private:
    wxPanel* panel = new wxPanel {this};
    wxButton* button = new wxButton {panel, wxID_ANY, "Close", {10, 10}, {160, 50}};
    wxOwnNotificationMessage* notificationMessage = new wxOwnNotificationMessage {"Notification", "This is a notification message", this, wxICON_ERROR};
  };
  
  class Application : public wxApp {
    bool OnInit() override {
      (new MainFrame())->Show();
      return true;
    }
  };
}

wxIMPLEMENT_APP(NotificationMessageExample::Application);
