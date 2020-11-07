#include <wx/wx.h>

namespace Examples {
  class Frame : public wxFrame {
  public:
    Frame() : wxFrame(nullptr, wxID_ANY, "Gauge example") {
      gauge2->SetValue(50);
   
      gauge3->SetRange(300);
      gauge3->SetValue(300);

      timer.Bind(wxEVT_TIMER, [&](wxTimerEvent& event) {
        gauge4->SetValue(gauge4->GetValue() < gauge4->GetRange() ? gauge4->GetValue() + 1 : 0);
        gaude5->Pulse();
      });
      timer.Start(50);
    }
    
  private:
    wxPanel* panel = new wxPanel(this);
    wxGauge* gauge1 = new wxGauge(panel, wxID_ANY, 100, {90, 30}, {200, 25});
    wxGauge* gauge2 = new wxGauge(panel, wxID_ANY, 100, {90, 60}, {200, 25});
    wxGauge* gauge3 = new wxGauge(panel, wxID_ANY, 100, {90, 90}, {200, 25});
    wxGauge* gauge4 = new wxGauge(panel, wxID_ANY, 100, {90, 120}, {200, 25});
    wxGauge* gaude5 = new wxGauge(panel, wxID_ANY, 100, {90, 150}, {200, 25});
    wxTimer timer;
  };

  class Application : public wxApp {
    bool OnInit() override {
      (new Frame())->Show();
      return true;
    }
  };
}

wxIMPLEMENT_APP(Examples::Application);
