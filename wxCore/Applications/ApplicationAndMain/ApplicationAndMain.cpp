#include <wx/app.h>
#include <wx/frame.h>

namespace ApplicationAndMainExample {
  class Application : public wxApp {
    bool OnInit() override {
      (new wxFrame)->Show();
      return true;
    }
  };
}

int main(int argc, char* argv[]) {
  wxDISABLE_DEBUG_SUPPORT();
  new ApplicationAndMainExample::Application;
  return wxEntry(argc, argv);
}
