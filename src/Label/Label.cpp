#include <wx/wx.h>

class Form : public wxFrame {
public:
  Form() : wxFrame(nullptr, wxID_ANY, "Form example", wxDefaultPosition, wxSize(300, 300)) {
  }
  
private:
  wxPanel* panel = new wxPanel(this);
  wxStaticText* label1 = new wxStaticText(this->panel, wxID_ANY, "label1", wxPoint(10, 10));
};

class Application : public wxApp {
public:
  bool OnInit() override {
    this->form = new Form();
    this->form->Show(true);
    return true;
  }
  
private:
  Form* form;
};

wxIMPLEMENT_APP(Application);
