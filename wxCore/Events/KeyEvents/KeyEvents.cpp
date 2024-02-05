#undef NDEBUG
#include <wx/app.h>
#include <wx/display.h>
#include <wx/frame.h>
#include <wx/log.h>

namespace KeyEventsExample {
  class Frame : public wxFrame {
  public:
    Frame() : wxFrame {nullptr, wxID_ANY, "KeyEvents"} {
      control->Bind(wxEVT_KEY_DOWN, [&](wxKeyEvent& event) {
        wxLogDebug(wxString::Format("KeyDown={KeyCode=0x%04X, Modifiers=[%s]}", event.GetKeyCode(), ModiiersToString(event.GetModifiers())));
        event.Skip();
      });
      
      control->Bind(wxEVT_CHAR, [&](wxKeyEvent& event) {
        wxLogDebug(wxString::Format("Char={UnicodeKey=%s}", event.GetUnicodeKey()== WXK_NONE ? "[None]" : wxString::Format("'%c'", event.GetUnicodeKey())));
      });
      
      control->Bind(wxEVT_KEY_UP, [&](wxKeyEvent& event) {
        wxLogDebug(wxString::Format("KeyUp={KeyCode=0x%04X, Modifiers=[%s]}", event.GetKeyCode(), ModiiersToString(event.GetModifiers())));
        if (event.GetModifiers() == WXK_NONE) wxLogDebug("");
      });
    }
    
  private:
    static wxString ModiiersToString(int modifiers) {
      if (!modifiers) return "None";
      auto result = wxString {};
      if ((modifiers & wxMOD_SHIFT) == wxMOD_SHIFT) result += "Shift, ";
      if ((modifiers & wxMOD_RAW_CONTROL) == wxMOD_RAW_CONTROL) result += "Control, ";
      if ((modifiers & wxMOD_ALT) == wxMOD_ALT) result += "Alt, ";
#if defined(__APPLE__)
      if ((modifiers & wxMOD_CONTROL) == wxMOD_CONTROL) result += "Command, ";
#endif
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
