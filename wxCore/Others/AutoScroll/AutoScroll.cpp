#include <wx/app.h>
#include <wx/frame.h>
#include <wx/panel.h>
#include <wx/scrolwin.h>
#include <wx/sizer.h>

namespace AutoScrollExample {
  class Frame : public wxFrame {
  public:
    Frame() : wxFrame {nullptr, wxID_ANY, "AutoScroll example", wxDefaultPosition, {400, 250}} {
      panel1->SetBackgroundColour({0x90, 0xEE, 0x90, 0xFF});
      panel2->SetBackgroundColour({0xFF, 0xB6, 0xC1, 0xFF});
      panel3->SetBackgroundColour({0xAD, 0xD8, 0xE6, 0xFF});
      panel4->SetBackgroundColour({0xFF, 0xFF, 0xE0, 0xFF});
      panel5->SetBackgroundColour({0xFF, 0xA0, 0x7A, 0xFF});

      boxSizerMain->Add(panel1, 0, wxGROW);
      boxSizerMain->Add(panel2, 0, wxGROW);
      boxSizerMain->Add(panel3, 0, wxGROW);
      boxSizerMain->Add(panel4, 0, wxGROW);
      boxSizerMain->Add(panel5, 0, wxGROW);

      panelMain->SetScrollRate(10, 10);
      panelMain->SetSizerAndFit(boxSizerMain);
      panelMain->SetVirtualSize(boxSizerMain->GetSize());
    }
    
  private:
    wxScrolled<wxPanel>* panelMain = new wxScrolled<wxPanel> {this};
    wxBoxSizer* boxSizerMain = new wxBoxSizer {wxVERTICAL};
    wxPanel* panel1 = new wxPanel {panelMain, wxID_ANY, wxDefaultPosition, {100, 100}, wxTAB_TRAVERSAL|wxBORDER_SIMPLE};
    wxPanel* panel2 = new wxPanel {panelMain, wxID_ANY, wxDefaultPosition, {100, 100}, wxTAB_TRAVERSAL|wxBORDER_SIMPLE};
    wxPanel* panel3 = new wxPanel {panelMain, wxID_ANY, wxDefaultPosition, {100, 100}, wxTAB_TRAVERSAL|wxBORDER_SIMPLE};
    wxPanel* panel4 = new wxPanel {panelMain, wxID_ANY, wxDefaultPosition, {100, 100}, wxTAB_TRAVERSAL|wxBORDER_SIMPLE};
    wxPanel* panel5 = new wxPanel {panelMain, wxID_ANY, wxDefaultPosition, {100, 100}, wxTAB_TRAVERSAL|wxBORDER_SIMPLE};
  };

  class Application : public wxApp {
    bool OnInit() override {return (new Frame)->Show();}
  };
}

wxIMPLEMENT_APP(AutoScrollExample::Application);
