#include <wx/wx.h>
#include <wx/commandlinkbutton.h>

class Form : public wxFrame {
public:
  Form() : wxFrame(nullptr, wxID_ANY, "Link button example", wxDefaultPosition, wxSize(300, 300)) {
    linkButton1->Bind(wxEVT_BUTTON, [&](wxCommandEvent& event) {
      label1->SetLabel(wxString::Format("linkButton1 clicked %d times", ++linkButton1Clicked));
    });
  }
  
private:
  wxPanel* panel = new wxPanel(this);
  wxCommandLinkButton* linkButton1 = new wxCommandLinkButton(panel, wxID_ANY, "Link", "Information text", wxPoint(50, 50), wxSize(150, 40));
  wxStaticText* label1 = new wxStaticText(panel, wxID_ANY, "linkButton1 clicked 0 times", wxPoint(50, 120), wxSize(200, 20));
  int linkButton1Clicked = 0;
};

class Application : public wxApp {
  bool OnInit() override {(new Form())->Show(); return true;}
};

wxIMPLEMENT_APP(Application);
