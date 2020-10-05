#include <wx/wx.h>
#include <wx/display.h>

namespace Examples {
  class Frame : public wxFrame {
  public:
    Frame() : wxFrame(nullptr, wxID_ANY, "KeyEvents", wxDefaultPosition, {300, 300}) {
      logWindow->GetFrame()->SetSize(wxDisplay(wxDisplay::GetFromWindow(this)).GetClientArea().GetLeft(), wxDisplay(wxDisplay::GetFromWindow(this)).GetClientArea().GetTop() + wxDisplay(wxDisplay::GetFromWindow(this)).GetClientArea().GetHeight() - wxDisplay(wxDisplay::GetFromWindow(this)).GetClientArea().GetHeight() / 4, wxDisplay(wxDisplay::GetFromWindow(this)).GetClientArea().GetWidth(), wxDisplay(wxDisplay::GetFromWindow(this)).GetClientArea().GetHeight() / 4);
      
      panel->Bind(wxEVT_KEY_DOWN, [&](wxKeyEvent& event) {
        wxLogDebug(wxString::Format("KeyDown={KeyCode=0x%04X, Modifiers=[%s]}", event.GetKeyCode(), ModiiersToString(event.GetModifiers())));
        event.Skip();
      });
      
      panel->Bind(wxEVT_CHAR, [&](wxKeyEvent& event) {
        wxLogDebug(wxString::Format("Char={UnicodeKey=%s}", event.GetUnicodeKey()== WXK_NONE ? "[None]" : wxString::Format("'%c'", event.GetUnicodeKey())));
      });
      
      panel->Bind(wxEVT_KEY_UP, [&](wxKeyEvent& event) {
        wxLogDebug(wxString::Format("KeyUp={KeyCode=0x%04X, Modifiers=[%s]}", event.GetKeyCode(), ModiiersToString(event.GetModifiers())));
        if (event.GetModifiers() == WXK_NONE) wxLogDebug("");
      });
    }
    
  private:
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
    wxLogWindow* logWindow = new wxLogWindow(this, "Debug");
  };

  class Application : public wxApp {
    bool OnInit() override {
      (new Frame())->Show();
      return true;
    }
  };
}

wxIMPLEMENT_APP(Examples::Application);
