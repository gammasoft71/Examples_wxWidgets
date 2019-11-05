#include <wx/wx.h>

class Form : public wxFrame {
public:
  Form() : wxFrame(nullptr, wxID_ANY, "ComboBox example", wxDefaultPosition, wxSize(300, 300)) {
    comboBox1->Append("item1");
    comboBox1->Append("item2");
    comboBox1->Append("item3");
    comboBox1->Append("item4");
    comboBox1->Select(0);

    comboBox2->Append("item1");
    comboBox2->Append("item2");
    comboBox2->Append("item3");
    comboBox2->Append("item4");
    comboBox2->Select(1);

    comboBox3->Append("item1");
    comboBox3->Append("item2");
    comboBox3->Append("item3");
    comboBox3->Append("item4");
    comboBox3->Select(2);
  }
  
private:
  wxPanel* panel = new wxPanel(this);
  wxComboBox* comboBox1 = new wxComboBox(panel, wxID_ANY, wxEmptyString, wxPoint(10, 10), wxDefaultSize);
  wxComboBox* comboBox2 = new wxComboBox(panel, wxID_ANY, wxEmptyString, wxPoint(10, 50), wxDefaultSize, 0, nullptr, wxCB_READONLY);
  wxComboBox* comboBox3 = new wxComboBox(panel, wxID_ANY, wxEmptyString, wxPoint(10, 90), wxSize(110, 150), 0, nullptr, wxCB_SIMPLE);
};

class Application : public wxApp {
  bool OnInit() override {(new Form())->Show(); return true;}
};

wxIMPLEMENT_APP(Application);
