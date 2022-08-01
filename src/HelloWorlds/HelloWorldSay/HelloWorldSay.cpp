#include <filesystem>
#include <wx/wx.h>
#include <wx/file.h>
#include <wx/process.h>

using namespace std::filesystem;

class Frame1 : public wxFrame {
public:
  Frame1() : wxFrame(nullptr, wxID_ANY, "Hello world (say)") {
    if (wxPlatformInfo::Get().GetOperatingSystemFamilyName() == "Windows") wxFile(sayCmdFile.string(), wxFile::write).Write("@echo Set Speaker=CreateObject(\"sapi.spvoice\") > %TEMP%\\say.vbs\n@echo Speaker.Speak \"%*\" >> %TEMP%\\say.vbs\n@%TEMP%\\say.vbs");
    else if (wxPlatformInfo::Get().GetOperatingSystemFamilyName() == "Macintosh") wxFile(sayCmdFile.string(), wxFile::write).Write("say \"$*\"");
    else wxFile(sayCmdFile.string(), wxFile::write).Write("spd-say \"$*\"");
    permissions(sayCmdFile, perms::owner_all);

    button1->Bind(wxEVT_BUTTON, [&](wxCommandEvent&) {
      wxProcess::Open(wxString::Format("%s Hello, World!", sayCmdFile.string()));
    });
  }

private:
  path sayCmdFile = temp_directory_path() / "say.cmd";
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
