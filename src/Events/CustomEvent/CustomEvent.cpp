#include <any>
#include <wx/wx.h>

namespace Examples {
  class CustomEvent;
  wxDECLARE_EVENT(WX_EVT_CUSTOM_EVENT, CustomEvent);

  class CustomEvent : public wxCommandEvent {
  public:
    CustomEvent(wxEventType commandType = WX_EVT_CUSTOM_EVENT, int id = 0) : wxCommandEvent(commandType, id) { }
    CustomEvent(const CustomEvent& event) : wxCommandEvent(event), tag_(event.tag_) {}
    
    std::any tag() const {return tag_;}
    void tag(const std::any& value) {tag_ = value;}
    
  private:
    std::any tag_;
  };

  wxDEFINE_EVENT(WX_EVT_CUSTOM_EVENT, CustomEvent);

  class Frame : public wxFrame {
  public:
    Frame() : wxFrame(nullptr, wxID_ANY, "Custom event example") {
      button->Bind(wxEVT_BUTTON, [&](wxCommandEvent& event) {
        static auto counter = 0;
        auto customEvent = new CustomEvent();
        customEvent->tag(++counter);
        wxQueueEvent(this, customEvent);
      });
      
      Bind(WX_EVT_CUSTOM_EVENT, [&](CustomEvent& event) {
        wxMessageBox(wxString::Format("Receive CustomEvent event (%d)", std::any_cast<int>(event.tag())), "CustomEVent", wxOK);
      });
    }
    
  private:
    wxPanel* panel = new wxPanel(this);
    wxButton* button = new wxButton(panel, wxID_ANY, "Send Event", {10, 10});
  };

  class Application : public wxApp {
    bool OnInit() override {
      (new Frame())->Show();
      return true;
    }
  };
}

wxIMPLEMENT_APP(Examples::Application);
