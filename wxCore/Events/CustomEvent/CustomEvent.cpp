#include <wx/app.h>
#include <wx/button.h>
#include <wx/frame.h>
#include <wx/msgdlg.h>
#include <wx/panel.h>
#include <any>

using namespace std;

namespace CustomEventExample {
  class CustomEvent;
  wxDECLARE_EVENT(WX_EVT_CUSTOM_EVENT, CustomEvent);
  
  class CustomEvent : public wxCommandEvent {
  public:
    explicit CustomEvent(const std::any& tag, wxEventType commandType = WX_EVT_CUSTOM_EVENT, int id = 0) : wxCommandEvent {commandType, id}, tag {tag} {}

    std::any Tag() const noexcept {return tag;}
    
  private:
    std::any tag;
  };

  wxDEFINE_EVENT(WX_EVT_CUSTOM_EVENT, CustomEvent);

  class Frame : public wxFrame {
  public:
    Frame() : wxFrame {nullptr, wxID_ANY, "Custom event example"} {
      button->Bind(wxEVT_BUTTON, [&](wxCommandEvent& event) {
        static auto counter = 0;
        wxQueueEvent(this, new CustomEvent {++counter});
      });
      
      Bind(WX_EVT_CUSTOM_EVENT, [&](CustomEvent& event) {
        wxMessageBox(wxString::Format("Receive CustomEvent event (%d)", any_cast<int>(event.Tag())), "CustomEVent", wxOK, this);
      });
    }
    
  private:
    wxPanel* panel = new wxPanel {this};
    wxButton* button = new wxButton {panel, wxID_ANY, "Send Event", {10, 10}};
  };

  class Application : public wxApp {
    bool OnInit() override {return (new Frame)->Show();}
  };
}

wxIMPLEMENT_APP(CustomEventExample::Application);
