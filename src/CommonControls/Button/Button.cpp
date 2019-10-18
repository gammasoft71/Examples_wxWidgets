#include <wx/wx.h>

class Form : public wxFrame {
public:
  Form() : wxFrame(nullptr, wxID_ANY, wxEmptyString, wxDefaultPosition, wxSize(300, 300)) {
    button1->Bind(wxEVT_BUTTON, [this](wxCommandEvent& event) {
      label1->SetLabel(wxString::Format("button1 clicked %d times", ++button1Clicked));
    });

    button2->Bind(wxEVT_BUTTON, [this](wxCommandEvent& event) {
      label2->SetLabel(wxString::Format("button2 clicked %d times", ++button2Clicked));
    });
  }
  
private:
  wxPanel* panel = new wxPanel(this);
  wxButton* button1 = new wxButton(panel, wxID_ANY, "button1", wxPoint(50, 50), wxDefaultSize, wxBU_TOP | wxBU_RIGHT);
  wxButton* button2 = new wxButton(panel, wxID_ANY, "button2", wxPoint(50, 100), wxSize(200, 75));
  wxStaticText* label1 = new wxStaticText(panel, wxID_ANY, "button1 clicked 0 times", wxPoint(50, 200), wxSize(200, 20));
  wxStaticText* label2 = new wxStaticText(panel, wxID_ANY, "button2 clicked 0 times", wxPoint(50, 230), wxSize(200, 20));
  int button1Clicked = 0;
  int button2Clicked = 0;
};

class Application : public wxApp {
  bool OnInit() override {(new Form())->Show(); return true;}
};

wxIMPLEMENT_APP(Application);
