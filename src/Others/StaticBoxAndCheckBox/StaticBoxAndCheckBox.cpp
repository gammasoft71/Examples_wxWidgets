#include <wx/wx.h>

class Frame : public wxFrame {
public:
  Frame() : wxFrame(nullptr, wxID_ANY, "StaticBox and CheckBox example", wxDefaultPosition) {
    SetClientSize(wxSize(300, 160));
    check2->SetValue(true);
    check6->SetValue(true);
  }
  
private:
  wxPanel* panel = new wxPanel(this);
  wxStaticBox* staticBox1 = new wxStaticBox(panel, wxID_ANY, "Group 1", {10, 10}, wxSize(135, 140));
  wxStaticBox* staticBox2 = new wxStaticBox(panel, wxID_ANY, "Group 2", wxPoint(155, 10), wxSize(135, 140));
  wxCheckBox* check1 = new wxCheckBox(staticBox1, wxID_ANY, "check 1", wxPoint(10, 15));
  wxCheckBox* check2 = new wxCheckBox(staticBox1, wxID_ANY, "check 2", wxPoint(10, 45));
  wxCheckBox* check3 = new wxCheckBox(staticBox1, wxID_ANY, "check 3", wxPoint(10, 75));
  wxCheckBox* check4 = new wxCheckBox(staticBox2, wxID_ANY, "check 1", wxPoint(10, 15));
  wxCheckBox* check5 = new wxCheckBox(staticBox2, wxID_ANY, "check 2", wxPoint(10, 45));
  wxCheckBox* check6 = new wxCheckBox(staticBox2, wxID_ANY, "check 3", wxPoint(10, 75));
};

class Application : public wxApp {
  bool OnInit() override {(new Frame())->Show(); return true;}
};

wxIMPLEMENT_APP(Application);
