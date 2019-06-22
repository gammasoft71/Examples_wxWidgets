#include <wx/wx.h>

class Form : public wxFrame {
public:
  Form() : wxFrame(nullptr, wxID_ANY, "ProgressBar example", wxDefaultPosition, wxSize(300, 300)) {
    this->progressBar2->SetValue(50);
 
    this->progressBar3->SetRange(300);
    this->progressBar3->SetValue(300);

    this->timer.Bind(wxEVT_TIMER, [&](wxTimerEvent& event) {
      this->progressBar4->SetValue(this->progressBar4->GetValue() < this->progressBar4->GetRange() ? this->progressBar4->GetValue() + 1 : 0);
    });
    this->timer.Start(50);

    this->progressBar5->Pulse();
  }
  
private:
  wxPanel* panel = new wxPanel(this);
  wxGauge* progressBar1 = new wxGauge(this->panel, wxID_ANY, 100, wxPoint(50, 50), wxSize(200, 25));
  wxGauge* progressBar2 = new wxGauge(this->panel, wxID_ANY, 100, wxPoint(50, 80), wxSize(200, 25));
  wxGauge* progressBar3 = new wxGauge(this->panel, wxID_ANY, 100, wxPoint(50, 110), wxSize(200, 25));
  wxGauge* progressBar4 = new wxGauge(this->panel, wxID_ANY, 100, wxPoint(50, 140), wxSize(200, 25));
  wxGauge* progressBar5 = new wxGauge(this->panel, wxID_ANY, 100, wxPoint(50, 170), wxSize(200, 25));
  wxTimer timer;
};

class Application : public wxApp {
  bool OnInit() override {return (new Form())->Show();}
};

wxIMPLEMENT_APP(Application);
