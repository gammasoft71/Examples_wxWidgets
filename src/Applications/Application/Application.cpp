#include <wx/wx.h>

namespace Examples {
  class Application : public wxApp {
    bool OnInit() override {
      (new wxFrame(nullptr, wxID_ANY, wxEmptyString))->Show();
      return true;
    }
  };
}

wxIMPLEMENT_APP(Examples::Application);
