#include <wx/app.h>
#include <wx/button.h>
#include <wx/frame.h>
#include <wx/panel.h>
#include <wx/stattext.h>

namespace ButtonExample {
  class Frame : public wxFrame {
  public:
    Frame() : wxFrame(nullptr, wxID_ANY, wxEmptyString) {
      button1->Bind(wxEVT_BUTTON, [&](wxCommandEvent& event) {
        staticText1->SetLabel(wxString::Format("button1 clicked %d times", ++button1Clicked));
      });

      button2->Bind(wxEVT_BUTTON, [&](wxCommandEvent& event) {
        staticText2->SetLabel(wxString::Format("button2 clicked %d times", ++button2Clicked));
      });
    }
    
  private:
    wxPanel* panel = new wxPanel {this};
    wxButton* button1 = new wxButton(panel, wxID_ANY, "button1", {50, 10});
    wxButton* button2 = new wxButton(panel, wxID_ANY, "button2", {50, 60}, {200, 75}, wxBORDER_SIMPLE);
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

wxIMPLEMENT_APP(ButtonExample::Application);
