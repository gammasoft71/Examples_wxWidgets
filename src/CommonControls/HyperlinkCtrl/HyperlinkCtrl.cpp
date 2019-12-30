#include <wx/app.h>
#include <wx/frame.h>
#include <wx/hyperlink.h>
#include <wx/panel.h>
#include <wx/stattext.h>

class Frame : public wxFrame {
public:
  Frame() : wxFrame(nullptr, wxID_ANY, "HyperlinkCtrl example", wxDefaultPosition, {300, 300}) {}
  
private:
  wxPanel* panel = new wxPanel(this);
  wxHyperlinkCtrl* staticText1 = new wxHyperlinkCtrl(panel, wxID_ANY, "Gammasoft", "https://gammasoft71.wixsite.com/gammasoft", {10, 10});
  wxStaticText* staticText2 = new wxStaticText(panel, wxID_ANY, " present ", {staticText1->GetPosition().x + staticText1->GetSize().GetWidth(), 10});
  wxHyperlinkCtrl* staticText3 = new wxHyperlinkCtrl(panel, wxID_ANY, "wxWidgets", "https://gammasoft71.wixsite.com/gammasoft/wxwidgets", {staticText2->GetPosition().x + staticText2->GetSize().GetWidth(), 10});
  wxStaticText* staticText4 = new wxStaticText(panel, wxID_ANY, " examples", {staticText3->GetPosition().x + staticText3->GetSize().GetWidth(), 10});
};

class Application : public wxApp {
  bool OnInit() override {(new Frame())->Show(); return true;}
};

wxIMPLEMENT_APP(Application);
