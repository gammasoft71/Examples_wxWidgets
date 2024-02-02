#include "Application.h"
#include <wx/frame.h>

int main() {
  auto application = new wxApplication;
  application->MainLoop(new wxFrame);
}
