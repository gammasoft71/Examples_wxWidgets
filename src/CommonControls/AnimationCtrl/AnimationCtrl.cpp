#include <filesystem>
#include <wx/app.h>
#include <wx/frame.h>
#include <wx/panel.h>
#include <wx/animate.h>

namespace Examples {
  class Frame : public wxFrame {
  public:
    Frame() : wxFrame(nullptr, wxID_ANY, "AnimationCtrl example") {
      SetClientSize(animationCtrl->GetSize());
      animationCtrl->Play();
    }
    
  private:
    wxAnimationCtrl* animationCtrl = new wxAnimationCtrl(this, wxID_ANY, wxAnimation("Resources/load.gif"));
  };

  class Application : public wxApp {
    bool OnInit() override {
      (new Frame())->Show();
      return true;
    }
  };
}

wxIMPLEMENT_APP(Examples::Application);
