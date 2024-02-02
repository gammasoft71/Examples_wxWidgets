#include <wx/app.h>
#include <wx/frame.h>
#include <wx/panel.h>
#include <wx/activityindicator.h>

namespace ActivityIndicatorExample {
  class Frame : public wxFrame {
  public:
    Frame() : wxFrame(nullptr, wxID_ANY, "ActivityIndicator example") {
      activityIndicator->Start();
    }
    
  private:
    wxPanel* panel = new wxPanel {this};
    wxActivityIndicator* activityIndicator = new wxActivityIndicator(panel, wxID_ANY, {10, 10});
  };

  class Application : public wxApp {
    bool OnInit() override {
      (new Frame)->Show();
      return true;
    }
  };
}

wxIMPLEMENT_APP(ActivityIndicatorExample::Application);
