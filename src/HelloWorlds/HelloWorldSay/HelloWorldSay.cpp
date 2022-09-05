#include <wx/filename.h>
#include <wx/process.h>
#include <wx/stdpaths.h>
#include <wx/wx.h>

class Frame1 : public wxFrame {
public:
  Frame1() : wxFrame(nullptr, wxID_ANY, "Hello world (say)") {
    if (wxPlatformInfo::Get().GetOperatingSystemFamilyName() == "Windows") wxFile(sayCmdFile.GetFullPath(), wxFile::write).Write("@echo Set Speaker=CreateObject(\"sapi.spvoice\") > %TEMP%\\say.vbs\n@echo Speaker.Speak \"%*\" >> %TEMP%\\say.vbs\n@%TEMP%\\say.vbs");
    else if (wxPlatformInfo::Get().GetOperatingSystemFamilyName() == "Macintosh") wxFile(sayCmdFile.GetFullPath(), wxFile::write).Write("say \"$*\"");
    else wxFile(sayCmdFile.GetFullPath(), wxFile::write).Write("spd-say \"$*\"");
    sayCmdFile.SetPermissions(wxPOSIX_USER_READ | wxPOSIX_USER_WRITE | wxPOSIX_USER_EXECUTE);

    button1->Bind(wxEVT_BUTTON, [&](wxCommandEvent&) {
      wxProcess::Open(wxString::Format("%s Hello, World!", sayCmdFile.GetFullPath()));
    });
  }

private:
  wxFileName sayCmdFile {wxStandardPaths::Get().GetTempDir(), "say", "cmd"};
  wxPanel* panel1 = new wxPanel(this, wxID_ANY);
  wxButton* button1 = new wxButton(panel1, wxID_ANY, "Say...", {10, 10});
};

class Application : public wxApp {
  bool OnInit() override {
    (new Frame1)->Show();
    return true;
  }
};

wxIMPLEMENT_APP(Application);
