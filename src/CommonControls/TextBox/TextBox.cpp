#include <wx/wx.h>

class Form : public wxFrame {
public:
  Form() : wxFrame(nullptr, wxID_ANY, "TextBox example", wxDefaultPosition, wxSize(300, 300)) {
    textBox1->Bind(wxEVT_TEXT, [&](wxCommandEvent& event) {
      if (textBox2->GetValue() != textBox1->GetValue())
        textBox2->SetValue(textBox1->GetValue());
    });

    textBox2->Bind(wxEVT_TEXT, [&](wxCommandEvent& event) {
      if (textBox1->GetValue() != textBox2->GetValue())
        textBox1->SetValue(textBox2->GetValue());
    });
    
    Show();
    textBox2->SetFocus();
  }
  
private:
  wxPanel* panel = new wxPanel(this);
  wxTextCtrl* textBox1 = new wxTextCtrl(panel, wxID_ANY, "textBox", wxPoint(10, 10));
  wxTextCtrl* textBox2 = new wxTextCtrl(panel, wxID_ANY, "textBox", wxPoint(10, 50));
};

class Application : public wxApp {
  bool OnInit() override {(new Form())->Show(); return true;}
};

wxIMPLEMENT_APP(Application);
