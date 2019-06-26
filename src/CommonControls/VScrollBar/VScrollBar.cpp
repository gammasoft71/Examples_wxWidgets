#include <wx/wx.h>

class Form : public wxFrame {
public:
  Form() : wxFrame(nullptr, wxID_ANY, "VScrollBar example", wxDefaultPosition, wxSize(300, 300)) {
    this->scrollBar2->SetScrollbar(100, 1, 200, 1);
    this->scrollBar2->SetSize(this->scrollBar2->GetSize().GetWidth(), 220);
  }
  
private:
  wxPanel* panel = new wxPanel(this);
  wxScrollBar* scrollBar1 = new wxScrollBar(this->panel, wxID_ANY, wxPoint(30, 10), wxDefaultSize, wxSB_VERTICAL);
  wxScrollBar* scrollBar2 = new wxScrollBar(this->panel, wxID_ANY, wxPoint(70, 10), wxDefaultSize, wxSB_VERTICAL);
};

class Application : public wxApp {
  bool OnInit() override {return (new Form())->Show();}
};

wxIMPLEMENT_APP(Application);
