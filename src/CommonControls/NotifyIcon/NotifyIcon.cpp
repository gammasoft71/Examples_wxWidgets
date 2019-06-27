#include <wx/wx.h>
#include <wx/taskbar.h>

#include "Gammasoft.xpm"

class wxNotifyIcon : public wxTaskBarIcon {
public:
  wxNotifyIcon(wxFrame* frame) : frame(frame) {}
  
  wxMenu* CreatePopupMenu() override {
    if (this->frame) {
      if (this->frame->IsShown())
        this->frame->Hide();
      else
        this->frame->Show();
    }
    return nullptr;
  }

  wxFrame* frame = nullptr;
};

class Form : public wxFrame {
public:
  Form() : wxFrame(nullptr, wxID_ANY, "NotifyIcon example", wxDefaultPosition, wxSize(300, 300)) {
    this->notifyIcon1.SetIcon(wxIcon(GammasoftIcon));
  }
  
private:
  wxPanel* panel = new wxPanel(this);
  wxStaticText* label1 = new wxStaticText(this->panel, wxID_ANY, "Click on Gammasoft tray icon\nto show or hide this form.", wxPoint(10, 10));
  wxNotifyIcon notifyIcon1 {this};
};

class Application : public wxApp {
  bool OnInit() override {return (new Form())->Show();}
};

wxIMPLEMENT_APP(Application);
