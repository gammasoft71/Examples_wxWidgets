#include <map>
#include <string>
#include <wx/wx.h>
#include <wx/display.h>
#include <wx/log.h>

namespace Examples {
  class Frame : public wxFrame {
  public:
    Frame() : wxFrame(nullptr, wxID_ANY, "MouseEvents", wxDefaultPosition, {300, 300}) {
      panel->Bind(wxEVT_COMMAND_LEFT_CLICK, [&](wxCommandEvent& event) {
        wxLogDebug("Command Left Click");
      });
      
      panel->Bind(wxEVT_COMMAND_RIGHT_CLICK, [&](wxCommandEvent& event) {
        wxLogDebug("Command Right Click");
      });
      
      panel->Bind(wxEVT_COMMAND_LEFT_DCLICK, [&](wxCommandEvent& event) {
        wxLogDebug("Command Left DClick");
      });
      
      panel->Bind(wxEVT_COMMAND_RIGHT_DCLICK, [&](wxCommandEvent& event) {
        wxLogDebug("Command Right DClick");
      });
      
      panel->Bind(wxEVT_AUX1_DCLICK, [&](wxMouseEvent& event) {
        wxLogDebug(wxString::Format("Aux1DbClick={Button=%s, ClickCount=%d, WheelDelta=%d, wheelAxis=%s, location[x=%d, y=%d], ModifiersKey=[%s]}", ButtonToString(event.GetButton()), event.GetClickCount(), event.GetWheelDelta(), WheelAxisToString(event.GetWheelAxis()), event.GetPosition().x, event.GetPosition().y, ModiiersToString(event.GetModifiers())));
      });
      
      panel->Bind(wxEVT_AUX1_DOWN, [&](wxMouseEvent& event) {
        wxLogDebug(wxString::Format("Aux1Down={Button=%s, ClickCount=%d, WheelDelta=%d, wheelAxis=%s, location[x=%d, y=%d], ModifiersKey=[%s]}", ButtonToString(event.GetButton()), event.GetClickCount(), event.GetWheelDelta(), WheelAxisToString(event.GetWheelAxis()), event.GetPosition().x, event.GetPosition().y, ModiiersToString(event.GetModifiers())));
      });

      panel->Bind(wxEVT_AUX1_UP, [&](wxMouseEvent& event) {
        wxLogDebug(wxString::Format("Aux1Up={Button=%s, ClickCount=%d, WheelDelta=%d, wheelAxis=%s, location[x=%d, y=%d], ModifiersKey=[%s]}", ButtonToString(event.GetButton()), event.GetClickCount(), event.GetWheelDelta(), WheelAxisToString(event.GetWheelAxis()), event.GetPosition().x, event.GetPosition().y, ModiiersToString(event.GetModifiers())));
      });

      panel->Bind(wxEVT_AUX2_DCLICK, [&](wxMouseEvent& event) {
        wxLogDebug(wxString::Format("Aux2DbClick={Button=%s, ClickCount=%d, WheelDelta=%d, wheelAxis=%s, location[x=%d, y=%d], ModifiersKey=[%s]}", ButtonToString(event.GetButton()), event.GetClickCount(), event.GetWheelDelta(), WheelAxisToString(event.GetWheelAxis()), event.GetPosition().x, event.GetPosition().y, ModiiersToString(event.GetModifiers())));
      });

      panel->Bind(wxEVT_AUX2_DOWN, [&](wxMouseEvent& event) {
        wxLogDebug(wxString::Format("Aux2Down={Button=%s, ClickCount=%d, WheelDelta=%d, wheelAxis=%s, location[x=%d, y=%d], ModifiersKey=[%s]}", ButtonToString(event.GetButton()), event.GetClickCount(), event.GetWheelDelta(), WheelAxisToString(event.GetWheelAxis()), event.GetPosition().x, event.GetPosition().y, ModiiersToString(event.GetModifiers())));
      });

      panel->Bind(wxEVT_AUX2_UP, [&](wxMouseEvent& event) {
        wxLogDebug(wxString::Format("Aux2Up={Button=%s, ClickCount=%d, WheelDelta=%d, wheelAxis=%s, location[x=%d, y=%d], ModifiersKey=[%s]}", ButtonToString(event.GetButton()), event.GetClickCount(), event.GetWheelDelta(), WheelAxisToString(event.GetWheelAxis()), event.GetPosition().x, event.GetPosition().y, ModiiersToString(event.GetModifiers())));
      });

      panel->Bind(wxEVT_LEFT_DCLICK, [&](wxMouseEvent& event) {
        wxLogDebug(wxString::Format("LeftDbClick={Button=%s, ClickCount=%d, WheelDelta=%d, wheelAxis=%s, location[x=%d, y=%d], ModifiersKey=[%s]}", ButtonToString(event.GetButton()), event.GetClickCount(), event.GetWheelDelta(), WheelAxisToString(event.GetWheelAxis()), event.GetPosition().x, event.GetPosition().y, ModiiersToString(event.GetModifiers())));
      });

      panel->Bind(wxEVT_LEFT_DOWN, [&](wxMouseEvent& event) {
        wxLogDebug(wxString::Format("LeftDown={Button=%s, ClickCount=%d, WheelDelta=%d, wheelAxis=%s, location[x=%d, y=%d], ModifiersKey=[%s]}", ButtonToString(event.GetButton()), event.GetClickCount(), event.GetWheelDelta(), WheelAxisToString(event.GetWheelAxis()), event.GetPosition().x, event.GetPosition().y, ModiiersToString(event.GetModifiers())));
      });

      panel->Bind(wxEVT_LEFT_UP, [&](wxMouseEvent& event) {
        wxLogDebug(wxString::Format("LeftUp={Button=%s, ClickCount=%d, WheelDelta=%d, wheelAxis=%s, location[x=%d, y=%d], ModifiersKey=[%s]}", ButtonToString(event.GetButton()), event.GetClickCount(), event.GetWheelDelta(), WheelAxisToString(event.GetWheelAxis()), event.GetPosition().x, event.GetPosition().y, ModiiersToString(event.GetModifiers())));
      });

      panel->Bind(wxEVT_MIDDLE_DCLICK, [&](wxMouseEvent& event) {
        wxLogDebug(wxString::Format("MiddleDbClick={Button=%s, ClickCount=%d, WheelDelta=%d, wheelAxis=%s, location[x=%d, y=%d], ModifiersKey=[%s]}", ButtonToString(event.GetButton()), event.GetClickCount(), event.GetWheelDelta(), WheelAxisToString(event.GetWheelAxis()), event.GetPosition().x, event.GetPosition().y, ModiiersToString(event.GetModifiers())));
      });

      panel->Bind(wxEVT_MIDDLE_DOWN, [&](wxMouseEvent& event) {
        wxLogDebug(wxString::Format("MiddleDown={Button=%s, ClickCount=%d, WheelDelta=%d, wheelAxis=%s, location[x=%d, y=%d], ModifiersKey=[%s]}", ButtonToString(event.GetButton()), event.GetClickCount(), event.GetWheelDelta(), WheelAxisToString(event.GetWheelAxis()), event.GetPosition().x, event.GetPosition().y, ModiiersToString(event.GetModifiers())));
      });

      panel->Bind(wxEVT_MIDDLE_UP, [&](wxMouseEvent& event) {
        wxLogDebug(wxString::Format("MiddleUp={Button=%s, ClickCount=%d, WheelDelta=%d, wheelAxis=%s, location[x=%d, y=%d], ModifiersKey=[%s]}", ButtonToString(event.GetButton()), event.GetClickCount(), event.GetWheelDelta(), WheelAxisToString(event.GetWheelAxis()), event.GetPosition().x, event.GetPosition().y, ModiiersToString(event.GetModifiers())));
      });

      panel->Bind(wxEVT_RIGHT_DCLICK, [&](wxMouseEvent& event) {
        wxLogDebug(wxString::Format("RightDbClick={Button=%s, ClickCount=%d, WheelDelta=%d, wheelAxis=%s, location[x=%d, y=%d], ModifiersKey=[%s]}", ButtonToString(event.GetButton()), event.GetClickCount(), event.GetWheelDelta(), WheelAxisToString(event.GetWheelAxis()), event.GetPosition().x, event.GetPosition().y, ModiiersToString(event.GetModifiers())));
      });

      panel->Bind(wxEVT_RIGHT_DOWN, [&](wxMouseEvent& event) {
        wxLogDebug(wxString::Format("RightDown={Button=%s, ClickCount=%d, WheelDelta=%d, wheelAxis=%s, location[x=%d, y=%d], ModifiersKey=[%s]}", ButtonToString(event.GetButton()), event.GetClickCount(), event.GetWheelDelta(), WheelAxisToString(event.GetWheelAxis()), event.GetPosition().x, event.GetPosition().y, ModiiersToString(event.GetModifiers())));
      });

      panel->Bind(wxEVT_RIGHT_UP, [&](wxMouseEvent& event) {
        wxLogDebug(wxString::Format("RightUp={Button=%s, ClickCount=%d, WheelDelta=%d, wheelAxis=%s, location[x=%d, y=%d], ModifiersKey=[%s]}", ButtonToString(event.GetButton()), event.GetClickCount(), event.GetWheelDelta(), WheelAxisToString(event.GetWheelAxis()), event.GetPosition().x, event.GetPosition().y, ModiiersToString(event.GetModifiers())));
      });

      panel->Bind(wxEVT_MOTION, [&](wxMouseEvent& event) {
        wxLogDebug(wxString::Format("Motion={Button=%s, ClickCount=%d, WheelDelta=%d, wheelAxis=%s, location[x=%d, y=%d], ModifiersKey=[%s]}", ButtonToString(event.GetButton()), event.GetClickCount(), event.GetWheelDelta(), WheelAxisToString(event.GetWheelAxis()), event.GetPosition().x, event.GetPosition().y, ModiiersToString(event.GetModifiers())));
      });

      panel->Bind(wxEVT_MOUSEWHEEL, [&](wxMouseEvent& event) {
        wxLogDebug(wxString::Format("MouseWheel={Button=%s, ClickCount=%d, WheelDelta=%d, wheelAxis=%s, location[x=%d, y=%d], ModifiersKey=[%s]}", ButtonToString(event.GetButton()), event.GetClickCount(), event.GetWheelDelta(), WheelAxisToString(event.GetWheelAxis()), event.GetPosition().x, event.GetPosition().y, ModiiersToString(event.GetModifiers())));
      });

      panel->Bind(wxEVT_ENTER_WINDOW, [&](wxMouseEvent& event) {
        wxLogDebug("Enter Window");
      });

      panel->Bind(wxEVT_LEAVE_WINDOW, [&](wxMouseEvent& event) {
        wxLogDebug("Leave Window");
      });
    }
    
  private:
    static std::string ButtonToString(int button) {
      static std::map<int, std::string> buttons {{wxMOUSE_BTN_NONE, "wxMOUSE_BTN_NONE"}, {wxMOUSE_BTN_LEFT, "wxMOUSE_BTN_LEFT"}, {wxMOUSE_BTN_MIDDLE, "wxMOUSE_BTN_MIDDLE"}, {wxMOUSE_BTN_RIGHT, "wxMOUSE_BTN_RIGHT"}, {wxMOUSE_BTN_AUX1, "wxMOUSE_BTN_AUX1"}, {wxMOUSE_BTN_AUX2, "wxMOUSE_BTN_AUX2"}};
      return buttons[button];
    }
    
    static std::string WheelAxisToString(int wheelAxis) {
      return wheelAxis == wxMOUSE_WHEEL_HORIZONTAL ? "wxMOUSE_WHEEL_HORIZONTAL" :  "wxMOUSE_WHEEL_VERTICAL";
    }
    
    static std::string ModiiersToString(int modifiers) {
      if (!modifiers) return "None";
      std::string result;
      if ((modifiers & wxMOD_SHIFT) == wxMOD_SHIFT) result += "Shift, ";
      if ((modifiers & wxMOD_RAW_CONTROL) == wxMOD_RAW_CONTROL) result += "Control, ";
      if ((modifiers & wxMOD_ALT) == wxMOD_ALT) result += "Alt, ";
      if ((modifiers & wxMOD_CONTROL) == wxMOD_CONTROL) result += "Command, ";
      if ((modifiers & wxMOD_META) == wxMOD_META) result += "Meta, ";
      if (result.size() > 1) result.resize(result.size() - 2);
      return result;
    }
    
    wxPanel* panel = new wxPanel(this);
  };

  class Application : public wxApp {
    bool OnInit() override {
      wxLogWindow* logWindow = new wxLogWindow(nullptr, "Debug");
      logWindow->GetFrame()->SetSize(wxDisplay(wxDisplay::GetFromWindow(logWindow->GetFrame())).GetClientArea().GetLeft(), wxDisplay(wxDisplay::GetFromWindow(logWindow->GetFrame())).GetClientArea().GetTop() + wxDisplay(wxDisplay::GetFromWindow(logWindow->GetFrame())).GetClientArea().GetHeight() - wxDisplay(wxDisplay::GetFromWindow(logWindow->GetFrame())).GetClientArea().GetHeight() / 4, wxDisplay(wxDisplay::GetFromWindow(logWindow->GetFrame())).GetClientArea().GetWidth(), wxDisplay(wxDisplay::GetFromWindow(logWindow->GetFrame())).GetClientArea().GetHeight() / 4);
      (new Frame())->Show();
      return true;
    }
  };
}

wxIMPLEMENT_APP(Examples::Application);
