#include <wx/wx.h>

namespace Examples {
  class Frame : public wxFrame {
  public:
    Frame() : wxFrame(nullptr, wxID_ANY, "StaticBox and RadioButton example") {
      SetClientSize(300, 160);
      radio1->SetValue(true);
      radio5->SetValue(true);
    }
    
  private:
    wxPanel* panel = new wxPanel(this);
    wxStaticBox* staticBox1 = new wxStaticBox(panel, wxID_ANY, "Group 1", {10, 10}, {135, 140});
    wxStaticBox* staticBox2 = new wxStaticBox(panel, wxID_ANY, "Group 2", {155, 10}, {135, 140});
    wxRadioButton* radio1 = new wxRadioButton(staticBox1, wxID_ANY, "radio 1", {10, 15});
    wxRadioButton* radio2 = new wxRadioButton(staticBox1, wxID_ANY, "radio 2", {10, 45});
    wxRadioButton* radio3 = new wxRadioButton(staticBox1, wxID_ANY, "radio 3", {10, 75});
    wxRadioButton* radio4 = new wxRadioButton(staticBox2, wxID_ANY, "radio 4", {10, 15});
    wxRadioButton* radio5 = new wxRadioButton(staticBox2, wxID_ANY, "radio 5", {10, 45});
    wxRadioButton* radio6 = new wxRadioButton(staticBox2, wxID_ANY, "radio 6", {10, 75});
  };

  class Application : public wxApp {
    bool OnInit() override {
      (new Frame())->Show();
      return true;
    }
  };
}

wxIMPLEMENT_APP(Examples::Application);
