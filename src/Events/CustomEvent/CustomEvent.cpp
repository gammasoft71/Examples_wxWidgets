#include <any>
#include <wx/wx.h>

class CustomEvent;
wxDECLARE_EVENT(WX_EVT_CUSTOM_EVENT, CustomEvent);

class CustomEvent : public wxCommandEvent {
public:
  CustomEvent(wxEventType commandType = WX_EVT_CUSTOM_EVENT, int id = 0) : wxCommandEvent(commandType, id) { }
  
  // You *must* copy here the data to be transported
  CustomEvent(const CustomEvent& event) : wxCommandEvent(event) {}
  
  std::any tag() const {return tag_;}
  void tag(const std::any& value) {tag_ = value;}
  
private:
  std::any tag_;
};

wxDEFINE_EVENT(WX_EVT_CUSTOM_EVENT, CustomEvent);

class Frame : public wxFrame {
public:
  Frame() : wxFrame(nullptr, wxID_ANY, "Custom event example", wxDefaultPosition, wxSize(300, 300)) {
    button->Bind(wxEVT_BUTTON, [&](wxCommandEvent& event) {
      wxPostEvent(this, CustomEvent());
    });
    
    Bind(WX_EVT_CUSTOM_EVENT, [&](CustomEvent& event) {
      wxMessageBox("Receive CustomEvent event", "CustomEVentk", wxOK);
    });
  }
  
private:
  wxPanel* panel = new wxPanel(this);
  wxButton* button = new wxButton(panel, wxID_ANY, "Send Event", {10, 10});
};

class Application : public wxApp {
  bool OnInit() override {(new Frame())->Show(); return true;}
};

wxIMPLEMENT_APP(Application);
