#include <wx/wx.h>

namespace ScrollBarExample {
  class Frame : public wxFrame {
  public:
    Frame() : wxFrame(nullptr, wxID_ANY, "ScrollBar example") {
      SetClientSize(300, 300);
      
      scrollBar1->SetScrollbar(10, 1, 20, 1);
      scrollBar1->SetSize(220, scrollBar1->GetSize().GetHeight());
      scrollBar1->Bind(wxEVT_SCROLLBAR, [&](wxCommandEvent& e){
        wxMessageOutputDebug().Printf("wxEVT_SCROLL_TOP {position %d}", scrollBar1->GetThumbPosition());
      });

      scrollBar2->SetScrollbar(0, 1, 100, 1);

      scrollBar3->SetScrollbar(10, 1, 20, 1);
      scrollBar3->SetSize(scrollBar3->GetSize().GetWidth(), 220);

      scrollBar4->SetScrollbar(0, 1, 100, 1);
    }
    
  private:
    wxPanel* panel = new wxPanel(this);
    wxScrollBar* scrollBar1 = new wxScrollBar(panel, wxID_ANY, {10, 10}, wxDefaultSize, wxSB_HORIZONTAL);
    wxScrollBar* scrollBar2 = new wxScrollBar(panel, wxID_ANY, {10, 40}, wxDefaultSize, wxSB_HORIZONTAL);
    wxScrollBar* scrollBar3 = new wxScrollBar(panel, wxID_ANY, {270, 70}, wxDefaultSize, wxSB_VERTICAL);
    wxScrollBar* scrollBar4 = new wxScrollBar(panel, wxID_ANY, {240, 190}, wxDefaultSize, wxSB_VERTICAL);
  };

  class Application : public wxApp {
    bool OnInit() override {
      (new Frame())->Show();
      return true;
    }
  };
}

wxIMPLEMENT_APP(ScrollBarExample::Application);
