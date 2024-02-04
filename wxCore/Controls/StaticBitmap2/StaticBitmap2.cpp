#include <wx/app.h>
#include <wx/frame.h>
#include <wx/panel.h>
#include <wx/filename.h>
#include <wx/stdpaths.h>
#include <wx/statbmp.h>

namespace StaticBitmap2Example {
  class Frame : public wxFrame {
  public:
    Frame() : wxFrame {nullptr, wxID_ANY, "StaticBitmap2 example"} {
      SetClientSize(300, 300);
      wxInitAllImageHandlers();
      auto imagePath = wxFileName {wxStandardPaths::Get().GetExecutablePath()};
      if (wxPlatformInfo::Get().GetOperatingSystemFamilyName() == "Macintosh") {
        imagePath.AppendDir("..");
        imagePath.AppendDir("..");
        imagePath.AppendDir("..");
      }
      
      imagePath.AppendDir("Resources");
      imagePath.SetFullName("Logo");
      imagePath.SetExt("png");
      staticBitmap1->SetBitmap(wxBitmapBundle {wxBitmap {imagePath.GetFullPath(), wxBITMAP_TYPE_ANY}});
      staticBitmap1->SetWindowStyle(wxBORDER_SIMPLE);
    }

  private:
    wxPanel* panel = new wxPanel {this};
    wxStaticBitmap* staticBitmap1 = new wxStaticBitmap {panel, wxID_ANY, wxNullBitmap, {20, 20}, {100, 50}};
  };

  class Application : public wxApp {
    bool OnInit() override {return (new Frame)->Show();}
  };
}

wxIMPLEMENT_APP(StaticBitmap2Example::Application);
