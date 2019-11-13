#include <wx/app.h>
#include <wx/bmpbuttn.h>
#include <wx/button.h>
#include <wx/frame.h>
#include <wx/panel.h>
#include <wx/stattext.h>

class Frame : public wxFrame {
  #include "Gammasoft-32x32.xpm"
public:
  Frame() : wxFrame(nullptr, wxID_ANY, "BitmapButton example", wxDefaultPosition, wxSize(300, 300)) {
    button1->SetBitmapLabel(gammasoft_32x32);
    button1->SetSize(40, 40);
    button1->Bind(wxEVT_BUTTON, [this](wxCommandEvent& event) {
      staticText1->SetLabel(wxString::Format("button1 clicked %d times", ++button1Clicked));
    });

    button2->Bind(wxEVT_BUTTON, [this](wxCommandEvent& event) {
      staticText2->SetLabel(wxString::Format("button2 clicked %d times", ++button2Clicked));
    });
  }
  
private:
  wxPanel* panel = new wxPanel(this);
  wxButton* button1 = new wxButton(panel, wxID_ANY, wxEmptyString, wxPoint(50, 50));
  wxBitmapButton* button2 = new wxBitmapButton(panel, wxID_ANY, gammasoft_32x32, wxPoint(100, 50));
  wxStaticText* staticText1 = new wxStaticText(panel, wxID_ANY, "button1 clicked 0 times", wxPoint(50, 120));
  wxStaticText* staticText2 = new wxStaticText(panel, wxID_ANY, "button2 clicked 0 times", wxPoint(50, 150));
  int button1Clicked = 0;
  int button2Clicked = 0;
};

class Application : public wxApp {
  bool OnInit() override {(new Frame())->Show(); return true;}
};

wxIMPLEMENT_APP(Application);
