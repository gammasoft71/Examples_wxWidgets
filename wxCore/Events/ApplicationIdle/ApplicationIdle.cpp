#include <wx/app.h>
#include <wx/frame.h>
#include <wx/panel.h>
#include <wx/stopwatch.h>

namespace ApplictionIdleExample {
  class Frame : public wxFrame {
  public:
    Frame() : wxFrame {nullptr, wxID_ANY, wxEmptyString} {}
    
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

      static auto stopWatch = [] {
        auto value = wxStopWatch {};
        value.Start();
        return value;
      }();
      
      if (stopWatch.Time() >= 100) {
        frame->OnApplicationIdle();
        stopWatch.Start();
      }
      wxApp::ProcessIdle();
      wxMilliSleep(20);
      return true;
    }
    
    Frame* frame = nullptr;
  };
}

wxIMPLEMENT_APP(ApplictionIdleExample::Application);
