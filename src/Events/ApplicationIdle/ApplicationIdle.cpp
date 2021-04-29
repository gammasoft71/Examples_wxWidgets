#include <chrono>
#include <thread>
#include <wx/wx.h>

using namespace std::chrono;
using namespace std::this_thread;
using namespace std::chrono_literals;

namespace Examples {
  class Frame : public wxFrame {
  public:
    Frame() : wxFrame(nullptr, wxID_ANY, wxEmptyString) {}
    
    void OnApplicationIdle() {
      SetLabel(wxString::Format("%d", ++counter));
    }
    
  private:
    wxPanel* panel = new wxPanel(this);
    int counter = 0;
  };

  class Application : public wxApp {
    bool OnInit() override {
      (frame = new Frame())->Show();
      return true;
    }
   
    bool ProcessIdle() override {
      if (!frame->IsVisible()) return wxApp::ProcessIdle();

      static auto lastIdleTime = high_resolution_clock::now();
      auto elapsedTime = high_resolution_clock::now() - lastIdleTime;
      if (elapsedTime >= 100ms) {
        frame->OnApplicationIdle();
        lastIdleTime = high_resolution_clock::now();
      }

      wxApp::ProcessIdle();
      sleep_for(20ms);
      return true;
    }

    Frame* frame = nullptr;
  };
}

wxIMPLEMENT_APP(Examples::Application);
