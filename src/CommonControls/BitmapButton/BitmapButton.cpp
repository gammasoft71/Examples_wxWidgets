#include <wx/app.h>
#include <wx/bmpbuttn.h>
#include <wx/button.h>
#include <wx/frame.h>
#include <wx/panel.h>

class Frame : public wxFrame {
  #include "Gammasoft-32x32.xpm"
public:
  Frame() : wxFrame(nullptr, wxID_ANY, "BitmapButton example", wxDefaultPosition, wxSize(300, 300)) {
    button1->SetBitmapLabel(gammasoft_32x32);
    button1->SetSize(40, 40);
    
    button2->SetSize(40, 40);
    
    button3->SetBitmap(gammasoft_32x32);
    button3->SetSize(120, 40);
  }
  
private:
  wxPanel* panel = new wxPanel(this);
  wxButton* button1 = new wxButton(panel, wxID_ANY, wxEmptyString, wxPoint(50, 50));
  wxBitmapButton* button2 = new wxBitmapButton(panel, wxID_ANY, gammasoft_32x32, wxPoint(100, 50));
  wxButton* button3 = new wxButton(panel, wxID_ANY, "Gammasoft", wxPoint(150, 50));
};

class Application : public wxApp {
  bool OnInit() override {(new Frame())->Show(); return true;}
};

wxIMPLEMENT_APP(Application);
