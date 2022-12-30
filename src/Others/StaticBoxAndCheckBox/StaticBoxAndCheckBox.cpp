#include <wx/wx.h>

namespace Examples {
  class Frame : public wxFrame {
  public:
    Frame() : wxFrame(nullptr, wxID_ANY, "StaticBox and CheckBox example") {
      SetClientSize(300, 160);
      
      check2->SetValue(true);
      check6->SetValue(true);
    }
    
  private:
    wxPanel* panel = new wxPanel(this);
    wxStaticBox* staticBox1 = new wxStaticBox(panel, wxID_ANY, "Group 1", {10, 10}, {135, 140});
    wxStaticBox* staticBox2 = new wxStaticBox(panel, wxID_ANY, "Group 2", {155, 10}, {135, 140});
    wxCheckBox* check1 = new wxCheckBox(staticBox1->GetMainWindowOfCompositeControl(), wxID_ANY, "check 1", {20, 20});
    wxCheckBox* check2 = new wxCheckBox(staticBox1->GetMainWindowOfCompositeControl(), wxID_ANY, "check 2", {20, 50});
    wxCheckBox* check3 = new wxCheckBox(staticBox1->GetMainWindowOfCompositeControl(), wxID_ANY, "check 3", {20, 80});
    wxCheckBox* check4 = new wxCheckBox(staticBox2->GetMainWindowOfCompositeControl(), wxID_ANY, "check 4", {20, 20});
    wxCheckBox* check5 = new wxCheckBox(staticBox2->GetMainWindowOfCompositeControl(), wxID_ANY, "check 5", {20, 50});
    wxCheckBox* check6 = new wxCheckBox(staticBox2->GetMainWindowOfCompositeControl(), wxID_ANY, "check 6", {20, 80});
  };
  
  class Application : public wxApp {
    bool OnInit() override {
      (new Frame())->Show();
      return true;
    }
  };
}

wxIMPLEMENT_APP(Examples::Application);
