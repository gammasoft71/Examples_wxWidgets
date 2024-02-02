#include <wx/app.h>
#include <wx/bmpbuttn.h>
#include <wx/button.h>
#include <wx/frame.h>
#include <wx/panel.h>
#include "gammasoft_16x16.xpm"
#include "gammasoft_32x32.xpm"
#include "gammasoft_64x64.xpm"

namespace BitmapButtonWithLabelExample {
  class Frame : public wxFrame {
  public:
    Frame() : wxFrame(nullptr, wxID_ANY, "BitmapButton with label example") {
      button1->SetSize(100, 25);
      
      button2->SetBitmapLabel(wxBitmap {gammasoft_16x16_xpm});
      button2->SetBitmapPosition(wxLEFT);
      button2->SetSize(120, 25);
      
      button3->SetBitmapLabel(wxBitmap {gammasoft_32x32_xpm});
      button3->SetBitmapPosition(wxLEFT);
      button3->SetSize(140, 40);

      button4->SetBitmapLabel(wxBitmap {gammasoft_64x64_xpm});
      button4->SetSize(70, 70);
    }
    
  private:
    wxPanel* panel = new wxPanel {this};
    wxButton* button1 = new wxButton(panel, wxID_ANY, "Gammasoft", {50, 20});
    wxButton* button2 = new wxButton(panel, wxID_ANY, "Gammasoft", {50, 50});
    wxButton* button3 = new wxButton(panel, wxID_ANY, "Gammasoft", {50, 80});
    wxButton* button4 = new wxButton(panel, wxID_ANY, wxEmptyString, {50, 125});
  };

  class Application : public wxApp {
    bool OnInit() override {
      (new Frame)->Show();
      return true;
    }
  };
}

wxIMPLEMENT_APP(BitmapButtonWithLabelExample::Application);
