#include <wx/wx.h>
#include <wx/splitter.h>

class Form : public wxFrame {
public:
  Form() : wxFrame(nullptr, wxID_ANY, "SplitContainer example", wxDefaultPosition) {
    SetClientSize(300, 300);
    splitContainerLeft->SetSplitMode(wxSPLIT_VERTICAL);
    splitContainerLeft->SplitVertically(leftPanel1, leftPanel2, 70);
    leftPanel1->SetBackgroundColour(wxTheColourDatabase->Find("Light Blue"));
    
    splitContainerRight->SetSplitMode(wxSPLIT_VERTICAL);
    splitContainerRight->SplitVertically(rightPanel1, rightPanel2, 160);
    rightPanel2->SetBackgroundColour(wxColour(0xFF, 0xFF, 0xE0));
    
    splitContainerCenter->SetSplitMode(wxSPLIT_HORIZONTAL);
    splitContainerCenter->SplitHorizontally(centerPanel1, centerPanel2, 147);
    centerPanel1->SetBackgroundColour(wxTheColourDatabase->Find("Pink"));
    centerPanel2->SetBackgroundColour(wxColour(0x90, 0xEE, 0x90));
  }
  
private:
  wxPanel* panel = new wxPanel(this);
  wxSplitterWindow* splitContainerLeft = new wxSplitterWindow(panel, wxID_ANY, wxPoint(0, 0), wxSize(300, 300), wxSP_NOBORDER);
  wxPanel* leftPanel1 = new wxPanel(splitContainerLeft);
  wxPanel* leftPanel2 = new wxPanel(splitContainerLeft);
  wxSplitterWindow* splitContainerRight = new wxSplitterWindow(leftPanel2, wxID_ANY, wxPoint(0, 0), wxSize(230, 300), wxSP_NOBORDER);
  wxPanel* rightPanel1 = new wxPanel(splitContainerRight);
  wxPanel* rightPanel2 = new wxPanel(splitContainerRight);
  wxSplitterWindow* splitContainerCenter = new wxSplitterWindow(rightPanel1, wxID_ANY, wxPoint(0, 0), wxSize(160, 300), wxSP_NOBORDER);
  wxPanel* centerPanel1 = new wxPanel(splitContainerCenter);
  wxPanel* centerPanel2 = new wxPanel(splitContainerCenter);
};

class Application : public wxApp {
  bool OnInit() override {(new Form())->Show(); return true;}
};

wxIMPLEMENT_APP(Application);
