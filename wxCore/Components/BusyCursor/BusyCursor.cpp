#include <wx/app.h>
#include <wx/button.h>
#include <wx/frame.h>
#include <wx/panel.h>

namespace BusyCursorExample {
  class Frame : public wxFrame {
  public:
    Frame() : wxFrame {nullptr, wxID_ANY, "BusyCursor example"} {
      button->Bind(wxEVT_BUTTON, [](wxCommandEvent& event) {
        auto busyCursor = wxBusyCursor {};
        for (auto count = 0; count < 500; ++count) {
          wxMilliSleep(10); // Simulate work...
          wxYield();
        }
      });
    }
    
  private:
    wxPanel* panel = new wxPanel {this};
    wxButton* button = new wxButton {panel, wxID_ANY, "Do something...", {10, 10}};
  };

  class Application : public wxApp {
    bool OnInit() override {return (new Frame)->Show();}
  };
}

wxIMPLEMENT_APP(BusyCursorExample::Application);
