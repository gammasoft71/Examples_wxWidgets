#include <wx/wx.h>
#include <wx/statline.h>

namespace Examples {
  class wxColouredLine : public wxPanel {
  public:
    wxColouredLine(wxWindow* parent, wxWindowID id, const wxColour& colour, const wxPoint& position = wxDefaultPosition, const wxSize& size = wxDefaultSize) : wxPanel(parent, id, position, size) {
      this->SetColour(colour);
    }
    
    void SetColour(const wxColour& colour) {this->SetBackgroundColour(colour);}
    const wxColour& GetColour() const {return this->GetBackgroundColour();}
  };
  
  class Form : public wxFrame {
  public:
    Form() : wxFrame(nullptr, wxID_ANY, "Lines example", wxDefaultPosition, wxSize(300, 300)) {
      this->SetClientSize(wxSize(300, 300));
    }
    
  private:
    wxPanel* panel = new wxPanel(this);
    wxStaticLine* lineSeparator1 = new wxStaticLine(this->panel, wxID_ANY, wxPoint(10, 10), wxSize(280, wxDefaultCoord), wxLI_HORIZONTAL);
    wxColouredLine* lineRed = new wxColouredLine(this->panel, wxID_ANY, wxColour(255, 0, 0), wxPoint(10, 20), wxSize(2, 250));
    wxColouredLine* lineGreen = new wxColouredLine(this->panel, wxID_ANY, wxColour(0, 143, 0), wxPoint(149, 20), wxSize(2, 250));
    wxColouredLine* lineBlue = new wxColouredLine(this->panel, wxID_ANY, wxColour(0, 0, 255), wxPoint(288, 20), wxSize(2, 250));
    wxColouredLine* lineSeparator2 = new wxColouredLine(this->panel, wxID_ANY, wxColour(96, 96, 96), wxPoint(10, 278), wxSize(280, 2));
  };
  
  class Application : public wxApp {
    bool OnInit() override {return (new Form())->Show();}
  };
}

wxIMPLEMENT_APP(Examples::Application);
