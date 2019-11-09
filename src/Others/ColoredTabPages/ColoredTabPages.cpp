#include <wx/wx.h>
#include <wx/notebook.h>

class Form : public wxFrame {
public:
  Form() : wxFrame(nullptr, wxID_ANY, "Colored TabPages example", wxDefaultPosition) {
    SetClientSize(wxSize(390, 270));
    tabControl1->AddPage(tabPageRed, "Red");
    tabPageRed->SetBackgroundColour(wxTheColourDatabase->Find("Red"));

    tabControl1->AddPage(tabPageGreen, "Green");
    tabPageGreen->SetBackgroundColour(wxColour(0, 0x80, 0));

    tabControl1->AddPage(tabPageBlue, "Blue");
    tabPageBlue->SetBackgroundColour(wxTheColourDatabase->Find("Blue"));

    tabControl1->AddPage(tabPageYellow, "Yellow");
    tabPageYellow->SetBackgroundColour(wxTheColourDatabase->Find("Yellow"));
  }

private:
  wxPanel* panel = new wxPanel(this);
  wxNotebook* tabControl1 = new wxNotebook(panel, wxID_ANY, wxPoint(10, 10), wxSize(370, 250));
  wxNotebookPage* tabPageRed = new wxNotebookPage(tabControl1, wxID_ANY);
  wxNotebookPage* tabPageGreen = new wxNotebookPage(tabControl1, wxID_ANY);
  wxNotebookPage* tabPageBlue = new wxNotebookPage(tabControl1, wxID_ANY);
  wxNotebookPage* tabPageYellow = new wxNotebookPage(tabControl1, wxID_ANY);
};

class Application : public wxApp {
  bool OnInit() override {(new Form())->Show(); return true;}
};

wxIMPLEMENT_APP(Application);
