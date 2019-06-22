#include <wx/wx.h>
#include <vector>

class Form : public wxFrame {
public:
  Form() : wxFrame(nullptr, wxID_ANY, "ComboBox example", wxDefaultPosition, wxSize(300, 300)) {
    this->comboBox1->Insert("item1", 0);
    this->comboBox1->Insert("item2", 1);
    this->comboBox1->Insert("item3", 2);
    this->comboBox1->Select(1);
  }
  
private:
  wxPanel* panel = new wxPanel(this);
  wxComboBox* comboBox1 = new wxComboBox(this->panel, wxID_ANY, wxEmptyString, wxPoint(10, 10));
};

class Application : public wxApp {
  bool OnInit() override {return (new Form())->Show();}
};

wxIMPLEMENT_APP(Application);
