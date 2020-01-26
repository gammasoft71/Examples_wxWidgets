#include <wx/app.h>
#include <wx/frame.h>
#include <wx/panel.h>
#include <wx/sizer.h>
#include <wx/radiobut.h>
#include <wx/textctrl.h>

namespace Examples {
  class Frame : public wxFrame {
  public:
    Frame() : wxFrame(nullptr, wxID_ANY, "TextCtrl example", wxDefaultPosition, {300, 300}) {
      textCtrl1->Bind(wxEVT_TEXT, [&](wxCommandEvent& event) {
        if (textCtrl2->GetValue() != textCtrl1->GetValue())
          textCtrl2->SetValue(textCtrl1->GetValue());
      });

      textCtrl2->Bind(wxEVT_TEXT, [&](wxCommandEvent& event) {
        if (textCtrl1->GetValue() != textCtrl2->GetValue())
          textCtrl1->SetValue(textCtrl2->GetValue());
      });
      
      Show();
      textCtrl2->SetFocus();
    }
    
  private:
    wxPanel* panel = new wxPanel(this);
    wxTextCtrl* textCtrl1 = new wxTextCtrl(panel, wxID_ANY, "textBox", {10, 10});
    wxTextCtrl* textCtrl2 = new wxTextCtrl(panel, wxID_ANY, "textBox", {10, 50});
  };

  class Application : public wxApp {
    bool OnInit() override {
      new Frame();
      return true;
    }
  };
}

wxIMPLEMENT_APP(Examples::Application);
