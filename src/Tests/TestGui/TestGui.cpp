#include "Application.h"
#include <wx/frame.h>
#include <wx/panel.h>

class MainFrame : public wxFrame {
public:
  MainFrame() : wxFrame(nullptr, wxID_ANY, "TestGui", wxDefaultPosition, {300, 300}) {
  }
  
private:
  wxPanel* panel = new wxPanel(this);
};

int main() {
  auto application = new wxApplication;
  auto frame = new MainFrame();
  frame->Show();
  return application->MainLoop();
}
