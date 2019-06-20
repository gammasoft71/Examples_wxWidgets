#include <wx/wx.h>
#include <wx/splitter.h>

class Form : public wxFrame {
public:
  Form() : wxFrame(nullptr, wxID_ANY, "SplitContainer example", wxDefaultPosition, wxSize(300, 300)) {
    this->SetClientSize(300, 300);
    this->splitContainerLeft->SetSplitMode(wxSPLIT_VERTICAL);
    this->splitContainerLeft->SplitVertically(leftPanel1, leftPanel2, 70);
    this->leftPanel1->SetBackgroundColour(wxTheColourDatabase->Find("Light Blue"));
    
    this->splitContainerRight->SetSplitMode(wxSPLIT_VERTICAL);
    this->splitContainerRight->SplitVertically(rightPanel1, rightPanel2, 160);
    this->rightPanel2->SetBackgroundColour(wxColour(0xFF, 0xFF, 0xE0));
    
    this->splitContainerCenter->SetSplitMode(wxSPLIT_HORIZONTAL);
    this->splitContainerCenter->SplitHorizontally(centerPanel1, centerPanel2, 147);
    this->centerPanel1->SetBackgroundColour(wxTheColourDatabase->Find("Pink"));
    this->centerPanel2->SetBackgroundColour(wxColour(0x90, 0xEE, 0x90));

    this->Show();
  }
  
private:
  wxPanel* panel = new wxPanel(this);
  wxSplitterWindow* splitContainerLeft = new wxSplitterWindow(this->panel, wxID_ANY, wxPoint(0, 0), wxSize(300, 300), wxSP_NOBORDER);
  wxPanel* leftPanel1 = new wxPanel(this->splitContainerLeft);
  wxPanel* leftPanel2 = new wxPanel(this->splitContainerLeft);
  wxSplitterWindow* splitContainerRight = new wxSplitterWindow(this->leftPanel2, wxID_ANY, wxPoint(0, 0), wxSize(230, 300), wxSP_NOBORDER);
  wxPanel* rightPanel1 = new wxPanel(this->splitContainerRight);
  wxPanel* rightPanel2 = new wxPanel(this->splitContainerRight);
  wxSplitterWindow* splitContainerCenter = new wxSplitterWindow(this->rightPanel1, wxID_ANY, wxPoint(0, 0), wxSize(160, 300), wxSP_NOBORDER);
  wxPanel* centerPanel1 = new wxPanel(this->splitContainerCenter);
  wxPanel* centerPanel2 = new wxPanel(this->splitContainerCenter);
};

class Application : public wxApp {
public:
  bool OnInit() override {new Form(); return true;}
};

wxIMPLEMENT_APP(Application);
