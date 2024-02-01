#include <wx/app.h>
#include <wx/bmpbuttn.h>
#include <wx/frame.h>
#include <wx/panel.h>
#include <wx/stattext.h>
#include "gammasoft_16x16.xpm"
#include "gammasoft_64x64.xpm"

namespace BitmapButtonExample {
  class Frame : public wxFrame {
  public:
    Frame() : wxFrame(nullptr, wxID_ANY, "BitmapButton example") {
      button1->Bind(wxEVT_BUTTON, [&](wxCommandEvent& event) {
        staticText1->SetLabel(wxString::Format("button1 clicked %d times", ++button1Clicked));
      });
      
      button2->Bind(wxEVT_BUTTON, [&](wxCommandEvent& event) {
        staticText2->SetLabel(wxString::Format("button2 clicked %d times", ++button2Clicked));
      });
    }
    
  private:
    wxPanel* panel = new wxPanel(this);
    wxBitmapButton* button1 = new wxBitmapButton(panel, wxID_ANY, wxBitmapBundle {wxBitmap {gammasoft_16x16_xpm}}, { 50, 10 });
    wxBitmapButton* button2 = new wxBitmapButton(panel, wxID_ANY, wxBitmapBundle {wxBitmap {gammasoft_64x64_xpm}}, { 50, 60 });
    wxStaticText* staticText1 = new wxStaticText(panel, wxID_ANY, "button1 clicked 0 times", {50, 150}, {200, 20});
    wxStaticText* staticText2 = new wxStaticText(panel, wxID_ANY, "button2 clicked 0 times", {50, 180}, {200, 20});
    int button1Clicked = 0;
    int button2Clicked = 0;
  };

  class Application : public wxApp {
    bool OnInit() override {
      (new Frame)->Show();
      return true;
    }
  };
}

wxIMPLEMENT_APP(BitmapButtonExample::Application);
