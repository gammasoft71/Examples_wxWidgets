#include <wx/wx.h>

namespace Examples {
  class Form : public wxFrame {
  public:
    Form() : wxFrame(nullptr, wxID_ANY, "TrackBar example", wxDefaultPosition, wxSize(300, 300)) {
      this->progressBar1.SetValue(this->trackBar1.GetValue());
      this->label1.SetLabel(wxString::Format("%d", this->trackBar1.GetValue()));
      this->trackBar1.Bind(wxEVT_SLIDER, [&](wxCommandEvent& event) {
        this->progressBar1.SetValue(this->trackBar1.GetValue());
        this->label1.SetLabel(wxString::Format("%d", this->trackBar1.GetValue()));
      });
    }
    
  private:
    wxPanel panel {this};
    wxSlider trackBar1 {&this->panel, wxID_ANY, 100, 0, 200, wxPoint(20, 50), wxSize(200, 25)};
    wxGauge progressBar1 {&this->panel, wxID_ANY, 200, wxPoint(20, 100), wxSize(200, 25)};
    wxStaticText label1 {&this->panel, wxID_ANY, wxEmptyString, wxPoint(20, 150)};
  };
  
  class Application : public wxApp {
    bool OnInit() override {return (new Form())->Show();}
  };
}

wxIMPLEMENT_APP(Examples::Application);
