#include "Application.h"
#include <wx/frame.h>

int main() {
  auto application = wxApplication {};
  auto frame1 = new wxFrame {nullptr, wxID_ANY, wxEmptyString};
  application.MainLoop(frame1);
}
