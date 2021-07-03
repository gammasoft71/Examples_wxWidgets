#include <wx/wx.h>

namespace Examples {
  class Application : public wxApp {
    bool OnInit() override {
      (new wxFrame(nullptr, wxID_ANY, wxEmptyString))->Show();
      return true;
    }
  };
}

int main(int argc, char* argv[]) {
  wxDISABLE_DEBUG_SUPPORT();
  new Examples::Application();
  return wxEntry(argc, argv);
}
