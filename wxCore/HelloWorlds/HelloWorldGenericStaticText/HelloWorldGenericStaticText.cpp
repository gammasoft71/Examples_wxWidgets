#include <wx/wx.h>
#include <wx/generic/stattextg.h>

namespace HelloWorldGenericStaticTextExample {
  class Frame : public wxFrame {
  public:
    Frame() : wxFrame(nullptr, wxID_ANY, "Hello world (Generic static text)") {
      staticText1->SetFont({32, wxFONTFAMILY_DEFAULT, wxFONTSTYLE_ITALIC, wxFONTWEIGHT_BOLD});
      staticText1->SetForegroundColour(wxTheColourDatabase->Find("Forest Green"));
      Bind(wxEVT_SIZING, [&](wxSizeEvent& e) {
        staticText1->Refresh();
      });
    }
    
  private:
    wxGenericStaticText* staticText1 = new wxGenericStaticText(this, wxID_ANY, "Hello, World!", wxDefaultPosition, wxDefaultSize, wxALIGN_CENTER);
  };

  class Application : public wxApp {
    bool OnInit() override {
      (new Frame)->Show();
      return true;
    }
  };
}

wxIMPLEMENT_APP(HelloWorldGenericStaticTextExample::Application);
