#include <wx/wx.h>

class Frame : public wxFrame {
public:
  Frame() : wxFrame(nullptr, wxID_ANY, "ScrollBar example", wxDefaultPosition) {
    SetClientSize(300, 300);
    
    scrollBar1->SetScrollbar(100, 1, 200, 1);
    scrollBar1->SetSize(220, scrollBar1->GetSize().GetHeight());

    scrollBar3->SetScrollbar(100, 1, 200, 1);
    scrollBar3->SetSize(scrollBar3->GetSize().GetWidth(), 220);
  }
  
private:
  wxPanel* panel = new wxPanel(this);
  wxScrollBar* scrollBar1 = new wxScrollBar(panel, wxID_ANY, wxPoint(10, 10), wxDefaultSize, wxSB_HORIZONTAL);
  wxScrollBar* scrollBar2 = new wxScrollBar(panel, wxID_ANY, wxPoint(10, 40), wxDefaultSize, wxSB_HORIZONTAL);
  wxScrollBar* scrollBar3 = new wxScrollBar(panel, wxID_ANY, wxPoint(270, 70), wxDefaultSize, wxSB_VERTICAL);
  wxScrollBar* scrollBar4 = new wxScrollBar(panel, wxID_ANY, wxPoint(240, 190), wxDefaultSize, wxSB_VERTICAL);
};

class Application : public wxApp {
  bool OnInit() override {(new Frame())->Show(); return true;}
};

wxIMPLEMENT_APP(Application);
