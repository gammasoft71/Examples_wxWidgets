#include <wx/app.h>
#include <wx/frame.h>

namespace ApplicationExample {
  class Application : public wxApp {
    bool OnInit() override {return (new wxFrame {nullptr, wxID_ANY, wxEmptyString})->Show();}
  };
}

wxIMPLEMENT_APP(ApplicationExample::Application);
