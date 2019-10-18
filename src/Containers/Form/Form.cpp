#include <wx/wx.h>

class Form : public wxFrame {
public:
  Form() : wxFrame(nullptr, wxID_ANY, "Form example", wxDefaultPosition, wxSize(640, 480)) {
    button->Bind(wxEVT_BUTTON, [&](wxCommandEvent& event) {
      Close();
    });

    Bind(wxEVT_CLOSE_WINDOW, [&](wxCloseEvent& event) {
      bool can_cloase = wxMessageBox("Are you sure you want exit?", "Close Form", wxICON_QUESTION | wxYES_NO) == wxYES;
      event.Veto(!can_cloase);
      event.Skip(can_cloase);
    });
  }

private:
  wxPanel* panel = new wxPanel(this);
  wxButton* button = new wxButton(panel, wxID_ANY, "Close", wxPoint(10, 10));
};

class Application : public wxApp {
  bool OnInit() override {(new Form())->Show(); return true;}
};

wxIMPLEMENT_APP(Application);
