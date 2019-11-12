#include <wx/wx.h>
#include <wx/notebook.h>

class Frame : public wxFrame {
public:
  Frame() : wxFrame(nullptr, wxID_ANY, "TabControl example", wxDefaultPosition) {
    SetClientSize(wxSize(390, 270));
    tabControl1->AddPage(tabpage1, "tabPage1");
    tabControl1->AddPage(tabpage2, "tabPage2");
    tabControl1->AddPage(tabpage3, "tabPage3");
    
    tabpage1->SetLabel("Other");
  }

private:
  wxPanel* panel = new wxPanel(this);
  wxNotebook* tabControl1 = new wxNotebook(panel, wxID_ANY, wxPoint(10, 10), wxSize(370, 250));
  wxNotebookPage* tabpage1 = new wxNotebookPage(tabControl1, wxID_ANY);
  wxNotebookPage* tabpage2 = new wxNotebookPage(tabControl1, wxID_ANY);
  wxNotebookPage* tabpage3 = new wxNotebookPage(tabControl1, wxID_ANY);
};

class Application : public wxApp {
  bool OnInit() override {(new Frame())->Show(); return true;}
};

wxIMPLEMENT_APP(Application);
