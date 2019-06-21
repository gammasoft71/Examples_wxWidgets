#include <wx/wx.h>
#include <wx/Notebook.h>

class Form : public wxFrame {
public:
  Form() : wxFrame(nullptr, wxID_ANY, "TabControl example", wxDefaultPosition) {
    this->SetClientSize(wxSize(390, 270));
    this->tabControl1.AddPage(&this->tabpage1, "tabPage1");
    this->tabControl1.AddPage(&this->tabpage2, "tabPage2");
    this->tabControl1.AddPage(&this->tabpage3, "tabPage3");
    this->Show();
  }
  
private:
  wxPanel panel {this};
  wxNotebook tabControl1 {&this->panel, wxID_ANY, wxPoint(10, 10), wxSize(370, 250)};
  wxNotebookPage tabpage1 {&this->tabControl1, wxID_ANY};
  wxNotebookPage tabpage2 {&this->tabControl1, wxID_ANY};
  wxNotebookPage tabpage3 {&this->tabControl1, wxID_ANY};
};

class Application : public wxApp {
public:
  bool OnInit() override {new Form(); return true;}
};

wxIMPLEMENT_APP(Application);
