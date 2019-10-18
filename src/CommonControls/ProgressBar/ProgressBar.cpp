#include <wx/wx.h>

class Form : public wxFrame {
public:
  Form() : wxFrame(nullptr, wxID_ANY, "ProgressBar example", wxDefaultPosition, wxSize(300, 300)) {
    progressBar2->SetValue(50);
 
    progressBar3->SetRange(300);
    progressBar3->SetValue(300);

    timer.Bind(wxEVT_TIMER, [&](wxTimerEvent& event) {
      progressBar4->SetValue(progressBar4->GetValue() < progressBar4->GetRange() ? progressBar4->GetValue() + 1 : 0);
      progressBar5->Pulse();
    });
    timer.Start(50);

  }
  
private:
  wxPanel* panel = new wxPanel(this);
  wxGauge* progressBar1 = new wxGauge(panel, wxID_ANY, 100, wxPoint(50, 50), wxSize(200, 25));
  wxGauge* progressBar2 = new wxGauge(panel, wxID_ANY, 100, wxPoint(50, 80), wxSize(200, 25));
  wxGauge* progressBar3 = new wxGauge(panel, wxID_ANY, 100, wxPoint(50, 110), wxSize(200, 25));
  wxGauge* progressBar4 = new wxGauge(panel, wxID_ANY, 100, wxPoint(50, 140), wxSize(200, 25));
  wxGauge* progressBar5 = new wxGauge(panel, wxID_ANY, 100, wxPoint(50, 170), wxSize(200, 25));
  wxTimer timer;
};

class Application : public wxApp {
  bool OnInit() override {(new Form())->Show(); return true;}
};

wxIMPLEMENT_APP(Application);
