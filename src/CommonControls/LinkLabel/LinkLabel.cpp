#include <wx/wx.h>
#include <wx/hyperlink.h>

class Form : public wxFrame {
public:
  Form() : wxFrame(nullptr, wxID_ANY, "LinkLabel example", wxDefaultPosition, wxSize(300, 300)) {}
  
private:
  wxPanel* panel = new wxPanel(this);
  wxHyperlinkCtrl* label1 = new wxHyperlinkCtrl(panel, wxID_ANY, "Gammasoft", "https://gammasoft71.wixsite.com/gammasoft", wxPoint(10, 10));
  wxStaticText* label2 = new wxStaticText(panel, wxID_ANY, " present ", wxPoint(label1->GetPosition().x + label1->GetSize().GetWidth(), 10));
  wxHyperlinkCtrl* label3 = new wxHyperlinkCtrl(panel, wxID_ANY, "wxWidgets", "https://gammasoft71.wixsite.com/gammasoft/wxwidgets", wxPoint(label2->GetPosition().x + label2->GetSize().GetWidth(), 10));
  wxStaticText* label4 = new wxStaticText(panel, wxID_ANY, " examples", wxPoint(label3->GetPosition().x + label3->GetSize().GetWidth(), 10));
};

class Application : public wxApp {
  bool OnInit() override {(new Form())->Show(); return true;}
};

wxIMPLEMENT_APP(Application);
