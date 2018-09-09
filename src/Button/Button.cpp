#include <wx/wx.h>

class Form : public wxFrame {
public:
  Form() : wxFrame(nullptr, wxID_ANY, "", wxDefaultPosition, wxSize(300, 300)) {
    this->button1->Bind(wxEVT_BUTTON, [&](wxCommandEvent& event) {
      this->label1->SetLabel(wxString::Format("button1 clicked %d times", ++this->button1Clicked));
    });

    this->button2->Bind(wxEVT_BUTTON, [&](wxCommandEvent& event) {
      this->label2->SetLabel(wxString::Format("button2 clicked %d times", ++this->button2Clicked));
    });
    
    this->Show();
  }
  
private:
  wxPanel* panel = new wxPanel(this);
  wxButton* button1 = new wxButton(this->panel, wxID_ANY, "button1", wxPoint(50, 50));
  wxButton* button2 = new wxButton(this->panel, wxID_ANY, "button2", wxPoint(50, 100), wxSize(200, 75));
  wxStaticText* label1 = new wxStaticText(this->panel, wxID_ANY, "button1 clicked 0 times", wxPoint(50, 200), wxSize(200, 20));
  wxStaticText* label2 = new wxStaticText(this->panel, wxID_ANY, "button2 clicked 0 times", wxPoint(50, 230), wxSize(200, 20));
  int button1Clicked = 0;
  int button2Clicked = 0;
};

class Application : public wxApp {
public:
  bool OnInit() override {new Form(); return true;}
};

wxIMPLEMENT_APP(Application);
