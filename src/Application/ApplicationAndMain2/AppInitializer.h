#pragma once
#include <memory>
#include <wx/wx.h>

struct AppIinitializer {
  AppIinitializer() {
    if (wxTheApp) return;
    wxApp::SetInstance(new wx_application());
    this->wxinitializer = make_unique<wxInitializer>();
    wxTheApp->CallOnInit();
  }
  
  ~AppIinitializer() {
    wxTheApp->OnExit();
    this->wxinitializer = nullptr;
  }
  
  std::unique_ptr<wxInitializer> wxinitializer;
};
