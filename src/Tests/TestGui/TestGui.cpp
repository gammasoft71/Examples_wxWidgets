#include <functional>
#include <wx/wx.h>
#include <wx/app.h>
#include <wx/button.h>
#include <wx/frame.h>
#include <wx/panel.h>
#include <wx/textctrl.h>

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

struct Message {
};

template <typename Control>
class ControlEvent : public Control {
public:
  ControlEvent(wxWindow *parent, wxWindowID id, const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxDefaultSize, long style = 0) : Control(parent, id, pos, size, style) {}
  ControlEvent(wxWindow *parent, wxWindowID id, const wxString& label = wxEmptyString, const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxDefaultSize, long style = 0) : Control(parent, id, label, pos, size, style) {}
  
  bool ProcessEvent (wxEvent &event) override {
    wxWindow* window = ((wxWindow*)event.GetEventObject());

    //Message message;

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

    //if (this->wndProc != nullptr)
    //  this->wndProc(message);
    
    return this->Control::ProcessEvent(event);
    
  }
  
protected:
  std::function<void (Message&)> wndProc;
};

class Form1 : public wxFrame {
public:
  Form1() : wxFrame(nullptr, wxID_ANY, "Test gui", wxDefaultPosition, wxSize(300, 300)) {
    this->panel->Hide();
  }

  /*
  void RegisterWndProc(std::function<void (Message&)> wndProc) {
    this->wndProc = wndProc;
  }
  
  void UnregisterWndProc(std::function<void (Message&)> wndProc) {
    this->wndProc = nullptr;
  }*/
  
private:
  wxPanel* panel = new wxPanel(this);
  wxStaticText* label1 = new wxStaticText(this, wxID_ANY, "Label1", wxPoint(10, 150));
  wxButton* button1 = new wxButton(this, wxID_ANY, "Button", wxPoint(10, 200));
};

class Application : public wxApp {
  bool OnInit() override {return (new Form1())->Show();}
};

wxIMPLEMENT_APP(Application);
