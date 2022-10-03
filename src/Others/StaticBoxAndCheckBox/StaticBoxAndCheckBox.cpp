#include <wx/wx.h>

namespace Examples {
  class Frame : public wxFrame {
  public:
    Frame() : wxFrame(nullptr, wxID_ANY, "StaticBox and CheckBox example") {
      SetClientSize(300, 160);
      
      panel->SetSizerAndFit(boxSizer);
      boxSizer->Add(staticBox1, 1, wxGROW, 10);
      boxSizer->Add(staticBox2, 1, wxGROW, 10);
      
      check2->SetValue(true);
      check6->SetValue(true);
    }
    
  private:
    wxPanel* panel = new wxPanel(this);
    wxBoxSizer* boxSizer = new wxBoxSizer(wxHORIZONTAL);
    wxStaticBox* staticBox1 = new wxStaticBox(panel, wxID_ANY, "Group 1", {10, 10}, {135, 140});
    wxStaticBox* staticBox2 = new wxStaticBox(panel, wxID_ANY, "Group 2", {155, 10}, {135, 140});
    // If you replace the two lines above with the following two lines you will see the correct expected behavior.
    //wxPanel* staticBox1 = new wxPanel(panel, wxID_ANY, {10, 10}, {135, 140});
    //wxPanel* staticBox2 = new wxPanel(panel, wxID_ANY, {155, 10}, {135, 140});
    wxCheckBox* check1 = new wxCheckBox(staticBox1, wxID_ANY, "check 1", {20, 10});
    wxCheckBox* check2 = new wxCheckBox(staticBox1, wxID_ANY, "check 2", {20, 40});
    wxCheckBox* check3 = new wxCheckBox(staticBox1, wxID_ANY, "check 3", {20, 70});
    wxCheckBox* check4 = new wxCheckBox(staticBox2, wxID_ANY, "check 4", {20, 10});
    wxCheckBox* check5 = new wxCheckBox(staticBox2, wxID_ANY, "check 5", {20, 40});
    wxCheckBox* check6 = new wxCheckBox(staticBox2, wxID_ANY, "check 6", {20, 70});
  };
  
  class Application : public wxApp {
    bool OnInit() override {
      (new Frame())->Show();
      return true;
    }
  };
}

wxIMPLEMENT_APP(Examples::Application);
