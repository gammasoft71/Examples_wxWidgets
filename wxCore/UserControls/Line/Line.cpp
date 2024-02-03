#include <wx/wx.h>
#include <wx/settings.h>

namespace LineExample {
  class wxColouredLine : public wxPanel {
  public:
    wxColouredLine(wxWindow* parent, const wxColour& colour, const wxPoint& position = wxDefaultPosition, const wxSize& size = wxDefaultSize) : wxPanel(parent, wxID_ANY, position, size) {
      SetColour(colour);
    }
    
    void SetColour(const wxColour& colour) {SetBackgroundColour(colour);}
    wxColour GetColour() const {return GetBackgroundColour();}
  };
  
  class Window : public wxFrame {
  public:
    Window() : wxFrame(nullptr, wxID_ANY, "Lines example") {
      SetClientSize(300, 300);
    }
    
  private:
    wxPanel* panel = new wxPanel {this};
    wxColouredLine* lineSeparator = new wxColouredLine(panel, wxSystemSettings::GetColour(wxSYS_COLOUR_WINDOW), {10, 10}, {280, 2});
    wxColouredLine* lineRed = new wxColouredLine(panel, {255, 0, 0}, {10, 20}, {2, 250});
    wxColouredLine* lineGreen = new wxColouredLine(panel, {0, 143, 0}, {149, 20}, {2, 250});
    wxColouredLine* lineBlue = new wxColouredLine(panel, {0, 0, 255}, {288, 20}, {2, 250});
    wxColouredLine* lineSeparator2 = new wxColouredLine(panel, wxSystemSettings::GetColour(wxSYS_COLOUR_BTNTEXT), {10, 278}, {280, 2});
  };
  
  class Application : public wxApp {
    bool OnInit() override {return (new Window())->Show();}
  };
}

wxIMPLEMENT_APP(LineExample::Application);
