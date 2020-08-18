#include <wx/wx.h>
#include "Application.h"

int main() {
  auto application = new wxApplication;
  auto frame1 = new wxFrame(nullptr, wxID_ANY, wxEmptyString);
  frame1->Show();
  return application->MainLoop();
}
