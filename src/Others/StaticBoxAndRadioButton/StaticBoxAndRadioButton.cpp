#include <wx/wx.h>

namespace StaticBoxAndRadioButtonExample {
  class Frame : public wxFrame {
  public:
    Frame() : wxFrame(nullptr, wxID_ANY, "StaticBox and RadioButton example") {
      boxSizer->Add(staticBoxSizer1, wxSizerFlags(1).Expand().Border(wxALL, 10));
      boxSizer->Add(staticBoxSizer2, wxSizerFlags(1).Expand().Border(wxALL, 10));

      staticBoxSizer1->Add(radio1, wxSizerFlags().Border(wxALL, 5));
      staticBoxSizer1->Add(radio2, wxSizerFlags().Border(wxALL, 5));
      staticBoxSizer1->Add(radio3, wxSizerFlags().Border(wxALL, 5));
      
      staticBoxSizer2->Add(radio4, wxSizerFlags().Border(wxALL, 5));
      staticBoxSizer2->Add(radio5, wxSizerFlags().Border(wxALL, 5));
      staticBoxSizer2->Add(radio6, wxSizerFlags().Border(wxALL, 5));
      
      panel->SetSizerAndFit(boxSizer);
      SetClientSize(300, 160);

      radio1->SetValue(true);
      radio5->SetValue(true);
    }
    
  private:
    wxPanel* panel = new wxPanel(this);
    wxBoxSizer* boxSizer = new wxBoxSizer(wxHORIZONTAL);
    wxStaticBoxSizer* staticBoxSizer1 = new wxStaticBoxSizer(wxVERTICAL, panel, "Group 1");
    wxStaticBoxSizer* staticBoxSizer2 = new wxStaticBoxSizer(wxVERTICAL, panel, "Group 2");
    wxRadioButton* radio1 = new wxRadioButton(staticBoxSizer1->GetStaticBox(), wxID_ANY, "radio 1");
    wxRadioButton* radio2 = new wxRadioButton(staticBoxSizer1->GetStaticBox(), wxID_ANY, "radio 2");
    wxRadioButton* radio3 = new wxRadioButton(staticBoxSizer1->GetStaticBox(), wxID_ANY, "radio 3");
    wxRadioButton* radio4 = new wxRadioButton(staticBoxSizer2->GetStaticBox(), wxID_ANY, "radio 4");
    wxRadioButton* radio5 = new wxRadioButton(staticBoxSizer2->GetStaticBox(), wxID_ANY, "radio 5");
    wxRadioButton* radio6 = new wxRadioButton(staticBoxSizer2->GetStaticBox(), wxID_ANY, "radio 6");
  };

  class Application : public wxApp {
    bool OnInit() override {
      (new Frame())->Show();
      return true;
    }
  };
}

wxIMPLEMENT_APP(StaticBoxAndRadioButtonExample::Application);
