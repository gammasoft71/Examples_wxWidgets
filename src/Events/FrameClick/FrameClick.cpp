#include <wx/wx.h>

namespace FrameClickExample {
  class Frame : public wxFrame {
  public:
    Frame() : wxFrame(nullptr, wxID_ANY, "Click anywhere on the frame") {
      panel->Bind(wxEVT_LEFT_UP, [&](wxMouseEvent& event) {
        wxMessageBox(wxString::Format("The frame is clicked at {x=%d, y=%d}", event.GetPosition().x, event.GetPosition().y), "FrameClick", wxOK) ;
      });
    }
    
  private:
    wxPanel* panel = new wxPanel(this);
  };

  class Application : public wxApp {
    bool OnInit() override {
      (new Frame())->Show();
      return true;
    }
  };
}

wxIMPLEMENT_APP(FrameClickExample::Application);
