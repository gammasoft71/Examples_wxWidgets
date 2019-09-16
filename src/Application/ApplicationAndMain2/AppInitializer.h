#pragma once
#include <memory>
#include <wx/wx.h>

struct AppInitializer {
  AppInitializer() {
    if (wxTheApp) return;
    wxApp::SetInstance(new wxApp());
    int argc = 0;
    wxEntryStart(argc, (wxChar**)NULL);
    wxTheApp->CallOnInit();
  }
  
  ~AppInitializer() {
    if (!wxTheApp) return;
    wxTheApp->OnExit();
    wxEntryCleanup();
    delete wxTheApp;
    wxApp::SetInstance(nullptr);
  }
};
