#include <wx/wx.h>
#include "AppInitializer.h"

int main(int argc, char* argv[]) {
  AppInitializer appInitializer;
  wxFrame* form1 = new wxFrame(nullptr, wxID_ANY, "TestGui");
  form1->Show();
  wxMessageOutputDebug().Printf("ClientSize = %d, %d", form1->GetClientSize().GetWidth(), form1->GetClientSize().GetHeight());
  wxMessageOutputDebug().Printf("Size = %d, %d", form1->GetSize().GetWidth(), form1->GetSize().GetHeight());
  wxTheApp->OnRun();
}
