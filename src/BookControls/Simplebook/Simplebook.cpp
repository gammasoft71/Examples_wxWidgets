#include <wx/wx.h>
#include <wx/simplebook.h>

namespace Examples {
  class Frame : public wxFrame {
  public:
    Frame() : wxFrame(nullptr, wxID_ANY, "Simplebook example") {
      SetClientSize(390, 305);
      
      tabControl1->AddPage(tabPageRed, "Red");
      tabControl1->AddPage(tabPageGreen, "Green");
      tabControl1->AddPage(tabPageBlue, "Blue");
      tabControl1->AddPage(tabPageYellow, "Yellow");
      
      tabPageRed->SetBackgroundColour(wxTheColourDatabase->Find("Red"));
      tabPageGreen->SetBackgroundColour(wxTheColourDatabase->Find("Forest Green"));
      tabPageBlue->SetBackgroundColour(wxTheColourDatabase->Find("Blue"));
      tabPageYellow->SetBackgroundColour(wxTheColourDatabase->Find("Yellow"));
      
      buttonPrev->Enable(tabControl1->GetSelection() > 0);
      buttonPrev->Bind(wxEVT_BUTTON, [&](wxCommandEvent& event) {
        tabControl1->SetSelection(tabControl1->GetSelection() - 1);
        buttonPrev->Enable(tabControl1->GetSelection() > 0);
        buttonNext->Enable(tabControl1->GetSelection() < tabControl1->GetPageCount() - 1);
      });

      buttonNext->Enable(tabControl1->GetSelection() < tabControl1->GetPageCount() - 1);
      buttonNext->Bind(wxEVT_BUTTON, [&](wxCommandEvent& event) {
        tabControl1->SetSelection(tabControl1->GetSelection() + 1);
        buttonPrev->Enable(tabControl1->GetSelection() > 0);
        buttonNext->Enable(tabControl1->GetSelection() < tabControl1->GetPageCount() - 1);
      });
    }
    
  private:
    wxPanel* panel = new wxPanel(this);
    wxSimplebook* tabControl1 = new wxSimplebook(panel, wxID_ANY, {10, 10}, {370, 250});
    wxNotebookPage* tabPageRed = new wxNotebookPage(tabControl1, wxID_ANY);
    wxNotebookPage* tabPageGreen = new wxNotebookPage(tabControl1, wxID_ANY);
    wxNotebookPage* tabPageBlue = new wxNotebookPage(tabControl1, wxID_ANY);
    wxNotebookPage* tabPageYellow = new wxNotebookPage(tabControl1, wxID_ANY);
    wxButton* buttonPrev = new wxButton(panel, wxID_ANY, "<", {10, 270}, {75, 25});
    wxButton* buttonNext = new wxButton(panel, wxID_ANY, ">", {305, 270}, {75, 25});
  };

  class Application : public wxApp {
    bool OnInit() override {
      (new Frame())->Show();
      return true;
    }
  };
}

wxIMPLEMENT_APP(Examples::Application);
