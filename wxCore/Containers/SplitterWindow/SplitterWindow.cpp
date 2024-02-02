#include <wx/wx.h>
#include <wx/splitter.h>

namespace SplitterWindowExample {
  class Frame : public wxFrame {
  public:
    Frame() : wxFrame(nullptr, wxID_ANY, "SplitterWindow example") {
      SetClientSize(300, 300);
      splitterWindowLeft->SetSplitMode(wxSPLIT_VERTICAL);
      splitterWindowLeft->SplitVertically(leftPanel1, leftPanel2, 70);
      leftPanel1->SetBackgroundColour(wxTheColourDatabase->Find("Light Blue"));
      
      splitterWindowRight->SetSplitMode(wxSPLIT_VERTICAL);
      splitterWindowRight->SplitVertically(rightPanel1, rightPanel2, 160);
      rightPanel2->SetBackgroundColour({0xFF, 0xFF, 0xE0});
      
      splitterWindowCenter->SetSplitMode(wxSPLIT_HORIZONTAL);
      splitterWindowCenter->SplitHorizontally(centerPanel1, centerPanel2, 147);
      centerPanel1->SetBackgroundColour(wxTheColourDatabase->Find("Pink"));
      centerPanel2->SetBackgroundColour({0x90, 0xEE, 0x90});
    }
    
  private:
    wxPanel* panel = new wxPanel {this};
    wxSplitterWindow* splitterWindowLeft = new wxSplitterWindow(panel, wxID_ANY, {0, 0}, {300, 300}, wxSP_NOBORDER);
    wxPanel* leftPanel1 = new wxPanel(splitterWindowLeft);
    wxPanel* leftPanel2 = new wxPanel(splitterWindowLeft);
    wxSplitterWindow* splitterWindowRight = new wxSplitterWindow(leftPanel2, wxID_ANY, {0, 0}, {230, 300}, wxSP_NOBORDER);
    wxPanel* rightPanel1 = new wxPanel(splitterWindowRight);
    wxPanel* rightPanel2 = new wxPanel(splitterWindowRight);
    wxSplitterWindow* splitterWindowCenter = new wxSplitterWindow(rightPanel1, wxID_ANY, {0, 0}, {160, 300}, wxSP_NOBORDER);
    wxPanel* centerPanel1 = new wxPanel(splitterWindowCenter);
    wxPanel* centerPanel2 = new wxPanel(splitterWindowCenter);
  };

  class Application : public wxApp {
    bool OnInit() override {
      (new Frame)->Show();
      return true;
    }
  };
}

wxIMPLEMENT_APP(SplitterWindowExample::Application);
