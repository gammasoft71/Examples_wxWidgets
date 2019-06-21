#include <wx/wx.h>
#include <wx/splitter.h>

class Form : public wxFrame {
public:
  Form() : wxFrame(nullptr, wxID_ANY, "SplitContainer example", wxDefaultPosition) {
    this->SetClientSize(300, 300);
    this->splitContainerLeft.SetSplitMode(wxSPLIT_VERTICAL);
    this->splitContainerLeft.SplitVertically(&leftPanel1, &leftPanel2, 70);
    this->leftPanel1.SetBackgroundColour(wxTheColourDatabase->Find("Light Blue"));
    
    this->splitContainerRight.SetSplitMode(wxSPLIT_VERTICAL);
    this->splitContainerRight.SplitVertically(&rightPanel1, &rightPanel2, 160);
    this->rightPanel2.SetBackgroundColour(wxColour(0xFF, 0xFF, 0xE0));
    
    this->splitContainerCenter.SetSplitMode(wxSPLIT_HORIZONTAL);
    this->splitContainerCenter.SplitHorizontally(&centerPanel1, &centerPanel2, 147);
    this->centerPanel1.SetBackgroundColour(wxTheColourDatabase->Find("Pink"));
    this->centerPanel2.SetBackgroundColour(wxColour(0x90, 0xEE, 0x90));

    this->Show();
  }
  
private:
  wxPanel panel = {this};
  wxSplitterWindow splitContainerLeft {&this->panel, wxID_ANY, wxPoint(0, 0), wxSize(300, 300), wxSP_NOBORDER};
  wxPanel leftPanel1 = {&this->splitContainerLeft};
  wxPanel leftPanel2 = {&this->splitContainerLeft};
  wxSplitterWindow splitContainerRight {&this->leftPanel2, wxID_ANY, wxPoint(0, 0), wxSize(230, 300), wxSP_NOBORDER};
  wxPanel rightPanel1 = {&this->splitContainerRight};
  wxPanel rightPanel2 = {&this->splitContainerRight};
  wxSplitterWindow splitContainerCenter {&this->rightPanel1, wxID_ANY, wxPoint(0, 0), wxSize(160, 300), wxSP_NOBORDER};
  wxPanel centerPanel1 = {&this->splitContainerCenter};
  wxPanel centerPanel2 = {&this->splitContainerCenter};
};

class Application : public wxApp {
public:
  bool OnInit() override {new Form(); return true;}
};

wxIMPLEMENT_APP(Application);
