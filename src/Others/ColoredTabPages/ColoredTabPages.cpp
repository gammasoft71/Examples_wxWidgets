#include <wx/wx.h>
#include <wx/notebook.h>

class Form : public wxFrame {
public:
  Form() : wxFrame(nullptr, wxID_ANY, "Colored TabPages example", wxDefaultPosition) {
    SetClientSize(wxSize(390, 270));
    
    tabControl1->AddPage(tabPageLightPink, "Light red");
    tabPageLightPink->SetBackgroundColour(wxColour(0xFF, 0xB6, 0xC1, 0xFF));

    tabControl1->AddPage(tabPageLightGreen, "Light green");
    tabPageLightGreen->SetBackgroundColour(wxColour(0x90, 0xEE, 0x90, 0xFF));

    tabControl1->AddPage(tabPageLightBlue, "Light blue");
    tabPageLightBlue->SetBackgroundColour(wxColour(0xAD, 0xD8, 0xE6, 0xFF));

    tabControl1->AddPage(tabPageLightYellow, "Light yellow");
    tabPageLightYellow->SetBackgroundColour(wxColour(0xFF, 0xFF, 0xE0, 0xFF));
  }

private:
  wxPanel* panel = new wxPanel(this);
  wxNotebook* tabControl1 = new wxNotebook(panel, wxID_ANY, wxPoint(10, 10), wxSize(370, 250), wxNB_BOTTOM);
  wxNotebookPage* tabPageLightPink = new wxNotebookPage(tabControl1, wxID_ANY);
  wxNotebookPage* tabPageLightGreen = new wxNotebookPage(tabControl1, wxID_ANY);
  wxNotebookPage* tabPageLightBlue = new wxNotebookPage(tabControl1, wxID_ANY);
  wxNotebookPage* tabPageLightYellow = new wxNotebookPage(tabControl1, wxID_ANY);
};

class Application : public wxApp {
  bool OnInit() override {(new Form())->Show(); return true;}
};

wxIMPLEMENT_APP(Application);
