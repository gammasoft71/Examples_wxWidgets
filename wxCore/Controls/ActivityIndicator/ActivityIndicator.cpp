#include <wx/activityindicator.h>
#include <wx/app.h>
#include <wx/frame.h>
#include <wx/panel.h>

namespace ActivityIndicatorExample {
  class Frame : public wxFrame {
  public:
    Frame() : wxFrame {nullptr, wxID_ANY, "ActivityIndicator example"} {
      activityIndicator->Start();
      panel->Bind(wxEVT_LEFT_DOWN, [&](wxMouseEvent& event) {
        if (activityIndicator->IsRunning()) activityIndicator->Stop();
        else activityIndicator->Start();
      });
    }
    
  private:
    wxPanel* panel = new wxPanel {this};
    wxActivityIndicator* activityIndicator = new wxActivityIndicator {panel, wxID_ANY, {10, 10}};
  };

  class Application : public wxApp {
    bool OnInit() override {return (new Frame)->Show();}
  };
}

wxIMPLEMENT_APP(ActivityIndicatorExample::Application);
