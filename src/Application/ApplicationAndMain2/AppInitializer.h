#pragma once
#include <memory>
#include <wx/wx.h>

struct AppInitializer {
  AppInitializer() {
    if (wxTheApp) return;
    wxApp::SetInstance(new wx_application());
    this->wxinitializer = make_unique<wxInitializer>();
    wxTheApp->CallOnInit();
  }
  
  ~AppInitializer() {
    wxTheApp->OnExit();
    this->wxinitializer = nullptr;
  }
  
  std::unique_ptr<wxInitializer> wxinitializer;
};
