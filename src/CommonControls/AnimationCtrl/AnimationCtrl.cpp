#include <filesystem>
#include <wx/app.h>
#include <wx/frame.h>
#include <wx/panel.h>
#include <wx/animate.h>

namespace Examples {
  class Frame : public wxFrame {
  public:
    Frame() : wxFrame(nullptr, wxID_ANY, "AnimationCtrl example") {
      bool exists = std::filesystem::exists("Resources/open.gif");
      bool loaded = animationCtrl->LoadFile("Resources/open.gif", wxANIMATION_TYPE_GIF);
      animationCtrl->Play();
    }
    
  private:
    wxPanel* panel = new wxPanel(this);
    wxAnimationCtrl* animationCtrl = new wxAnimationCtrl(panel, wxID_ANY, wxNullAnimation, {10, 10}, {245, 200});
  };

  class Application : public wxApp {
    bool OnInit() override {
      (new Frame())->Show();
      return true;
    }
  };
}

wxIMPLEMENT_APP(Examples::Application);
