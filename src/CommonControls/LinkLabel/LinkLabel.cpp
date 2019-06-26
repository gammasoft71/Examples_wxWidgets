#include <wx/wx.h>
#include <wx/hyperlink.h>

class Form : public wxFrame {
public:
  Form() : wxFrame(nullptr, wxID_ANY, "LinkLabel example", wxDefaultPosition, wxSize(300, 300)) {}
  
private:
  wxPanel* panel = new wxPanel(this);
  wxHyperlinkCtrl* label1 = new wxHyperlinkCtrl(this->panel, wxID_ANY, "Gammasoft", "https://gammasoft71.wixsite.com/gammasoft", wxPoint(10, 10));
  wxStaticText* label2 = new wxStaticText(this->panel, wxID_ANY, " present ", wxPoint(label1->GetPosition().x + this->label1->GetSize().GetWidth(), 10));
  wxHyperlinkCtrl* label3 = new wxHyperlinkCtrl(this->panel, wxID_ANY, "CSharp", "https://gammasoft71.wixsite.com/gammasoft/csharp", wxPoint(label2->GetPosition().x + this->label2->GetSize().GetWidth(), 10));
  wxStaticText* label4 = new wxStaticText(this->panel, wxID_ANY, " examples", wxPoint(label3->GetPosition().x + this->label3->GetSize().GetWidth(), 10));
};

class Application : public wxApp {
  bool OnInit() override {return (new Form())->Show();}
};

wxIMPLEMENT_APP(Application);
