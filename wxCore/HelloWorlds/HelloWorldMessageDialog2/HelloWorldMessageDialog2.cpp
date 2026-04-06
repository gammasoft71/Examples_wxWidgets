#include <wx/wx.h>

class Application : public wxApp {
  auto OnInit() -> bool override {
    wxMessageDialog(nullptr, "Hello, World!").ShowModal();
    return false;
  }
};

wxIMPLEMENT_APP(Application);
