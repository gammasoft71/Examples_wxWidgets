#include <wx/wx.h>
#include <wx/display.h>

namespace Examples {
  class Frame : public wxFrame {
  public:
    Frame() : wxFrame(nullptr, wxID_ANY, "Display informations example") {
      SetClientSize(450, 300);
      
      screenInformationsTextCtrl->SetBackgroundColour({wxTheColourDatabase->Find("Navy")});
      screenInformationsTextCtrl->SetForegroundColour(wxTheColourDatabase->Find("Yellow"));
      screenInformationsTextCtrl->AppendText(wxString::Format("Count: %d\n", wxDisplay::GetCount()));
      screenInformationsTextCtrl->AppendText(wxString::Format("StdPPI: {Width=%d, Height=%d}\n", wxDisplay::GetStdPPI().GetWidth(), wxDisplay::GetStdPPI().GetHeight()));
      screenInformationsTextCtrl->AppendText(wxString::Format("StdPPIValue: %d\n", wxDisplay::GetStdPPIValue()));
      for (auto screenIndex = 0u; screenIndex < wxDisplay::GetCount(); screenIndex++) {
        screenInformationsTextCtrl->AppendText("\n");
        wxDisplay display(screenIndex);
        screenInformationsTextCtrl->AppendText(wxString::Format("Display: %d\n", screenIndex + 1));
        screenInformationsTextCtrl->AppendText(wxString::Format("   Name: %s\n", display.GetName()));
        screenInformationsTextCtrl->AppendText(wxString::Format("   Geometry: {X=%d, Y=%d, Width=%d, Height=%d\n", display.GetGeometry().GetX(), display.GetGeometry().GetY(), display.GetGeometry().GetWidth(), display.GetGeometry().GetHeight()));
        screenInformationsTextCtrl->AppendText(wxString::Format("   ClientArea: {X=%d, Y=%d, Width=%d, Height=%d\n", display.GetClientArea().GetX(), display.GetClientArea().GetY(), display.GetClientArea().GetWidth(), display.GetClientArea().GetHeight()));
        screenInformationsTextCtrl->AppendText(wxString::Format("   PPI: {Width=%d, Height=%d}\n", display.GetPPI().GetWidth(), display.GetPPI().GetHeight()));
        screenInformationsTextCtrl->AppendText(wxString::Format("   ScaleFactor: %g\n", display.GetScaleFactor()));
        screenInformationsTextCtrl->AppendText(wxString::Format("   Depth: %d\n", display.GetCurrentMode().GetDepth()));
        screenInformationsTextCtrl->AppendText(wxString::Format("   Primary: %s\n", display.IsPrimary() ? "True" : "False"));
      }
    }

  private:
    wxTextCtrl* screenInformationsTextCtrl = new wxTextCtrl(this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxTE_MULTILINE|wxTE_READONLY);
  };

  class Application : public wxApp {
    bool OnInit() override {
      (new Frame())->Show();
      return true;
    }
  };
}

wxIMPLEMENT_APP(Examples::Application);
