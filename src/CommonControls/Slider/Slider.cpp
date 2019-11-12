#include <wx/app.h>
#include <wx/gauge.h>
#include <wx/Slider.h>
#include <wx/frame.h>
#include <wx/panel.h>

class Frame : public wxFrame {
public:
  Frame() : wxFrame(nullptr, wxID_ANY, "Slider example", wxDefaultPosition, wxSize(300, 300)) {
    gauge1->SetValue(100);
    staticText1->SetLabel(wxString::Format("%d", slider1->GetValue()));
    slider1->Bind(wxEVT_SLIDER, [&](wxCommandEvent& event) {
      gauge1->SetValue(slider1->GetValue());
      staticText1->SetLabel(wxString::Format("%d", slider1->GetValue()));
    });
  }
  
private:
  wxPanel* panel = new wxPanel(this);
  wxSlider* slider1 = new wxSlider(panel, wxID_ANY, 100, 0, 200, wxPoint(20, 50), wxSize(200, 25));
  wxGauge* gauge1 = new wxGauge(panel, wxID_ANY, 200, wxPoint(20, 100), wxSize(200, 25));
  wxStaticText* staticText1 = new wxStaticText(panel, wxID_ANY, wxEmptyString, wxPoint(20, 150));
};

class Application : public wxApp {
  bool OnInit() override {(new Frame())->Show(); return true;}
};

wxIMPLEMENT_APP(Application);
