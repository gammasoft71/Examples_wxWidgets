#include <wx/wx.h>
#include <wx/msgout.h>

class Form : public wxFrame {
public:
  Form() : wxFrame(nullptr, wxID_ANY, "Form and events", wxDefaultPosition, wxSize(300, 300)) {}
  
  bool ProcessEvent (wxEvent &event) override {
    wxWindow* window = ((wxWindow*)event.GetEventObject());
    if (event.GetEventType() == wxEVT_ACTIVATE_APP) wxMessageOutputDebug.Output("WM_ACTIVATEAPP");
    if (event.GetEventType() == wxEVT_CLOSE_WINDOW) wxMessageOutputDebug.Output("WM_CLOSE");
    if (event.GetEventType() == wxEVT_CREATE) wxMessageOutputDebug.Output("WM_CREATE");
    if (event.GetEventType() == wxEVT_DESTROY) wxMessageOutputDebug.Output("WM_DESTROY");
    //if (event.GetEventType() == wxEVT_ENABLE) wxMessageOutputDebug.Output("WM_ENABLE");
    if (event.GetEventType() == wxEVT_COMMAND_ENTER) wxMessageOutputDebug.Output("WM_COMMAND");
    //if (event.GetEventType() == wxEVT_ENTER_SIZEMOVE) wxMessageOutputDebug.Output("WM_ENTERSIZEMOVE");
    //if (event.GetEventType() == wxEVT_EXIT_SIZEMOVE) wxMessageOutputDebug.Output("WM_EXITSIZEMOVE");
    if (event.GetEventType() == wxEVT_MOVE) wxMessageOutputDebug.Prinf("WM_MOVE {x = %d, y= %d}", window->GetPosition().x, window->GetPosition().y);
    if (event.GetEventType() == wxEVT_NULL) wxMessageOutputDebug.Output("WM_MNULL");
    //if (event.GetEventType() == wxEVT_QUIT) wxMessageOutputDebug.Output("WM_QUIT");
    if (event.GetEventType() == wxEVT_TEXT) wxMessageOutputDebug.Output("WM_SETTEXT");
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
