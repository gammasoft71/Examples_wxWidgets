#include "Application.h"
#include <wx/frame.h>
#include <wx/panel.h>

int main() {
  auto application = new wxApplication;
  auto frame = new wxFrame(nullptr, wxID_ANY, "TestGui", wxDefaultPosition, {300, 300});
  //auto panel = new wxPanel(frame);
  frame->Show();
  return application->MainLoop();
}
