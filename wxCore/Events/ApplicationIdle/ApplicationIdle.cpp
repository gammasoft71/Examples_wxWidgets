#include <chrono>
#include <wx/wx.h>

using namespace std::chrono;
using namespace std::chrono_literals;

namespace ApplictionIdleExample {
  class Frame : public wxFrame {
  public:
    Frame() : wxFrame(nullptr, wxID_ANY, wxEmptyString) {}
    
    void OnApplicationIdle() {
      SetLabel(wxString::Format("%d", ++counter));
    }
    
  private:
    wxPanel* panel = new wxPanel {this};
    int counter = 0;
  };

  class Application : public wxApp {
    bool OnInit() override {return (frame = new Frame())->Show();}
   
    bool ProcessIdle() override {
      if (!frame->IsVisible()) return wxApp::ProcessIdle();

      static auto lastIdleTime = high_resolution_clock::now();
      auto elapsedTime = high_resolution_clock::now() - lastIdleTime;
      if (elapsedTime >= 100ms) {
        frame->OnApplicationIdle();
        lastIdleTime = high_resolution_clock::now();
      }

      wxApp::ProcessIdle();
      wxMilliSleep(20);
      return true;
    }

    Frame* frame = nullptr;
  };
}

wxIMPLEMENT_APP(ApplictionIdleExample::Application);
