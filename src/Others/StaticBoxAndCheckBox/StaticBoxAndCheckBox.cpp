#include <wx/wx.h>

class wxGroupBox : public wxStaticBox {
public:
  wxGroupBox(wxWindow* parent, wxWindowID id, const wxString& label, const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxDefaultSize, long style = 0, const wxString& name = wxASCII_STR(wxStaticBoxNameStr)) : wxStaticBox(parent, id, label, pos, size, style, name) {
    Bind(wxEVT_SIZE, [&](wxSizeEvent & event) {
      inner_panel->SetPosition(get_inner_box_position());
      inner_panel->SetSize(get_inner_box_size());
    });
  }
  
  wxPoint GetClientAreaOrigin() const override {return {inner_margin, inner_margin + extra_inner_margin_up};}
  
  void DoGetClientSize(int* width, int* height) const override {
    wxStaticBox::DoGetSize(width, height);
    *width = *width - GetClientAreaOrigin().x - inner_margin;
    *height = *height - GetClientAreaOrigin().y - inner_margin;
  }
  
  wxWindow* GetMainWindowOfCompositeControl() override {return inner_panel;}
  
private:
  wxPoint get_inner_box_position() const {
    if (wxPlatformInfo::Get().GetOperatingSystemFamilyName() == "Windows") return {0, inner_margin + extra_inner_margin_up};
    if (wxPlatformInfo::Get().GetOperatingSystemFamilyName() == "Macintosh") return {inner_margin, inner_margin + extra_inner_margin_up};
    if (wxPlatformInfo::Get().GetOperatingSystemFamilyName() == "Unix") return {inner_margin, 0};
    return {0, 0};
  }
  
  wxSize get_inner_box_size() const {
    if (wxPlatformInfo::Get().GetOperatingSystemFamilyName() == "Windows") return {GetClientSize().GetWidth(), GetClientSize().GetHeight() - GetClientAreaOrigin().y};
    if (wxPlatformInfo::Get().GetOperatingSystemFamilyName() == "Macintosh") return {GetClientSize().GetWidth() - GetClientAreaOrigin().x - inner_margin, GetClientSize().GetHeight() - GetClientAreaOrigin().y - inner_margin};
    if (wxPlatformInfo::Get().GetOperatingSystemFamilyName() == "Unix") return {GetClientSize().GetWidth() - inner_margin, GetClientSize().GetHeight() - GetClientAreaOrigin().y - inner_margin};
    return GetClientSize();
  }
  
  static constexpr int32_t inner_margin = 3;
  static constexpr int32_t extra_inner_margin_up = 5;
  wxPanel* inner_panel = new wxPanel(this, wxID_ANY, get_inner_box_position(), get_inner_box_size());
};

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
    wxGroupBox* staticBox1 = new wxGroupBox(panel, wxID_ANY, "Group 1", {10, 10}, {135, 140});
    wxGroupBox* staticBox2 = new wxGroupBox(panel, wxID_ANY, "", {155, 10}, {135, 140});
    wxCheckBox* check1 = new wxCheckBox(staticBox1->GetMainWindowOfCompositeControl(), wxID_ANY, "check 1", {20, 10});
    wxCheckBox* check2 = new wxCheckBox(staticBox1->GetMainWindowOfCompositeControl(), wxID_ANY, "check 2", {20, 40});
    wxCheckBox* check3 = new wxCheckBox(staticBox1->GetMainWindowOfCompositeControl(), wxID_ANY, "check 3", {20, 70});
    wxCheckBox* check4 = new wxCheckBox(staticBox2->GetMainWindowOfCompositeControl(), wxID_ANY, "check 4", {20, 10});
    wxCheckBox* check5 = new wxCheckBox(staticBox2->GetMainWindowOfCompositeControl(), wxID_ANY, "check 5", {20, 40});
    wxCheckBox* check6 = new wxCheckBox(staticBox2->GetMainWindowOfCompositeControl(), wxID_ANY, "check 6", {20, 70});
  };
  
  class Application : public wxApp {
    bool OnInit() override {
      (new Frame())->Show();
      return true;
    }
  };
}

wxIMPLEMENT_APP(Examples::Application);
