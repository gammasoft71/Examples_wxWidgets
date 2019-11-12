#include <wx/app.h>
#include <wx/frame.h>
#include <wx/panel.h>
#include <wx/stattext.h>
#include <wx/spinbutt.h>

class Form : public wxFrame {
public:
  Form() : wxFrame(nullptr, wxID_ANY, "NumericUpDown example", wxDefaultPosition, wxSize(300, 300)) {
    spinButton1->SetRange(0, 100);
    spinButton1->SetValue(50);
    spinButton1->Bind(wxEVT_SPIN, [this](wxCommandEvent& event) {
      staticText1->SetLabel(wxString::Format("value = %d", spinButton1->GetValue()));
    });

    staticText1->SetLabel(wxString::Format("value = %d", spinButton1->GetValue()));
    
    wxMessageOutputDebug().Printf("size = {%d, %d}", spinButton1->GetSize().GetWidth(), spinButton1->GetSize().GetHeight());
  }
  
private:
  wxPanel* panel = new wxPanel(this);
  wxSpinButton* spinButton1 = new wxSpinButton(panel, wxID_ANY, wxPoint(10, 10), wxSize(18, 34));
  wxStaticText* staticText1 = new wxStaticText(panel, wxID_ANY, wxEmptyString, wxPoint(10, 50));
};

class Application : public wxApp {
  bool OnInit() override {(new Form())->Show(); return true;}
};

wxIMPLEMENT_APP(Application);
