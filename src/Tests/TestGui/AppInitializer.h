#pragma once
#include <memory>
#include <wx/wx.h>
#include <wx/aboutdlg.h>

struct AppInitializer {
  AppInitializer() {
    if (wxTheApp) return;
    wxApp::SetInstance(new wxApp());
    int argc = 0;
    wxEntryStart(argc, (wxChar**)NULL);
    wxTheApp->CallOnInit();
#if __WXOSX__
    wxTheApp->SetExitOnFrameDelete(false);
    wxMenuBar* menubar = new wxMenuBar();
    wxMenu* menuWindow = new wxMenu();
    wxMenuItem* aboutMenuItem = new wxMenuItem(menuWindow, wxID_ANY, "About");
    
    menubar->Append(menuWindow, "Window");
    menubar->Bind(wxEVT_MENU, [&](wxCommandEvent& event) {
      if (event.GetId() == wxID_ABOUT) wxAboutBox(wxAboutDialogInfo());
      if (event.GetId() == wxID_EXIT) {
        bool can_quit = true;
        for (wxWindow* window : wxTopLevelWindows) {
          can_quit = window->Close();
          if (!can_quit) break;
        }
        if (can_quit) wxTheApp->ExitMainLoop();
      } else event.Skip();
    });
    
    wxApp::s_macAboutMenuItemId = aboutMenuItem->GetId();
#if wxMAJOR_VERSION >= 3 && wxMINOR_VERSION >= 1
    wxApp::s_macWindowMenuTitleName = "Window";
#endif
    wxMenuBar::MacSetCommonMenuBar(menubar);
#endif
  }
  
  ~AppInitializer() {
    if (!wxTheApp) return;
    wxTheApp->OnExit();
    wxEntryCleanup();
    delete wxTheApp;
    wxApp::SetInstance(nullptr);
  }
};
