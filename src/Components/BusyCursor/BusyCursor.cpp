#include <thread>
#include <wx/wx.h>
#include <wx/utils.h>

namespace Examples {
  class Frame : public wxFrame {
  public:
    Frame() : wxFrame(nullptr, wxID_ANY, "BusyCursor example", wxDefaultPosition, {300, 300}) {
      button->Bind(wxEVT_BUTTON, [](wxCommandEvent& event) {
        wxBusyCursor busyCursor;
        for (auto count = 0; count < 500; ++count) {
          std::this_thread::sleep_for(std::chrono::milliseconds(10));
          wxYield();
        }
      });
    }
    
  private:
    wxPanel* panel = new wxPanel(this);
    wxButton* button = new wxButton(panel, wxID_ANY, "Do something...", {10, 10});
  };

  class Application : public wxApp {
    bool OnInit() override {
      (new Frame())->Show();
      return true;
    }
  };
}

wxIMPLEMENT_APP(Examples::Application);
