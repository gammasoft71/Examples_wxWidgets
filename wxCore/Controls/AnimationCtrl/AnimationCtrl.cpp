#include <wx/animate.h>
#include <wx/app.h>
#include <wx/filename.h>
#include <wx/frame.h>
#include <wx/panel.h>
#include <wx/stdpaths.h>

namespace AnimationCtrlExample {
  class Frame : public wxFrame {
  public:
    Frame() : wxFrame {nullptr, wxID_ANY, "AnimationCtrl example"} {
      auto imagePath = wxFileName {wxStandardPaths::Get().GetExecutablePath()};
      if (wxPlatformInfo::Get().GetOperatingSystemFamilyName() == "Macintosh") imagePath.AppendDir("..");
      imagePath.AppendDir("Resources");
      imagePath.SetFullName("load");
      imagePath.SetExt("gif");
      animationCtrl->SetAnimation(wxAnimation(imagePath.GetFullPath()));
      SetClientSize(animationCtrl->GetSize());
      animationCtrl->Play();
    }
    
  private:
    wxAnimationCtrl* animationCtrl = new wxAnimationCtrl {this, wxID_ANY, wxAnimation {}};
  };

  class Application : public wxApp {
    bool OnInit() override {return (new Frame)->Show();}
  };
}

wxIMPLEMENT_APP(AnimationCtrlExample::Application);
