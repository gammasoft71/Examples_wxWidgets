#include <wx/wx.h>
#include <wx/settings.h>

namespace Examples {
  class wxColouredLine : public wxPanel {
  public:
    wxColouredLine(wxWindow* parent, const wxColour& colour, const wxPoint& position = wxDefaultPosition, const wxSize& size = wxDefaultSize) : wxPanel(parent, wxID_ANY, position, size) {SetColour(colour);}
    
    void SetColour(const wxColour& colour) {SetBackgroundColour(colour);}
    wxColour GetColour() const {return GetBackgroundColour();}
  };
  
  class Form : public wxFrame {
  public:
    Form() : wxFrame(nullptr, wxID_ANY, "Lines example", wxDefaultPosition, {300, 300}) {
      SetClientSize({300, 300});
    }
    
  private:
    wxPanel* panel = new wxPanel(this);
    wxColouredLine* lineSeparator = new wxColouredLine(panel, wxSystemSettings::GetColour(wxSYS_COLOUR_WINDOW), {10, 10}, wxSize(280, 2));
    wxColouredLine* lineRed = new wxColouredLine(panel, wxColour(255, 0, 0), wxPoint(10, 20), wxSize(2, 250));
    wxColouredLine* lineGreen = new wxColouredLine(panel, wxColour(0, 143, 0), wxPoint(149, 20), wxSize(2, 250));
    wxColouredLine* lineBlue = new wxColouredLine(panel, wxColour(0, 0, 255), wxPoint(288, 20), wxSize(2, 250));
    wxColouredLine* lineSeparator2 = new wxColouredLine(panel, wxSystemSettings::GetColour(wxSYS_COLOUR_BTNTEXT), wxPoint(10, 278), wxSize(280, 2));
  };
  
  class Application : public wxApp {
    bool OnInit() override {(new Form())->Show(); return true;}
  };
}

wxIMPLEMENT_APP(Examples::Application);
