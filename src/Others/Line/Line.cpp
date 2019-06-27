#include <wx/wx.h>
#include <wx/statline.h>

namespace Examples {
  class Form : public wxFrame {
  public:
    Form() : wxFrame(nullptr, wxID_ANY, "Lines example", wxDefaultPosition, wxSize(300, 300)) {
      this->SetClientSize(wxSize(300, 300));
      
      this->lineRed->SetBackgroundColour(wxColour(255, 0, 0));
      this->lineGreen->SetBackgroundColour(wxColour(0, 143, 0));
      this->lineBlue->SetBackgroundColour(wxColour(0, 0, 255));
      this->lineSeparator2->SetBackgroundColour(wxColour(96, 96, 96));
    }
    
  private:
    wxPanel* panel = new wxPanel(this);
    wxStaticLine* lineSeparator1 = new wxStaticLine(this->panel, wxID_ANY, wxPoint(10, 10), wxSize(280, 2), wxLI_HORIZONTAL);
    wxPanel* lineRed = new wxPanel(this->panel, wxID_ANY, wxPoint(10, 20), wxSize(2, 250));
    wxPanel* lineGreen = new wxPanel(this->panel, wxID_ANY, wxPoint(149, 20), wxSize(2, 250));
    wxPanel* lineBlue = new wxPanel(this->panel, wxID_ANY, wxPoint(288, 20), wxSize(2, 250));
    wxPanel* lineSeparator2 = new wxPanel(this->panel, wxID_ANY, wxPoint(10, 278), wxSize(280, 2));
  };
  
  class Application : public wxApp {
    bool OnInit() override {return (new Form())->Show();}
  };
}

wxIMPLEMENT_APP(Examples::Application);
