#include <wx/wx.h>

class Application : public wxApp {
public:
  bool OnInit() override {(new wxFrame(nullptr, wxID_ANY, ""))->Show(); return true;}
};

Application& wxGetApp() { return *static_cast<Application*>(wxApp::GetInstance()); }

wxAppInitializer wxTheAppInitializer([]()->wxAppConsole* {
  wxAppConsole::CheckBuildOptions(WX_BUILD_OPTIONS_SIGNATURE, "your program");
  return new Application();
});

int main(int argc, char* argv[]) {
  return wxEntry(argc, argv);
}
