#include <wx/app.h>
#include <wx/commandlinkbutton.h>
#include <wx/frame.h>
#include <wx/panel.h>
#include <wx/stattext.h>

namespace CommandLinkButtonExample {
  class Frame : public wxFrame {
  public:
    Frame() : wxFrame(nullptr, wxID_ANY, "CommandLinkButton example") {
      commandLinkButton1->Bind(wxEVT_BUTTON, [&](wxCommandEvent& event) {
        staticText1->SetLabel(wxString::Format("commandLinkButton1 clicked %d times", ++commandLinkButton1Clicked));
      });
    }
    
  private:
    wxPanel* panel = new wxPanel(this);
    wxCommandLinkButton* commandLinkButton1 = new wxCommandLinkButton(panel, wxID_ANY, "Command link", "width supplementary text", {30, 30}, {240, 60});
    wxStaticText* staticText1 = new wxStaticText(panel, wxID_ANY, "commandLinkButton1 clicked 0 times", {30, 100}, {200, 50});
    int commandLinkButton1Clicked = 0;
  };

  class Application : public wxApp {
    bool OnInit() override {
      (new Frame())->Show();
      return true;
    }
  };
}

wxIMPLEMENT_APP(CommandLinkButtonExample::Application);
