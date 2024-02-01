#include <wx/app.h>
#include <wx/frame.h>

namespace ApplicationExample {
  class Application : public wxApp {
    bool OnInit() override {
      (new wxFrame {})->Show();
      return true;
    }
  };
}

wxIMPLEMENT_APP(ApplicationExample::Application);
