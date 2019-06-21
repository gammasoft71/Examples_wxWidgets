#include <wx/wx.h>

class Form : public wxFrame {
public:
  Form() : wxFrame(nullptr, wxID_ANY, "TextBox example", wxDefaultPosition, wxSize(300, 300)) {
    this->textBox1.Bind(wxEVT_TEXT, [&](wxCommandEvent& event) {
      if (this->textBox2.GetValue() != this->textBox1.GetValue())
        this->textBox2.SetValue(this->textBox1.GetValue());
    });

    this->textBox2.Bind(wxEVT_TEXT, [&](wxCommandEvent& event) {
      if (this->textBox1.GetValue() != this->textBox2.GetValue())
        this->textBox1.SetValue(this->textBox2.GetValue());
    });
  }
  
private:
  wxPanel panel {this};
  wxTextCtrl textBox1 {&this->panel, wxID_ANY, "textBox", wxPoint(10, 10)};
  wxTextCtrl textBox2 {&this->panel, wxID_ANY, "textBox", wxPoint(10, 50)};
};

class Application : public wxApp {
  bool OnInit() override {return (new Form())->Show();}
};

wxIMPLEMENT_APP(Application);
