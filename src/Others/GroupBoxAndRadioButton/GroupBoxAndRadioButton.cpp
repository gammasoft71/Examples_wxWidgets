#include <wx/wx.h>

class Frame : public wxFrame {
public:
  Frame() : wxFrame(nullptr, wxID_ANY, "GroupBox and RadioButton example", wxDefaultPosition) {
    SetClientSize(wxSize(300, 160));
    radio1->SetValue(true);
    radio5->SetValue(true);
  }
  
private:
  wxPanel* panel = new wxPanel(this);
  wxStaticBox* groupBox1 = new wxStaticBox(panel, wxID_ANY, "Group 1", wxPoint(10, 10), wxSize(135, 140));
  wxStaticBox* groupBox2 = new wxStaticBox(panel, wxID_ANY, "Group 2", wxPoint(155, 10), wxSize(135, 140));
  wxRadioButton* radio1 = new wxRadioButton(groupBox1, wxID_ANY, "radio 1", wxPoint(10, 15));
  wxRadioButton* radio2 = new wxRadioButton(groupBox1, wxID_ANY, "radio 2", wxPoint(10, 45));
  wxRadioButton* radio3 = new wxRadioButton(groupBox1, wxID_ANY, "radio 3", wxPoint(10, 75));
  wxRadioButton* radio4 = new wxRadioButton(groupBox2, wxID_ANY, "radio 4", wxPoint(10, 15));
  wxRadioButton* radio5 = new wxRadioButton(groupBox2, wxID_ANY, "radio 5", wxPoint(10, 45));
  wxRadioButton* radio6 = new wxRadioButton(groupBox2, wxID_ANY, "radio 6", wxPoint(10, 75));
};

class Application : public wxApp {
  bool OnInit() override {(new Frame())->Show(); return true;}
};

wxIMPLEMENT_APP(Application);
