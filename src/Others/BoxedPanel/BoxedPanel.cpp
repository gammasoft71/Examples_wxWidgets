#include <wx/wx.h>

namespace Examples {
  class Window : public wxFrame {
  public:
    Window() : wxFrame(nullptr, wxID_ANY, "Boxed example") {
      SetClientSize(300, 300);
      
      panel5->SetBackgroundColour({0xFF, 0xA0, 0x7A, 0xFF});
      panel4->SetBackgroundColour({0xFF, 0xB6, 0xC1, 0xFF});
      panel3->SetBackgroundColour({0xAD, 0xD8, 0xE6, 0xFF});
      panel2->SetBackgroundColour({0x90, 0xEE, 0x90, 0xFF});
      panel1->SetBackgroundColour({0xFF, 0xFF, 0xE0, 0xFF});

      boxSizerVerticalOne->Add(boxSizerHorizontalOne, 1, wxGROW);
      boxSizerVerticalOne->Add(panel5, 0, wxGROW);

      boxSizerHorizontalOne->Add(panel4, 0, wxGROW);
      boxSizerHorizontalOne->Add(boxSizerVerticalTwo, 1, wxGROW);

      boxSizerVerticalTwo->Add(panel3, 0, wxGROW);
      boxSizerVerticalTwo->Add(boxSizerHorizontalTwo, 1, wxGROW);

      boxSizerHorizontalTwo->Add(panel2, 1, wxGROW);
      boxSizerHorizontalTwo->Add(panel1, 0, wxGROW);

      panelMain->SetSizerAndFit(boxSizerVerticalOne);
      panelMain->Layout();
    }
    
  private:
    wxPanel* panelMain = new wxPanel(this);
    wxBoxSizer* boxSizerVerticalOne = new wxBoxSizer(wxVERTICAL);
    wxBoxSizer* boxSizerHorizontalOne = new wxBoxSizer(wxHORIZONTAL);
    wxBoxSizer* boxSizerVerticalTwo = new wxBoxSizer(wxVERTICAL);
    wxBoxSizer* boxSizerHorizontalTwo = new wxBoxSizer(wxHORIZONTAL);

    wxPanel* panel1 = new wxPanel(panelMain, wxID_ANY, wxDefaultPosition, {100, 100}, wxTAB_TRAVERSAL|wxBORDER_SIMPLE);
    wxPanel* panel2 = new wxPanel(panelMain, wxID_ANY, wxDefaultPosition, {100, 100}, wxTAB_TRAVERSAL|wxBORDER_SIMPLE);
    wxPanel* panel3 = new wxPanel(panelMain, wxID_ANY, wxDefaultPosition, {100, 100}, wxTAB_TRAVERSAL|wxBORDER_SIMPLE);
    wxPanel* panel4 = new wxPanel(panelMain, wxID_ANY, wxDefaultPosition, {100, 100}, wxTAB_TRAVERSAL|wxBORDER_SIMPLE);
    wxPanel* panel5 = new wxPanel(panelMain, wxID_ANY, wxDefaultPosition, {100, 100}, wxTAB_TRAVERSAL|wxBORDER_SIMPLE);
  };

  class Application : public wxApp {
    bool OnInit() override {
      (new Window())->Show();
      return true;
    }
  };
}

wxIMPLEMENT_APP(Examples::Application);
