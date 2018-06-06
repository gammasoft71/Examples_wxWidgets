#include <wx/wx.h>

class Form : public wxFrame {
public:
  Form() : wxFrame(nullptr, wxID_ANY, "Form example", wxDefaultPosition, wxSize(640, 480)) {
    this->panel1->SetWindowStyle(wxBORDER_SIMPLE);
    this->panel2->SetWindowStyle(wxBORDER_SUNKEN);
  }
  
private:
  wxPanel* panel = new wxPanel(this);
  wxPanel* panel1 = new wxPanel(this->panel, wxID_ANY, wxPoint(10, 10), wxSize(305, 440));
  wxPanel* panel2 = new wxPanel(this->panel, wxID_ANY, wxPoint(325, 10), wxSize(305, 440));
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
