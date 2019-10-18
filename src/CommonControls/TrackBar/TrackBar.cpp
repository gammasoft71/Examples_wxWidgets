#include <wx/wx.h>

class Form : public wxFrame {
public:
  Form() : wxFrame(nullptr, wxID_ANY, "TrackBar example", wxDefaultPosition, wxSize(300, 300)) {
    progressBar1->SetValue(100);
    label1->SetLabel(wxString::Format("%d", trackBar1->GetValue()));
    trackBar1->Bind(wxEVT_SLIDER, [&](wxCommandEvent& event) {
      progressBar1->SetValue(trackBar1->GetValue());
      label1->SetLabel(wxString::Format("%d", trackBar1->GetValue()));
    });
  }
  
private:
  wxPanel* panel = new wxPanel(this);
  wxSlider* trackBar1 = new wxSlider(panel, wxID_ANY, 100, 0, 200, wxPoint(20, 50), wxSize(200, 25));
  wxGauge* progressBar1 = new wxGauge(panel, wxID_ANY, 200, wxPoint(20, 100), wxSize(200, 25));
  wxStaticText* label1 = new wxStaticText(panel, wxID_ANY, wxEmptyString, wxPoint(20, 150));
};

class Application : public wxApp {
  bool OnInit() override {(new Form())->Show(); return true;}
};

wxIMPLEMENT_APP(Application);
