#include <wx/wx.h>

class Form : public wxFrame {
public:
  Form() : wxFrame(nullptr, wxID_ANY, "GroupBox and CheckBox example", wxDefaultPosition, wxSize(300, 180)) {
    this->radio1->SetValue(true);
    this->radio5->SetValue(true);
    this->Show();
  }
  
private:
  wxPanel* panel = new wxPanel(this);
  wxStaticBox* groupBox1 = new wxStaticBox(this->panel, wxID_ANY, "Group 1", wxPoint(10, 10), wxSize(135, 140));
  wxStaticBox* groupBox2 = new wxStaticBox(this->panel, wxID_ANY, "Group 2", wxPoint(155, 10), wxSize(135, 140));
  wxRadioButton* radio1 = new wxRadioButton(this->groupBox1, wxID_ANY, "radio 1", wxPoint(10, 15));
  wxRadioButton* radio2 = new wxRadioButton(this->groupBox1, wxID_ANY, "radio 2", wxPoint(10, 45));
  wxRadioButton* radio3 = new wxRadioButton(this->groupBox1, wxID_ANY, "radio 3", wxPoint(10, 75));
  wxRadioButton* radio4 = new wxRadioButton(this->groupBox2, wxID_ANY, "radio 4", wxPoint(10, 15));
  wxRadioButton* radio5 = new wxRadioButton(this->groupBox2, wxID_ANY, "radio 5", wxPoint(10, 45));
  wxRadioButton* radio6 = new wxRadioButton(this->groupBox2, wxID_ANY, "radio 6", wxPoint(10, 75));
};

class Application : public wxApp {
public:
  bool OnInit() override {new Form(); return true;}
};

wxIMPLEMENT_APP(Application);
