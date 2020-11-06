#include <filesystem>
#include <wx/wx.h>
#include <wx/file.h>
#include <wx/process.h>

using namespace std::filesystem;

class Frame1 : public wxFrame {
public:
  Frame1() : wxFrame(nullptr, wxID_ANY, "Hello world (say)") {
    button1->Bind(wxEVT_BUTTON, [](wxCommandEvent&) {
      if (wxPlatformInfo::Get().GetOperatingSystemFamilyName() == "Windows") wxProcess::Open("say.bat \"Hello world\"", wxEXEC_BLOCK);
      else wxProcess::Open("say \"Hello world\"", wxEXEC_BLOCK);
      });
  }

private:
  wxPanel* panel1 = new wxPanel(this, wxID_ANY);
  wxButton* button1 = new wxButton(panel1, wxID_ANY, "Say...", { 10, 10 });
};

class Application : public wxApp {
  bool OnInit() override {
    if (wxPlatformInfo::Get().GetOperatingSystemFamilyName() == "Windows")
      wxFile("say.bat", wxFile::write).Write(
        "@echo off\n"
        "echo Dim Speak >> %TEMP%\\speak.vbs\n"
        "echo Set Speak=CreateObject(\"sapi.spvoice\") >> %TEMP%\\speak.vbs\n"
        "echo Speak.Speak %*>> %TEMP%\\speak.vbs\n"
        "%TEMP%\\speak.vbs\n"
        "del %TEMP%\\speak.vbs"
      );
    else if (wxPlatformInfo::Get().GetOperatingSystemFamilyName() == "Unix") {
      wxFile("say", wxFile::write).Write(
        "#!/bin/bash\n"
        "echo $* | espeak"
      );
      permissions("say", perms::owner_all);
    }
    (new Frame1)->Show();
    return true;
  }
};

wxIMPLEMENT_APP(Application);
