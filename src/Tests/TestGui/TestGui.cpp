#include <fstream>
#include <wx/wx.h>
#include "AppInitializer.h"

int main(int argc, char* argv[]) {
  AppInitializer appInitializer;
  wxFrame* form1 = new wxFrame(nullptr, wxID_ANY, "TestGui", wxDefaultPosition, {300, 300});

  wxScrolled<wxPanel>* panel = new wxScrolled<wxPanel>(form1, wxID_ANY, wxDefaultPosition, wxDefaultSize, 0);
  //wxPanel* panel = new wxPanel(form1, wxID_ANY, wxDefaultPosition, wxDefaultSize, 0);

  form1->Show();

  //panel->ShowScrollbars(wxScrollbarVisibility::wxSHOW_SB_DEFAULT, wxScrollbarVisibility::wxSHOW_SB_DEFAULT);
  //panel->SetVirtualSize({0, 0});
  panel->SetVirtualSize({450, 375});
  panel->SetScrollRate(10, 10);
  
  wxPanel* panel1 = new wxPanel(panel, wxID_ANY, {350, 350}, {200, 100});
  panel1->SetBackgroundColour(wxColour(0, 128, 0));
  
  //panel->Scroll(30, 0);
  
  wxTheApp->OnRun();
}
