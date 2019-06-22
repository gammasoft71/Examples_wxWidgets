#include <wx/wx.h>

class Form : public wxFrame {
public:
  Form() : wxFrame(nullptr, wxID_ANY, "Timer example", wxDefaultPosition, wxSize(230, 150)) {
    this->label->SetFont(wxFont(48, wxFONTFAMILY_DEFAULT, wxFONTSTYLE_ITALIC, wxFONTWEIGHT_NORMAL, false, "Arial"));
    this->label->SetForegroundColour(wxColour(30, 144, 255));

    this->timer->Bind(wxEVT_TIMER, [&](wxTimerEvent& event) {
      this->label->SetLabelText(wxString::Format("%.1f", static_cast<double>(++this->counter) / 10));
    });
    
    this->button->Bind(wxEVT_BUTTON, [&](wxCommandEvent& event) {
      if (this->timer->IsRunning())
        this->timer->Stop();
      else
        this->timer->Start(100);
      this->button->SetLabel(this->timer->IsRunning() ? "Stop" : "Start");
    });
  }
  
private:
  wxPanel* panel = new wxPanel(this);
  wxStaticText* label = new wxStaticText(this->panel, wxID_ANY, "0.0", wxPoint(10, 10));
  wxButton* button = new wxButton(this->panel, wxID_ANY, "Start", wxPoint(10, 90));
  wxTimer* timer = new wxTimer();
  int counter = 0;
};

class Application : public wxApp {
  bool OnInit() override {return (new Form())->Show();}
};

wxIMPLEMENT_APP(Application);
