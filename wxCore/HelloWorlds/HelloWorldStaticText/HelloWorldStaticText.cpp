#include <wx/wx.h>

namespace HelloWorldStaticTextExample {
  class Frame : public wxFrame {
  public:
    Frame() : wxFrame {nullptr, wxID_ANY, "Hello world (Static text)"} {
      staticText1->SetFont({32, wxFONTFAMILY_DEFAULT, wxFONTSTYLE_ITALIC, wxFONTWEIGHT_BOLD});
      staticText1->SetForegroundColour(wxTheColourDatabase->Find("Forest Green"));
    }
    
  private:
    wxStaticText* staticText1 = new wxStaticText {this, wxID_ANY, "Hello, World!", wxDefaultPosition, wxDefaultSize, wxALIGN_CENTER};
  };

  class Application : public wxApp {
    bool OnInit() override {return (new Frame)->Show();}
  };
}

wxIMPLEMENT_APP(HelloWorldStaticTextExample::Application);
