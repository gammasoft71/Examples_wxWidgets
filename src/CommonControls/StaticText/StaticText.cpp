#include <wx/app.h>
#include <wx/frame.h>
#include <wx/panel.h>
#include <wx/stattext.h>

class Frame : public wxFrame {
public:
  Frame() : wxFrame(nullptr, wxID_ANY, "StaticText example", wxDefaultPosition, {300, 300}) {}
  
private:
  wxPanel* panel = new wxPanel(this);
  wxStaticText* staticText1 = new wxStaticText(panel, wxID_ANY, "staticText1", {10, 10});
};

class Application : public wxApp {
  bool OnInit() override {(new Frame())->Show(); return true;}
};

wxIMPLEMENT_APP(Application);
