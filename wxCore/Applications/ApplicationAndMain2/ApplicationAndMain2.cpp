#include "Application.h"
#include <wx/wx.h>

int main() {
  auto application = new wxApplication;
  application->MainLoop(new wxFrame(nullptr, wxID_ANY, wxEmptyString));
}
