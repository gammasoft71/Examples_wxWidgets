#include <wx/wx.h>
#include <wx/notebook.h>

class Form : public wxFrame {
public:
  Form() : wxFrame(nullptr, wxID_ANY, "Colored TabPages example", wxDefaultPosition) {
  this->SetClientSize(wxSize(390, 270));
    this->tabControl1->AddPage(new wxNotebookPage(this->tabControl1, wxID_ANY), "Red");
    this->tabControl1->GetPage(0)->SetBackgroundColour(wxTheColourDatabase->Find("Red"));

    this->tabControl1->AddPage(new wxNotebookPage(this->tabControl1, wxID_ANY), "Green");
    this->tabControl1->GetPage(1)->SetBackgroundColour(wxColour(0, 0x80, 0, 0xFF));

    this->tabControl1->AddPage(new wxNotebookPage(this->tabControl1, wxID_ANY), "Blue");
    this->tabControl1->GetPage(2)->SetBackgroundColour(wxTheColourDatabase->Find("BLUE"));

    this->tabControl1->AddPage(new wxNotebookPage(this->tabControl1, wxID_ANY), "Yellow");
    this->tabControl1->GetPage(3)->SetBackgroundColour(wxTheColourDatabase->Find("YELLOW"));
  }

private:
  wxPanel* panel = new wxPanel(this);
  wxNotebook* tabControl1 = new wxNotebook(this->panel, wxID_ANY, wxPoint(10, 10), wxSize(370, 250));
};

class Application : public wxApp {
  bool OnInit() override {return (new Form())->Show();}
};

wxIMPLEMENT_APP(Application);