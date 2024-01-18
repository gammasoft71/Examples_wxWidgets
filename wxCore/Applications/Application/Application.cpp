#include <wx/wx.h>

namespace ApplicationExample {
  class Application : public wxApp {
    bool OnInit() override {
      (new wxFrame(nullptr, wxID_ANY, wxEmptyString))->Show();
      return true;
    }
  };
}

wxIMPLEMENT_APP(ApplicationExample::Application);
