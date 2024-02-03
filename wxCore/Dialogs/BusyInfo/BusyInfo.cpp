#include <thread>
#include <wx/app.h>
#include <wx/artprov.h>
#include <wx/busyinfo.h>
#include <wx/button.h>
#include <wx/frame.h>
#include <wx/panel.h>

namespace BusyInfoExample {
  class Frame : public wxFrame {
  public:
    Frame() : wxFrame {nullptr, wxID_ANY, "BusyInfo example"} {
      button->Bind(wxEVT_BUTTON, [this](wxCommandEvent& event) {
        auto busiInfo = wxBusyInfo {wxBusyInfoFlags {}.Title("Application busy").Label("Please wait while do something...").Icon(wxArtProvider::GetIcon(wxART_WARNING)).Background({255, 0, 0}).Foreground({255, 255, 255}).Transparency(192)};
        for (auto count = 0; count < 500; ++count) {
          std::this_thread::sleep_for(std::chrono::milliseconds {10});
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

wxIMPLEMENT_APP(BusyInfoExample::Application);
