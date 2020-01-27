#include "AppInitializer.h"
#include <wx/app.h>
#include <wx/artprov.h>
#include <wx/frame.h>
#include <wx/msgout.h>
#include <wx/panel.h>
#include <wx/menu.h>

int main(int argc, char* argv[]) {
  AppInitializer appInitializer;
  auto frame = new wxFrame(nullptr, wxID_ANY, "TestGui", wxDefaultPosition, {300, 300});
  //auto panelMain = new wxPanel(frame);
  
  auto menuBar = new wxMenuBar();
  auto menuFile = new wxMenu();
  
  auto menuItemFileNew = menuFile->Append(wxMenuItem::New(menuFile, wxID_ANY, "&New\tCTRL+N", "", wxITEM_NORMAL));
  menuItemFileNew->SetBitmap(wxArtProvider::GetBitmap(wxART_NEW));
  menuFile->AppendSeparator();
  auto menuItemFileOpen = menuFile->Append(wxMenuItem::New(menuFile, wxID_ANY, "Open\tRAWCTRL+O", "", wxITEM_NORMAL));
  menuItemFileOpen->SetBitmap(wxArtProvider::GetBitmap(wxART_FILE_OPEN));

  menuBar->Append(menuFile, "&File");

  auto menuWindow = new wxMenu();
  menuWindow->AppendSeparator();
  menuWindow->Append(wxID_ANY, "New frame");
  menuWindow->Append(wxID_ANY, "Hide");
  wxApp::s_macWindowMenuTitleName = "&Window";
  menuBar->Append(menuWindow, "&Window");

  auto menuHelp = new wxMenu();
  menuHelp->Append(wxID_ANY, "Index");
  menuHelp->Append(wxID_ANY, "Website");
  menuBar->Append(menuHelp, "&Help");
  
#if defined(__WXOSX__)
  if (menuBar->FindMenu("Window") == wxNOT_FOUND) menuBar->Append(new wxMenu(), "&Window");
  if (menuBar->FindMenu("Help") == wxNOT_FOUND) menuBar->Append(new wxMenu(), "&Help");
#endif

  menuBar->Bind(wxEVT_MENU, [&](wxCommandEvent& event) {
    if (event.GetId() == menuItemFileNew->GetId())
      wxMessageOutputDebug().Printf("New...");
    else if (event.GetId() == menuItemFileOpen->GetId())
      wxMessageOutputDebug().Printf("Open...");
    else event.Skip();
  });

  frame->SetMenuBar(menuBar);
  frame->Show();
  wxTheApp->OnRun();
}
