#include <wx/filename.h>
#include <wx/process.h>
#include <wx/stdpaths.h>
#include <wx/wx.h>

class Frame1 : public wxFrame {
public:
  Frame1() : wxFrame(nullptr, wxID_ANY, "Hello world (say)") {
    button1->Bind(wxEVT_BUTTON, [&](wxCommandEvent&) {
      Speak("Hello, World!");
    });
  }

private:
  // Very basic speech synthesizer using the command line.
  void Speak(const wxString& text) {
    static auto initialized = false;
    static auto sayCmdFile = wxFileName {wxStandardPaths::Get().GetTempDir(), "say", "cmd"};
    if (!initialized) {
      if (wxPlatformInfo::Get().GetOperatingSystemFamilyName() == "Windows") wxFile(sayCmdFile.GetFullPath(), wxFile::write).Write("@echo Set Speaker=CreateObject(\"sapi.spvoice\") > %TEMP%\\say.vbs\n@echo Speaker.Speak \"%*\" >> %TEMP%\\say.vbs\n@%TEMP%\\say.vbs");
      else if (wxPlatformInfo::Get().GetOperatingSystemFamilyName() == "Macintosh") wxFile(sayCmdFile.GetFullPath(), wxFile::write).Write("say \"$*\"");
      else wxFile(sayCmdFile.GetFullPath(), wxFile::write).Write("spd-say \"$*\"");
      sayCmdFile.SetPermissions(wxPOSIX_USER_READ | wxPOSIX_USER_WRITE | wxPOSIX_USER_EXECUTE);
      initialized = true;
    }
    wxProcess::Open(wxString::Format("%s %s", sayCmdFile.GetFullPath(), text));
  }

  wxPanel* panel1 = new wxPanel(this, wxID_ANY);
  wxButton* button1 = new wxButton(panel1, wxID_ANY, "Say...", {10, 10});
};

class Application : public wxApp {
  bool OnInit() override {return (new Frame1)->Show();}
};

wxIMPLEMENT_APP(Application);
