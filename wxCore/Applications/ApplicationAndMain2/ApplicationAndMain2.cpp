#include "Application.h"
#include <wx/frame.h>

int main() {
  auto application = wxApplication {};
  application.MainLoop(new wxFrame {nullptr, wxID_ANY, wxEmptyString});
}
