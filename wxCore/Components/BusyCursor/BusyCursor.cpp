#include <thread>
#include <wx/wx.h>
#include <wx/utils.h>

using namespace std::chrono;
using namespace std::this_thread;

namespace BusyCursorExample {
  class Frame : public wxFrame {
  public:
    Frame() : wxFrame(nullptr, wxID_ANY, "BusyCursor example") {
      button->Bind(wxEVT_BUTTON, [](wxCommandEvent& event) {
        wxBusyCursor busyCursor;
        for (auto count = 0; count < 500; ++count) {
          sleep_for(milliseconds(10)); // Simulate work...
          wxYield();
        }
      });
    }
    
  private:
    wxPanel* panel = new wxPanel {this};
    wxButton* button = new wxButton(panel, wxID_ANY, "Do something...", {10, 10});
  };

  class Application : public wxApp {
    bool OnInit() override {return (new Frame)->Show();}
  };
}

wxIMPLEMENT_APP(BusyCursorExample::Application);
