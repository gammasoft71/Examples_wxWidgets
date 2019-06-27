#include <wx/wx.h>

#if defined(__APPLE__)
  constexpr double DeviceUnitScaleCorrection =  4.0 / 3.0;
#else
  constexpr double DeviceUnitScaleCorrection =  1.0;
#endif

class Form : public wxFrame {
public:
  Form() : wxFrame(nullptr, wxID_ANY, "My first application", wxDefaultPosition) {
    this->SetClientSize(wxSize(300, 300));
    this->label1->SetFont(wxFont(32 * DeviceUnitScaleCorrection, wxFONTFAMILY_DEFAULT, wxFONTSTYLE_ITALIC, wxFONTWEIGHT_BOLD, false, "Arial"));
    this->label1->SetForegroundColour(wxTheColourDatabase->Find("FOREST GREEN"));

    this->CenterOnScreen();
  }
  
private:
  wxPanel* panel = new wxPanel(this);
  wxStaticText* label1 = new wxStaticText(this->panel, wxID_ANY, "Hello, World!", wxPoint(5, 100), wxSize(290, 70));
};

class Application : public wxApp {
  bool OnInit() override {return (new Form())->Show();}
};

wxIMPLEMENT_APP(Application);
