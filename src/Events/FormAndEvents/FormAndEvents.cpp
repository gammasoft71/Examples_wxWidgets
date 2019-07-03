#include <iostream>
#include <wx/wx.h>

class Form : public wxFrame {
public:
  Form() : wxFrame(nullptr, wxID_ANY, "Click anywhere on the form", wxDefaultPosition, wxSize(300, 300)) {
  }
  
  bool ProcessEvent (wxEvent &event) override {
    wxWindow* window = ((wxWindow*)event.GetEventObject());
    if (event.GetEventType() == wxEVT_ACTIVATE_APP) std::cout << "WM_ACTIVATEAPP" << std::endl;
    if (event.GetEventType() == wxEVT_CLOSE_WINDOW) std::cout << "WM_CLOSE" << std::endl;
    if (event.GetEventType() == wxEVT_CREATE) std::cout << "WM_CREATE" << std::endl;
    if (event.GetEventType() == wxEVT_DESTROY) std::cout << "WM_DESTROY" << std::endl;
    //if (event.GetEventType() == wxEVT_ENABLE) std::cout << "WM_ENABLE" << std::endl;
    if (event.GetEventType() == wxEVT_COMMAND_ENTER) std::cout << "WM_COMMAND" << std::endl;
    //if (event.GetEventType() == wxEVT_ENTER_SIZEMOVE) std::cout << "WM_ENTERSIZEMOVE" << std::endl;
    //if (event.GetEventType() == wxEVT_EXIT_SIZEMOVE) std::cout << "WM_EXITSIZEMOVE" << std::endl;
    if (event.GetEventType() == wxEVT_MOVE) std::cout << "WM_MOVE {x=" << window->GetPosition().x << ", y=" << window->GetPosition().y << "}" << std::endl;
    if (event.GetEventType() == wxEVT_NULL) std::cout << "WM_MNULL" << std::endl;
    //if (event.GetEventType() == wxEVT_QUIT) std::cout << "WM_QUIT" << std::endl;
    if (event.GetEventType() == wxEVT_TEXT) std::cout << "WM_SETTEXT" << std::endl;
    if (event.GetEventType() == wxEVT_SHOW) std::cout << "WM_SHOWWINDOW show = " << window->IsShown() << std::endl;
    if (event.GetEventType() == wxEVT_SIZE) std::cout << "WM_SIZE {width=" << window->GetSize().GetWidth() << ", height=" << window->GetSize().GetHeight() << "}" << std::endl;
    return this->wxFrame::ProcessEvent(event);
  }
  
private:
  wxPanel* panel = new wxPanel(this);
};

class Application : public wxApp {
  bool OnInit() override {return (new Form())->Show();}
};

wxIMPLEMENT_APP(Application);
