#include <wx/wx.h>
#include <wx/Notebook.h>

class Form : public wxFrame {
public:
  Form() : wxFrame(nullptr, wxID_ANY, "Form example", wxDefaultPosition, wxSize(390, 290)) {
    this->tabControl1->AddPage(new wxNotebookPage(this->tabControl1, wxID_ANY), "tabPage1");
    this->tabControl1->AddPage(new wxNotebookPage(this->tabControl1, wxID_ANY), "tabPage2");
    this->tabControl1->AddPage(new wxNotebookPage(this->tabControl1, wxID_ANY), "tabPage3");
    this->Show();
  }
  
private:
  wxPanel* panel = new wxPanel(this);
  wxNotebook* tabControl1 = new wxNotebook(this->panel, wxID_ANY, wxPoint(10, 10), wxSize(370, 250));
};

class Application : public wxApp {
public:
  bool OnInit() override {new Form(); return true;}
};

wxIMPLEMENT_APP(Application);
