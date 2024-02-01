#include <wx/app.h>
#include <wx/frame.h>
#include <wx/panel.h>
#include <wx/statline.h>

namespace StaticLineExample {
  class Frame : public wxFrame {
  public:
    Frame() : wxFrame(nullptr, wxID_ANY, "StaticLine example") {
      SetClientSize({300, 300});
    }
    
  private:
    wxPanel* panel = new wxPanel(this);
    wxStaticLine* staticLine1 = new wxStaticLine(panel, wxID_ANY, {20, 15}, {255, wxDefaultCoord});
    wxStaticLine* staticLine2 = new wxStaticLine(panel, wxID_ANY, {285, 20}, {wxDefaultCoord, 255}, wxLI_VERTICAL);
    wxStaticLine* staticLine3 = new wxStaticLine(panel, wxID_ANY, {20, 285}, {255, wxDefaultCoord});
    wxStaticLine* staticLine4 = new wxStaticLine(panel, wxID_ANY, {15, 20}, {wxDefaultCoord, 255}, wxLI_VERTICAL);
  };

  class Application : public wxApp {
    bool OnInit() override {
      (new Frame)->Show();
      return true;
    }
  };
}

wxIMPLEMENT_APP(StaticLineExample::Application);
