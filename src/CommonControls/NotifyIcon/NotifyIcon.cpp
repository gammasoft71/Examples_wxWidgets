#include <wx/wx.h>
#include <wx/taskbar.h>

#include "Gammasoft.xpm"

class Form : public wxFrame {
public:
  Form() : wxFrame(nullptr, wxID_ANY, "NotifyIcon example", wxDefaultPosition, wxSize(300, 300)) {
    this->notifyIcon1.SetIcon(wxIcon(GammasoftIcon));
    this->notifyIcon1.Bind(wxEVT_TASKBAR_LEFT_DCLICK, [&](wxTaskBarIconEvent& event) {
      if (this->IsShown())
        this->Hide();
      else
        this->Show();
    });
  }
  
private:
  wxPanel* panel = new wxPanel(this);
  wxStaticText* label1 = new wxStaticText(this->panel, wxID_ANY, "Double click on Gammasoft tray icon\nto show or hide this form.", wxPoint(10, 10));
  wxTaskBarIcon notifyIcon1;
};

class Application : public wxApp {
  bool OnInit() override {return (new Form())->Show();}
};

wxIMPLEMENT_APP(Application);
