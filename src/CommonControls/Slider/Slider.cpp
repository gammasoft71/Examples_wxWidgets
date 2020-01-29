#include <wx/app.h>
#include <wx/gauge.h>
#include <wx/Slider.h>
#include <wx/frame.h>
#include <wx/panel.h>
#include <wx/stattext.h>

namespace Examples {
  class Frame : public wxFrame {
  public:
    Frame() : wxFrame(nullptr, wxID_ANY, "Slider example") {
      SetClientSize(300, 300);
      
      gauge1->SetValue(100);
      staticText1->SetLabel(wxString::Format("%d", slider1->GetValue()));
      slider1->Bind(wxEVT_SLIDER, [&](wxCommandEvent& event) {
        gauge1->SetValue(slider1->GetValue());
        staticText1->SetLabel(wxString::Format("%d", slider1->GetValue()));
      });
    }
    
  private:
    wxPanel* panel = new wxPanel(this);
    wxSlider* slider1 = new wxSlider(panel, wxID_ANY, 100, 0, 200, {50, 50}, {25, 200}, wxSL_VERTICAL|wxSL_INVERSE);
    wxGauge* gauge1 = new wxGauge(panel, wxID_ANY, 200, {80, 50}, {25, 200}, wxGA_VERTICAL);
    wxStaticText* staticText1 = new wxStaticText(panel, wxID_ANY, wxEmptyString, {150, 50});
  };

  class Application : public wxApp {
    bool OnInit() override {
      (new Frame())->Show();
      return true;
    }
  };
}

wxIMPLEMENT_APP(Examples::Application);
