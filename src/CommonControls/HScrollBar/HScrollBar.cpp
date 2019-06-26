#include <wx/wx.h>

class Form : public wxFrame {
public:
  Form() : wxFrame(nullptr, wxID_ANY, "HScrollBar example", wxDefaultPosition, wxSize(300, 300)) {
    this->scrollBar2->SetScrollbar(100, 1, 200, 1);
    this->scrollBar2->SetSize(220, this->scrollBar2->GetSize().GetHeight());
  }
  
private:
  wxPanel* panel = new wxPanel(this);
  wxScrollBar* scrollBar1 = new wxScrollBar(this->panel, wxID_ANY, wxPoint(10, 30), wxDefaultSize, wxSB_HORIZONTAL);
  wxScrollBar* scrollBar2 = new wxScrollBar(this->panel, wxID_ANY, wxPoint(10, 70), wxDefaultSize, wxSB_HORIZONTAL);
};

class Application : public wxApp {
  bool OnInit() override {return (new Form())->Show();}
};

wxIMPLEMENT_APP(Application);
