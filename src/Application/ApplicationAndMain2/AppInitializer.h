#pragma once
#include <wx/wx.h>

struct AppInitializer {
  AppInitializer() : AppInitializer(nullptr, true) {}
  AppInitializer(wxApp* app) : AppInitializer(app, true) {}
  AppInitializer(bool exit_on_last_frame_closed) : AppInitializer(nullptr, exit_on_last_frame_closed) {}
  AppInitializer(wxApp* app, bool exit_on_last_frame_closed) {
    wxDISABLE_DEBUG_SUPPORT();
    wxApp::SetInstance(app ? app : new wxApp());
    int argc = 0;
    wxEntryStart(argc, (wxChar**)NULL);
    wxTheApp->CallOnInit();
    wxTheApp->SetExitOnFrameDelete(exit_on_last_frame_closed);
    wxInitAllImageHandlers();
#if __WXOSX__
    wxMenuBar* menubar = new wxMenuBar();
    menubar->Bind(wxEVT_MENU, [&](wxCommandEvent& event) {
      if (event.GetId() == wxID_EXIT) {
        auto can_quit = true;
        for (auto window : wxTopLevelWindows)
          if (!(can_quit = window->Close())) break;
        if (can_quit) wxTheApp->ExitMainLoop();
      } else event.Skip();
    });
    wxMenuBar::MacSetCommonMenuBar(menubar);
#endif
  }
  
  ~AppInitializer() {
    if (!wxTheApp) return;
    wxImage::CleanUpHandlers();
    wxTheApp->OnExit();
    wxEntryCleanup();
    delete wxTheApp;
    wxApp::SetInstance(nullptr);
  }
};
