#include <functional>
#include <wx/aboutdlg.h>
#include <wx/app.h>
#include <wx/button.h>
#include <wx/frame.h>
#include <wx/menu.h>
#include <wx/panel.h>
#include <wx/settings.h>
#include <wx/dcscreen.h>

class Form1 : public wxFrame {
public:
  Form1() : wxFrame(nullptr, wxID_ANY, "Test gui") {
    this->SetBackgroundColour(this->panel1->GetBackgroundColour());
    this->SetForegroundColour(this->panel1->GetForegroundColour());
    this->panel1->Hide();
  }
private:
  wxPanel* panel1 = new wxPanel(this);
};

class Application : public wxApp {
  bool OnInit() override {return (new Form1())->Show();}
};

wxIMPLEMENT_APP(Application);
