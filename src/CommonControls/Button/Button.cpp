#include <wx/app.h>
#include <wx/button.h>
#include <wx/frame.h>
#include <wx/panel.h>
#include <wx/stattext.h>

class Frame : public wxFrame {
public:
  Frame() : wxFrame(nullptr, wxID_ANY, wxEmptyString, wxDefaultPosition, wxSize(300, 300)) {
    button1->Bind(wxEVT_BUTTON, [this](wxCommandEvent& event) {
      staticText1->SetLabel(wxString::Format("button1 clicked %d times", ++button1Clicked));
    });

    button2->Bind(wxEVT_BUTTON, [this](wxCommandEvent& event) {
      staticText2->SetLabel(wxString::Format("button2 clicked %d times", ++button2Clicked));
    });
  }
  
private:
  wxPanel* panel = new wxPanel(this);
  wxButton* button1 = new wxButton(panel, wxID_ANY, "button1", wxPoint(50, 50), wxDefaultSize, wxBU_TOP | wxBU_RIGHT);
  wxButton* button2 = new wxButton(panel, wxID_ANY, "button2", wxPoint(50, 100), wxSize(200, 75));
  wxStaticText* staticText1 = new wxStaticText(panel, wxID_ANY, "button1 clicked 0 times", wxPoint(50, 200), wxSize(200, 20));
  wxStaticText* staticText2 = new wxStaticText(panel, wxID_ANY, "button2 clicked 0 times", wxPoint(50, 230), wxSize(200, 20));
  int button1Clicked = 0;
  int button2Clicked = 0;
};

class Application : public wxApp {
  bool OnInit() override {(new Frame())->Show(); return true;}
};

wxIMPLEMENT_APP(Application);
