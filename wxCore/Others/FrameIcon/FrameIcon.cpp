#include <wx/wx.h>
#include "Gammasoft.xpm"

namespace FrameIconExample {
  class Application : public wxApp {
    bool OnInit() override {
      wxFrame* frame = new wxFrame(nullptr, wxID_ANY, "Window Icon example");
      frame->SetIcon(GammasoftLogo32x32);
      return frame->Show();
    }
  };
}

wxIMPLEMENT_APP(FrameIconExample::Application);
