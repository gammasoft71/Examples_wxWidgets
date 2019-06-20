#include <wx/wx.h>

class Form : public wxFrame {
public:
  Form() : wxFrame(nullptr, wxID_ANY, "GroupBox and CheckBox example", wxDefaultPosition, wxSize(300, 180)) {
    this->check2->SetValue(true);
    this->check6->SetValue(true);
    this->Show();
  }
  
private:
  wxPanel* panel = new wxPanel(this);
  wxStaticBox* groupBox1 = new wxStaticBox(this->panel, wxID_ANY, "Group 1", wxPoint(10, 10), wxSize(135, 140));
  wxStaticBox* groupBox2 = new wxStaticBox(this->panel, wxID_ANY, "Group 2", wxPoint(155, 10), wxSize(135, 140));
  wxCheckBox* check1 = new wxCheckBox(this->groupBox1, wxID_ANY, "check 1", wxPoint(10, 15));
  wxCheckBox* check2 = new wxCheckBox(this->groupBox1, wxID_ANY, "check 2", wxPoint(10, 45));
  wxCheckBox* check3 = new wxCheckBox(this->groupBox1, wxID_ANY, "check 3", wxPoint(10, 75));
  wxCheckBox* check4 = new wxCheckBox(this->groupBox2, wxID_ANY, "check 1", wxPoint(10, 15));
  wxCheckBox* check5 = new wxCheckBox(this->groupBox2, wxID_ANY, "check 2", wxPoint(10, 45));
  wxCheckBox* check6 = new wxCheckBox(this->groupBox2, wxID_ANY, "check 3", wxPoint(10, 75));
};

class Application : public wxApp {
public:
  bool OnInit() override {new Form(); return true;}
};

wxIMPLEMENT_APP(Application);
