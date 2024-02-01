#include <wx/app.h>
#include <wx/frame.h>
#include <wx/filename.h>
#include <wx/image.h>
#include <wx/stdpaths.h>

namespace ApplicationIconExample {
  class Application : public wxApp {
    bool OnInit() override {
      auto frame = new wxFrame;
      wxImage::AddHandler(new wxPNGHandler);
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

wxIMPLEMENT_APP(ApplicationIconExample::Application);
