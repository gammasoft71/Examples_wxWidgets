#undef NDEBUG
#include <map>
#include <wx/app.h>
#include <wx/display.h>
#include <wx/frame.h>
#include <wx/log.h>

namespace KeyEventsExample {
  class Frame : public wxFrame {
  public:
    Frame() : wxFrame {nullptr, wxID_ANY, "KeyEvents"} {
      control->Bind(wxEVT_KEY_DOWN, [&](wxKeyEvent& event) {
        wxLogDebug(wxString::Format("KeyDown={KeyCode=%s, Modifiers=[%s], Raw=[0x%08X]}", KeyCodeToString(event.GetKeyCode()), ModiiersToString(event.GetModifiers()), event.GetRawKeyCode()));
        event.Skip();
      });
      
      control->Bind(wxEVT_CHAR, [&](wxKeyEvent& event) {
        wxLogDebug(wxString::Format("Char={UnicodeKey=%s}", event.GetUnicodeKey()== WXK_NONE ? "[None]" : wxString::Format("'%c'", event.GetUnicodeKey())));
      });
      
      control->Bind(wxEVT_KEY_UP, [&](wxKeyEvent& event) {
        wxLogDebug(wxString::Format("KeyUp={KeyCode=%s, Modifiers=[%s], RawKeyCode=[0x%08X]}", KeyCodeToString(event.GetKeyCode()), ModiiersToString(event.GetModifiers()), event.GetRawKeyCode()));
        if (event.GetModifiers() == WXK_NONE) wxLogDebug("");
      });
    }
    
  private:
    static wxString KeyCodeToString(int keyCode) noexcept {
      static auto keys = std::map<int, wxString> {{WXK_NONE, "WXK_NONE"}, {WXK_BACK, "WXK_BACK"}, {WXK_TAB, "WXK_TAB"}, {WXK_RETURN, "WXK_RETURN"}, {WXK_ESCAPE, "WXK_ESCAPE"}, {WXK_SPACE, "WXK_SPACE"}, {WXK_DELETE, "WXK_DELETE"}, {WXK_CONTROL_A, "WXK_CONTROL_A"}, {WXK_CONTROL_B, "WXK_CONTROL_B"}, {WXK_CONTROL_C, "WXK_CONTROL_C"}, {WXK_CONTROL_D, "WXK_CONTROL_D"}, {WXK_CONTROL_E, "WXK_CONTROL_E"}, {WXK_CONTROL_F, "WXK_CONTROL_F"}, {WXK_CONTROL_G, "WXK_CONTROL_G"}, {WXK_CONTROL_H, "WXK_CONTROL_H"}, {WXK_CONTROL_I, "WXK_CONTROL_I"}, {WXK_CONTROL_J, "WXK_CONTROL_J"}, {WXK_CONTROL_K, "WXK_CONTROL_K"}, {WXK_CONTROL_L, "WXK_CONTROL_L"}, {WXK_CONTROL_M, "WXK_CONTROL_M"}, {WXK_CONTROL_N, "WXK_CONTROL_N"}, {WXK_CONTROL_O, "WXK_CONTROL_O"}, {WXK_CONTROL_P, "WXK_CONTROL_P"}, {WXK_CONTROL_Q, "WXK_CONTROL_Q"}, {WXK_CONTROL_R, "WXK_CONTROL_R"}, {WXK_CONTROL_S, "WXK_CONTROL_S"}, {WXK_CONTROL_T, "WXK_CONTROL_T"}, {WXK_CONTROL_U, "WXK_CONTROL_U"}, {WXK_CONTROL_V, "WXK_CONTROL_V"}, {WXK_CONTROL_W, "WXK_CONTROL_W"}, {WXK_CONTROL_X, "WXK_CONTROL_X"}, {WXK_CONTROL_Y, "WXK_CONTROL_Y"}, {WXK_CONTROL_Z, "WXK_CONTROL_Z"}, {WXK_START, "WXK_START"}, {WXK_LBUTTON, "WXK_LBUTTON"}, {WXK_RBUTTON, "WXK_RBUTTON"}, {WXK_CANCEL, "WXK_CANCEL"}, {WXK_MBUTTON, "WXK_MBUTTON"}, {WXK_CLEAR, "WXK_CLEAR"}, {WXK_SHIFT, "WXK_SHIFT"}, {WXK_ALT, "WXK_ALT"} /*, {WXK_COMMAND, "WXK_COMMAND"}*/, {WXK_CONTROL, "WXK_CONTROL"}, {WXK_MENU, "WXK_MENU"}, {WXK_PAUSE, "WXK_PAUSE"}, {WXK_CAPITAL, "WXK_CAPITAL"}, {WXK_END, "WXK_END"}, {WXK_HOME, "WXK_HOME"}, {WXK_LEFT, "WXK_LEFT"}, {WXK_UP, "WXK_UP"}, {WXK_RIGHT, "WXK_RIGHT"}, {WXK_DOWN, "WXK_DOWN"}, {WXK_SELECT, "WXK_SELECT"}, {WXK_PRINT, "WXK_PRINT"}, {WXK_EXECUTE, "WXK_EXECUTE"}, {WXK_SNAPSHOT, "WXK_SNAPSHOT"}, {WXK_INSERT, "WXK_INSERT"}, {WXK_HELP, "WXK_HELP"}, {WXK_NUMPAD0, "WXK_NUMPAD0"}, {WXK_NUMPAD1, "WXK_NUMPAD1"}, {WXK_NUMPAD2, "WXK_NUMPAD2"}, {WXK_NUMPAD3, "WXK_NUMPAD3"}, {WXK_NUMPAD4, "WXK_NUMPAD4"}, {WXK_NUMPAD5, "WXK_NUMPAD5"}, {WXK_NUMPAD6, "WXK_NUMPAD6"}, {WXK_NUMPAD7, "WXK_NUMPAD7"}, {WXK_NUMPAD8, "WXK_NUMPAD8"}, {WXK_NUMPAD9, "WXK_NUMPAD9"}, {WXK_MULTIPLY, "WXK_MULTIPLY"}, {WXK_ADD, "WXK_ADD"}, {WXK_SEPARATOR, "WXK_SEPARATOR"}, {WXK_SUBTRACT, "WXK_SUBTRACT"}, {WXK_DECIMAL, "WXK_DECIMAL"}, {WXK_DIVIDE, "WXK_DIVIDE"}, {WXK_F1, "WXK_F1"}, {WXK_F2, "WXK_F2"}, {WXK_F3, "WXK_F3"}, {WXK_F4, "WXK_F4"}, {WXK_F5, "WXK_F5"}, {WXK_F6, "WXK_F6"}, {WXK_F7, "WXK_F7"}, {WXK_F8, "WXK_F8"}, {WXK_F9, "WXK_F9"}, {WXK_F10, "WXK_F10"}, {WXK_F11, "WXK_F11"}, {WXK_F12, "WXK_F12"}, {WXK_F13, "WXK_F13"}, {WXK_F14, "WXK_F14"}, {WXK_F15, "WXK_F15"}, {WXK_F16, "WXK_F16"}, {WXK_F17, "WXK_F17"}, {WXK_F18, "WXK_F18"}, {WXK_F19, "WXK_F19"}, {WXK_F20, "WXK_F20"}, {WXK_F21, "WXK_F21"}, {WXK_F22, "WXK_F22"}, {WXK_F23, "WXK_F23"}, {WXK_F24, "WXK_F24"}, {WXK_NUMLOCK, "WXK_NUMLOCK"}, {WXK_SCROLL, "WXK_SCROLL"}, {WXK_PAGEUP, "WXK_PAGEUP"}, {WXK_PAGEDOWN, "WXK_PAGEDOWN"}, {WXK_NUMPAD_SPACE, "WXK_NUMPAD_SPACE"}, {WXK_NUMPAD_TAB, "WXK_NUMPAD_TAB"}, {WXK_NUMPAD_ENTER, "WXK_NUMPAD_ENTER"}, {WXK_NUMPAD_F1, "WXK_NUMPAD_F1"}, {WXK_NUMPAD_F2, "WXK_NUMPAD_F2"}, {WXK_NUMPAD_F3, "WXK_NUMPAD_F3"}, {WXK_NUMPAD_F4, "WXK_NUMPAD_F4"}, {WXK_NUMPAD_HOME, "WXK_NUMPAD_HOME"}, {WXK_NUMPAD_LEFT, "WXK_NUMPAD_LEFT"}, {WXK_NUMPAD_UP, "WXK_NUMPAD_UP"}, {WXK_NUMPAD_RIGHT, "WXK_NUMPAD_RIGHT"}, {WXK_NUMPAD_DOWN, "WXK_NUMPAD_DOWN"}, {WXK_NUMPAD_PAGEUP, "WXK_NUMPAD_PAGEUP"}, {WXK_NUMPAD_PAGEDOWN, "WXK_NUMPAD_PAGEDOWN"}, {WXK_NUMPAD_END, "WXK_NUMPAD_END"}, {WXK_NUMPAD_BEGIN, "WXK_NUMPAD_BEGIN"}, {WXK_NUMPAD_INSERT, "WXK_NUMPAD_INSERT"}, {WXK_NUMPAD_DELETE, "WXK_NUMPAD_DELETE"}, {WXK_NUMPAD_EQUAL, "WXK_NUMPAD_EQUAL"}, {WXK_NUMPAD_MULTIPLY, "WXK_NUMPAD_MULTIPLY"}, {WXK_NUMPAD_ADD, "WXK_NUMPAD_ADD"}, {WXK_NUMPAD_SEPARATOR, "WXK_NUMPAD_SEPARATOR"}, {WXK_NUMPAD_SUBTRACT, "WXK_NUMPAD_SUBTRACT"}, {WXK_NUMPAD_DECIMAL, "WXK_NUMPAD_DECIMAL"}, {WXK_NUMPAD_DIVIDE, "WXK_NUMPAD_DIVIDE"}, {WXK_WINDOWS_LEFT, "WXK_WINDOWS_LEFT"}, {WXK_WINDOWS_RIGHT, "WXK_WINDOWS_RIGHT"}, {WXK_WINDOWS_MENU , "WXK_WINDOWS_MENU"}, {WXK_RAW_CONTROL, "WXK_RAW_CONTROL"}, {WXK_SPECIAL1, "WXK_SPECIAL1"}, {WXK_SPECIAL2, "WXK_SPECIAL2"}, {WXK_SPECIAL3, "WXK_SPECIAL3"}, {WXK_SPECIAL4, "WXK_SPECIAL4"}, {WXK_SPECIAL5, "WXK_SPECIAL5"}, {WXK_SPECIAL6, "WXK_SPECIAL6"}, {WXK_SPECIAL7, "WXK_SPECIAL7"}, {WXK_SPECIAL8, "WXK_SPECIAL8"}, {WXK_SPECIAL9, "WXK_SPECIAL9"}, {WXK_SPECIAL10, "WXK_SPECIAL10"}, {WXK_SPECIAL11, "WXK_SPECIAL11"}, {WXK_SPECIAL12, "WXK_SPECIAL12"}, {WXK_SPECIAL13, "WXK_SPECIAL13"}, {WXK_SPECIAL14, "WXK_SPECIAL14"}, {WXK_SPECIAL15, "WXK_SPECIAL15"}, {WXK_SPECIAL16, "WXK_SPECIAL16"}, {WXK_SPECIAL17, "WXK_SPECIAL17"}, {WXK_SPECIAL18, "WXK_SPECIAL18"}, {WXK_SPECIAL19, "WXK_SPECIAL19"}, {WXK_SPECIAL20, "WXK_SPECIAL20"}, {WXK_BROWSER_BACK, "WXK_BROWSER_BACK"}, {WXK_BROWSER_FORWARD, "WXK_BROWSER_FORWARD"}, {WXK_BROWSER_REFRESH, "WXK_BROWSER_REFRESH"}, {WXK_BROWSER_STOP, "WXK_BROWSER_STOP"}, {WXK_BROWSER_SEARCH, "WXK_BROWSER_SEARCH"}, {WXK_BROWSER_FAVORITES, "WXK_BROWSER_FAVORITES"}, {WXK_BROWSER_HOME, "WXK_BROWSER_HOME"}, {WXK_VOLUME_MUTE, "WXK_VOLUME_MUTE"}, {WXK_VOLUME_DOWN, "WXK_VOLUME_DOWN"}, {WXK_VOLUME_UP, "WXK_VOLUME_UP"}, {WXK_MEDIA_NEXT_TRACK, "WXK_MEDIA_NEXT_TRACK"}, {WXK_MEDIA_PREV_TRACK, "WXK_MEDIA_PREV_TRACK"}, {WXK_MEDIA_STOP, "WXK_MEDIA_STOP"}, {WXK_MEDIA_PLAY_PAUSE, "WXK_MEDIA_PLAY_PAUSE"}, {WXK_LAUNCH_MAIL, "WXK_LAUNCH_MAIL"}, {WXK_LAUNCH_0, "WXK_LAUNCH_0"}, {WXK_LAUNCH_1, "WXK_LAUNCH_1"}, {WXK_LAUNCH_2, "WXK_LAUNCH_2"}, {WXK_LAUNCH_3, "WXK_LAUNCH_3"}, {WXK_LAUNCH_4, "WXK_LAUNCH_4"}, {WXK_LAUNCH_5, "WXK_LAUNCH_5"}, {WXK_LAUNCH_6, "WXK_LAUNCH_6"}, {WXK_LAUNCH_7, "WXK_LAUNCH_7"}, {WXK_LAUNCH_8, "WXK_LAUNCH_8"}, {WXK_LAUNCH_9, "WXK_LAUNCH_9"}, {WXK_LAUNCH_A, "WXK_LAUNCH_A"}, {WXK_LAUNCH_B, "WXK_LAUNCH_B"}, {WXK_LAUNCH_C, "WXK_LAUNCH_C"}, {WXK_LAUNCH_D, "WXK_LAUNCH_D"}, {WXK_LAUNCH_E, "WXK_LAUNCH_E"}, {WXK_LAUNCH_F, "WXK_LAUNCH_F"}, {WXK_LAUNCH_APP1, "WXK_LAUNCH_APP1"}, {WXK_LAUNCH_APP2, "WXK_LAUNCH_APP2"}};
      if ((keyCode >= 33 && keyCode <= 126) || (keyCode >= 128 && keyCode <= 255)) return wxString::Format("%c", static_cast<char>(keyCode));
      auto it = keys.find(keyCode);
      if (it == keys.end()) return wxString::Format("0x%04X", keyCode);
      return it->second;
    }
    
    static wxString ModiiersToString(int modifiers) noexcept {
      if (!modifiers) return "None";
      auto result = wxString {};
      if ((modifiers & wxMOD_SHIFT) == wxMOD_SHIFT) result += "Shift, ";
      if ((modifiers & wxMOD_RAW_CONTROL) == wxMOD_RAW_CONTROL) result += "Control, ";
      if ((modifiers & wxMOD_ALT) == wxMOD_ALT) result += "Alt, ";
      if (wxPlatformInfo::Get().GetOperatingSystemFamilyName() == "Macintosh" && (modifiers & wxMOD_CONTROL) == wxMOD_CONTROL) result += "Command, ";
      if ((modifiers & wxMOD_META) == wxMOD_META) result += "Meta, ";
      if (result.size() > 1) result.resize(result.size() - 2);
      return result;
    }
    
    wxControl* control = new wxControl {this, wxID_ANY};
  };

  class Application : public wxApp {
    bool OnInit() override {
      auto logWindow = new wxLogWindow {nullptr, "Debug"};
      logWindow->GetFrame()->SetSize(wxDisplay {static_cast<unsigned>(wxDisplay::GetFromWindow(logWindow->GetFrame()))}.GetClientArea().GetLeft(), wxDisplay {static_cast<unsigned>(wxDisplay::GetFromWindow(logWindow->GetFrame()))}.GetClientArea().GetTop() + wxDisplay {static_cast<unsigned>(wxDisplay::GetFromWindow(logWindow->GetFrame()))}.GetClientArea().GetHeight() - wxDisplay {static_cast<unsigned>(wxDisplay::GetFromWindow(logWindow->GetFrame()))}.GetClientArea().GetHeight() / 4, wxDisplay {static_cast<unsigned>(wxDisplay::GetFromWindow(logWindow->GetFrame()))}.GetClientArea().GetWidth(), wxDisplay {static_cast<unsigned>(wxDisplay::GetFromWindow(logWindow->GetFrame()))}.GetClientArea().GetHeight() / 4);
      return (new Frame)->Show();
    }
  };
}

wxIMPLEMENT_APP(KeyEventsExample::Application);
