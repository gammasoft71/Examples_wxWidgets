#include <wx/wx.h>
#include <wx/msgout.h>

namespace FrameAndEventsExample {
  class Frame : public wxFrame {
  public:
    Frame() : wxFrame(nullptr, wxID_ANY, "Frame and events") {}
    
    bool ProcessEvent (wxEvent &event) override {
      wxWindow* window = ((wxWindow*)event.GetEventObject());
      if (event.GetEventType() == wxEVT_ACTIVATE_APP) wxMessageOutputDebug().Output("wxEVT_ACTIVATE_APP");
      if (event.GetEventType() == wxEVT_CLOSE_WINDOW) wxMessageOutputDebug().Output("wxEVT_CLOSE_WINDOW");
      if (event.GetEventType() == wxEVT_CREATE) wxMessageOutputDebug().Output("wxEVT_CREATE");
      if (event.GetEventType() == wxEVT_DESTROY) wxMessageOutputDebug().Output("wxEVT_DESTROY");
      if (event.GetEventType() == wxEVT_COMMAND_ENTER) wxMessageOutputDebug().Output("wxEVT_COMMAND_ENTER");
      if (event.GetEventType() == wxEVT_MOVE) wxMessageOutputDebug().Printf("wxEVT_MOVE {x = %d, y= %d}", window->GetPosition().x, window->GetPosition().y);
      if (event.GetEventType() == wxEVT_NULL) wxMessageOutputDebug().Output("wxEVT_NULL");
      if (event.GetEventType() == wxEVT_TEXT) wxMessageOutputDebug().Output("wxEVT_TEXT");
      if (event.GetEventType() == wxEVT_SHOW) wxMessageOutputDebug().Printf("wxEVT_SHOW show = %d", window->IsShown());
      if (event.GetEventType() == wxEVT_SIZE) wxMessageOutputDebug().Printf("wxEVT_SIZE {width = %d, height= %d}", window->GetSize().GetWidth(), window->GetSize().GetHeight());

      return wxFrame::ProcessEvent(event);
    }
    
  private:
    wxPanel* panel = new wxPanel {this};
  };

  class Application : public wxApp {
    bool OnInit() override {return (new Frame)->Show();}
  };
}

wxIMPLEMENT_APP(FrameAndEventsExample::Application);
