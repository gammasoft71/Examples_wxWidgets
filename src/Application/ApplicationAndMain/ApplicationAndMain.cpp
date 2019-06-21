#include <wx/wx.h>

namespace Examples {
  class Application : public wxApp {
    bool OnInit() override {(new wxFrame(nullptr, wxID_ANY, wxEmptyString))->Show(); return true;}
  };
}

wxAppInitializer wxTheAppInitializer {[] {
  return static_cast<wxAppConsole*>(new Examples::Application());
}};

int main(int argc, char* argv[]) {
  return wxEntry(argc, argv);
}
