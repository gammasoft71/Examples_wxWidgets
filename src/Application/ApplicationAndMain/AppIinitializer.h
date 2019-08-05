#include <wx/wx.h>

struct AppIinitializer {
  AppIinitializer() {
    if (wxTheApp) return;
    wxApp::SetInstance(new wx_application());
    wxTheApp->CallOnInit();
  }
  
  ~AppIinitializer() {
    wxTheApp->OnExit();
  }
};
