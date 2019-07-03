#include <wx/wx.h>

#if defined(WIN32)
#include <Windows.h>
void WriteLineDebugString(const wxString& str) {
  OutputDebugString(str.wc_str());
  OutputDebugString(L"\n");
}
#else
#include <iostream>
void WriteLineDebugString(const wxString& str) {
  std::wcout << str.wc_str() << std::endl;
}
#endif

class Form : public wxFrame {
public:
  Form() : wxFrame(nullptr, wxID_ANY, "Click anywhere on the form", wxDefaultPosition, wxSize(300, 300)) {
  }
  
  bool ProcessEvent (wxEvent &event) override {
    wxWindow* window = ((wxWindow*)event.GetEventObject());
    if (event.GetEventType() == wxEVT_ACTIVATE_APP) WriteLineDebugString("WM_ACTIVATEAPP");
    if (event.GetEventType() == wxEVT_CLOSE_WINDOW) WriteLineDebugString("WM_CLOSE");
    if (event.GetEventType() == wxEVT_CREATE) WriteLineDebugString("WM_CREATE");
    if (event.GetEventType() == wxEVT_DESTROY) WriteLineDebugString("WM_DESTROY");
    //if (event.GetEventType() == wxEVT_ENABLE) WriteLineDebugString("WM_ENABLE");
    if (event.GetEventType() == wxEVT_COMMAND_ENTER) WriteLineDebugString("WM_COMMAND");
    //if (event.GetEventType() == wxEVT_ENTER_SIZEMOVE) WriteLineDebugString("WM_ENTERSIZEMOVE");
    //if (event.GetEventType() == wxEVT_EXIT_SIZEMOVE) WriteLineDebugString("WM_EXITSIZEMOVE");
    if (event.GetEventType() == wxEVT_MOVE) WriteLineDebugString(wxString::Format("WM_MOVE {x = %d, y= %d}", window->GetPosition().x, window->GetPosition().y));
    if (event.GetEventType() == wxEVT_NULL) WriteLineDebugString("WM_MNULL");
    //if (event.GetEventType() == wxEVT_QUIT) WriteLineDebugString("WM_QUIT");
    if (event.GetEventType() == wxEVT_TEXT) WriteLineDebugString("WM_SETTEXT");
    if (event.GetEventType() == wxEVT_SHOW) WriteLineDebugString(wxString::Format("WM_SHOWWINDOW show = %d", window->IsShown()));
    if (event.GetEventType() == wxEVT_SIZE) WriteLineDebugString(wxString::Format("WM_SIZE {width = %d, height= %d}", window->GetSize().GetWidth(), window->GetSize().GetHeight()));

    return this->wxFrame::ProcessEvent(event);
  }
  
private:
  wxPanel* panel = new wxPanel(this);
};

class Application : public wxApp {
  bool OnInit() override {return (new Form())->Show();}
};

wxIMPLEMENT_APP(Application);
