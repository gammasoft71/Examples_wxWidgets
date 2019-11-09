#include <wx/wx.h>

namespace Examples {
  class Form : public wxFrame {
  public:
    Form() : wxFrame(nullptr, wxID_ANY, "AutoScroll example", wxDefaultPosition, {400, 250}) {
      panel1->SetBackgroundColour(wxColour(0x90, 0xEE, 0x90, 0xFF));
      panel2->SetBackgroundColour(wxColour(0xFF, 0xB6, 0xC1, 0xFF));
      panel3->SetBackgroundColour(wxColour(0xAD, 0xD8, 0xE6, 0xFF));
      panel4->SetBackgroundColour(wxColour(0xFF, 0xFF, 0xE0, 0xFF));
      panel5->SetBackgroundColour(wxColour(0xFF, 0xA0, 0x7A, 0xFF));

      boxSizerMain->Add(panel1, 0, wxALL | wxEXPAND);
      boxSizerMain->Add(panel2, 0, wxALL | wxEXPAND);
      boxSizerMain->Add(panel3, 0, wxALL | wxEXPAND);
      boxSizerMain->Add(panel4, 0, wxALL | wxEXPAND);
      boxSizerMain->Add(panel5, 0, wxALL | wxEXPAND);

      panelMain->SetScrollRate(10, 10);
      panelMain->SetSizerAndFit(boxSizerMain);
      panelMain->SetVirtualSize(boxSizerMain->GetSize());
    }
    
  private:
    wxScrolled<wxPanel>* panelMain = new wxScrolled<wxPanel>(this);
    wxBoxSizer* boxSizerMain = new wxBoxSizer(wxVERTICAL);
    wxPanel* panel1 = new wxPanel(panelMain, wxID_ANY, wxDefaultPosition, wxSize(400, 100), wxTAB_TRAVERSAL | wxBORDER_SIMPLE);
    wxPanel* panel2 = new wxPanel(panelMain, wxID_ANY, wxDefaultPosition, wxSize(400, 100), wxTAB_TRAVERSAL | wxBORDER_SIMPLE);
    wxPanel* panel3 = new wxPanel(panelMain, wxID_ANY, wxDefaultPosition, wxSize(400, 100), wxTAB_TRAVERSAL | wxBORDER_SIMPLE);
    wxPanel* panel4 = new wxPanel(panelMain, wxID_ANY, wxDefaultPosition, wxSize(400, 100), wxTAB_TRAVERSAL | wxBORDER_SIMPLE);
    wxPanel* panel5 = new wxPanel(panelMain, wxID_ANY, wxDefaultPosition, wxSize(400, 100), wxTAB_TRAVERSAL | wxBORDER_SIMPLE);
  };

  class Application : public wxApp {
    bool OnInit() override {(new Form())->Show(); return true;}
  };
}

wxIMPLEMENT_APP(Examples::Application);
