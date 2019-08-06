#include <wx/wx.h>
#include <wx/msgout.h>

class Form : public wxFrame {
public:
  Form() : wxFrame(nullptr, wxID_ANY, "Click anywhere on the form", wxDefaultPosition, wxSize(300, 300)) {}
  
  bool ProcessEvent (wxEvent &event) override {
    wxWindow* window = ((wxWindow*)event.GetEventObject());
    if (event.GetEventType() == wxEVT_ACTIVATE_APP) wxMessageOutputDebug.Prinf("WM_ACTIVATEAPP");
    if (event.GetEventType() == wxEVT_CLOSE_WINDOW) wxMessageOutputDebug.Prinf("WM_CLOSE");
    if (event.GetEventType() == wxEVT_CREATE) wxMessageOutputDebug.Prinf("WM_CREATE");
    if (event.GetEventType() == wxEVT_DESTROY) wxMessageOutputDebug.Prinf("WM_DESTROY");
    //if (event.GetEventType() == wxEVT_ENABLE) wxMessageOutputDebug.Prinf("WM_ENABLE");
    if (event.GetEventType() == wxEVT_COMMAND_ENTER) wxMessageOutputDebug.Prinf("WM_COMMAND");
    //if (event.GetEventType() == wxEVT_ENTER_SIZEMOVE) wxMessageOutputDebug.Prinf("WM_ENTERSIZEMOVE");
    //if (event.GetEventType() == wxEVT_EXIT_SIZEMOVE) wxMessageOutputDebug.Prinf("WM_EXITSIZEMOVE");
    if (event.GetEventType() == wxEVT_MOVE) wxMessageOutputDebug.Prinf("WM_MOVE {x = %d, y= %d}", window->GetPosition().x, window->GetPosition().y);
    if (event.GetEventType() == wxEVT_NULL) wxMessageOutputDebug.Prinf("WM_MNULL");
    //if (event.GetEventType() == wxEVT_QUIT) wxMessageOutputDebug.Prinf("WM_QUIT");
    if (event.GetEventType() == wxEVT_TEXT) wxMessageOutputDebug.Prinf("WM_SETTEXT");
    if (event.GetEventType() == wxEVT_SHOW) wxMessageOutputDebug.Prinf("WM_SHOWWINDOW show = %d", window->IsShown());
    if (event.GetEventType() == wxEVT_SIZE) wxMessageOutputDebug.Prinf("WM_SIZE {width = %d, height= %d}", window->GetSize().GetWidth(), window->GetSize().GetHeight());

    return this->wxFrame::ProcessEvent(event);
  }
  
private:
  wxPanel* panel = new wxPanel(this);
};

class Application : public wxApp {
  bool OnInit() override {return (new Form())->Show();}
};

wxIMPLEMENT_APP(Application);
