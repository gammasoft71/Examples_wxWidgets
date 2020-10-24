#include <wx/wx.h>

class Application : public wxApp {
  bool OnInit() override {
    wxMessageDialog(nullptr, "Hello, World!").ShowModal();
    return false;
  }
};

wxIMPLEMENT_APP(Application);
