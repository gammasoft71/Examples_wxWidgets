#include <wx/wx.h>
#include <wx/notebook.h>

namespace Examples {
  class Frame : public wxFrame {
  public:
    Frame() : wxFrame(nullptr, wxID_ANY, "Colored TabPages example") {
      SetClientSize(390, 270);
      
      tabControl1->AddPage(tabPageLightPink, "Red");
      tabPageLightPink->SetBackgroundColour(wxTheColourDatabase->Find("Red"));

      tabControl1->AddPage(tabPageLightGreen, "Green");
      tabPageLightGreen->SetBackgroundColour(wxTheColourDatabase->Find("Forest Green"));

      tabControl1->AddPage(tabPageLightBlue, "Blue");
      tabPageLightBlue->SetBackgroundColour(wxTheColourDatabase->Find("Blue"));

      tabControl1->AddPage(tabPageLightYellow, "Yellow");
      tabPageLightYellow->SetBackgroundColour(wxTheColourDatabase->Find("Yellow"));
    }

  private:
    wxPanel* panel = new wxPanel(this);
    wxNotebook* tabControl1 = new wxNotebook(panel, wxID_ANY, {10, 10}, {370, 250}, wxNB_BOTTOM);
    wxNotebookPage* tabPageLightPink = new wxNotebookPage(tabControl1, wxID_ANY);
    wxNotebookPage* tabPageLightGreen = new wxNotebookPage(tabControl1, wxID_ANY);
    wxNotebookPage* tabPageLightBlue = new wxNotebookPage(tabControl1, wxID_ANY);
    wxNotebookPage* tabPageLightYellow = new wxNotebookPage(tabControl1, wxID_ANY);
  };

  class Application : public wxApp {
    bool OnInit() override {
      (new Frame())->Show();
      return true;
    }
  };
}

wxIMPLEMENT_APP(Examples::Application);
