#include <wx/app.h>
#include <wx/control.h>
#include <wx/frame.h>
#include <wx/panel.h>

namespace ControlExample {
  class Frame : public wxFrame {
  public:
    Frame() : wxFrame(nullptr, wxID_ANY, "Control example") {
      control1->SetBackgroundColour(wxTheColourDatabase->Find("Spring Green"));
      control1->Bind(wxEVT_LEFT_DOWN, [&](wxMouseEvent& event) {
        control1->SetBackgroundColour(control1->GetBackgroundColour() == wxTheColourDatabase->Find("Spring Green") ? wxTheColourDatabase->Find("Orange Red") : wxTheColourDatabase->Find("Spring Green"));
        control1->Refresh();
      });
    }
    
  private:
    wxPanel* panel = new wxPanel(this);
    wxControl* control1 = new wxControl(panel, wxID_ANY, {50, 50}, {100, 50});
  };

  class Application : public wxApp {
    bool OnInit() override {
      (new Frame())->Show();
      return true;
    }
  };
}

wxIMPLEMENT_APP(ControlExample::Application);
