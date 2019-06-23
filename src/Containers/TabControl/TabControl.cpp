#include <wx/wx.h>
#include <wx/notebook.h>

class Form : public wxFrame {
public:
  Form() : wxFrame(nullptr, wxID_ANY, "TabControl example", wxDefaultPosition) {
    this->SetClientSize(wxSize(390, 270));
    this->tabControl1->AddPage(this->tabpage1, "tabPage1");
    this->tabControl1->AddPage(this->tabpage2, "tabPage2");
    this->tabControl1->AddPage(this->tabpage3, "tabPage3");
  }

private:
  wxPanel* panel = new wxPanel(this);
  wxNotebook* tabControl1 = new wxNotebook(this->panel, wxID_ANY, wxPoint(10, 10), wxSize(370, 250));
  wxNotebookPage* tabpage1 = new wxNotebookPage(this->tabControl1, wxID_ANY);
  wxNotebookPage* tabpage2 = new wxNotebookPage(this->tabControl1, wxID_ANY);
  wxNotebookPage* tabpage3 = new wxNotebookPage(this->tabControl1, wxID_ANY);
};

class Application : public wxApp {
  bool OnInit() override {return (new Form())->Show();}
};

wxIMPLEMENT_APP(Application);
