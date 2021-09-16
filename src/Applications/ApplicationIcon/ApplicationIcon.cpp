#include <wx/wx.h>
#include <wx/filename.h>
#include <wx/stdpaths.h>

namespace Examples {
  class Application : public wxApp {
    bool OnInit() override {
      wxFrame* frame = new wxFrame(nullptr, wxID_ANY, wxEmptyString);
      wxImage::AddHandler(new wxPNGHandler());
      wxFileName imagePath(wxStandardPaths::Get().GetExecutablePath());
      if (wxPlatformInfo::Get().GetOperatingSystemFamilyName() == "Macintosh") imagePath.AppendDir("..");
      imagePath.AppendDir("Resources");
      imagePath.SetFullName("Gammasoft");
      imagePath.SetExt("png");
      frame->SetIcon({imagePath.GetFullPath(), wxBITMAP_TYPE_PNG});
      return frame->Show();
    }
  };
}

wxIMPLEMENT_APP(Examples::Application);
