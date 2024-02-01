#include <wx/app.h>
#include <wx/frame.h>
#include <wx/panel.h>
#include <wx/stattext.h>
#include <wx/generic/stattextg.h>

namespace BorderStyleExample {
  class Frame : public wxFrame {
  public:
    Frame() : wxFrame(nullptr, wxID_ANY, "Border style example") {
      SetClientSize(700, 400);
    }
    
  private:
    wxPanel* panel = new wxPanel(this);
    wxGenericStaticText* staticTextWithNoneBorder = new wxGenericStaticText(panel, wxID_ANY, "None", {20, 20}, {150, 50}, wxALIGN_CENTER|wxBORDER_NONE);
    wxGenericStaticText* staticTextWithStaticBorder = new wxGenericStaticText(panel, wxID_ANY, "Static", {190, 20}, {150, 50}, wxALIGN_CENTER|wxBORDER_STATIC);
    wxGenericStaticText* staticTextWithSimpleBorder = new wxGenericStaticText(panel, wxID_ANY, "Simple", {360, 20}, {150, 50}, wxALIGN_CENTER|wxBORDER_SIMPLE);
    wxGenericStaticText* staticTextWithRaisedBorder = new wxGenericStaticText(panel, wxID_ANY, "Raised", {530, 20}, {150, 50}, wxALIGN_CENTER|wxBORDER_RAISED);
    wxGenericStaticText* staticTextWithSunkenBorder = new wxGenericStaticText(panel, wxID_ANY, "Sunken", {20, 90}, {150, 50}, wxALIGN_CENTER|wxBORDER_SUNKEN);
    wxGenericStaticText* staticTextWithThemeBorder = new wxGenericStaticText(panel, wxID_ANY, "Theme", {190, 90}, {150, 50}, wxALIGN_CENTER|wxBORDER_THEME);
  };

  class Application : public wxApp {
    bool OnInit() override {
      (new Frame)->Show();
      return true;
    }
  };
}

wxIMPLEMENT_APP(BorderStyleExample::Application);
