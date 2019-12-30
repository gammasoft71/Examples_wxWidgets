#include <wx/wx.h>
#include "AppInitializer.h"

int main(int argc, char* argv[]) {
  AppInitializer appInitializer;
  wxFrame* frame1 = new wxFrame(nullptr, wxID_ANY, "Frame1", wxDefaultPosition, {300, 300});
  frame1->Show();
  wxTheApp->OnRun();
}
