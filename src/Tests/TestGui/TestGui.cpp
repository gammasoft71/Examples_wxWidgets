#include <wx/wx.h>
#include "AppInitializer.h"

int main(int argc, char* argv[]) {
  AppInitializer appInitializer;
  wxFrame* form1 = new wxFrame(nullptr, wxID_ANY, "TestGui");
  form1->Show();
  wxTheApp->OnRun();
}
