#pragma once
#include <memory>
#include <wx/wx.h>

struct AppInitializer {
  AppInitializer() {
    if (wxTheApp) return;
    wxApp::SetInstance(new wxApp());
    this->wxinitializer = make_unique<wxInitializer>();
    wxTheApp->CallOnInit();
  }
  
  ~AppInitializer() {
    if (!this->wxinitializer) return;
    wxTheApp->OnExit();
    this->wxinitializer = nullptr;
  }
  
  std::unique_ptr<wxInitializer> wxinitializer;
};
