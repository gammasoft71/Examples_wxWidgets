#include <wx/wx.h>
#include <wx/choicebk.h>

namespace ChoicebookExample {
  class Frame : public wxFrame {
  public:
    Frame() : wxFrame(nullptr, wxID_ANY, "Choicebook example") {
      SetClientSize(390, 270);
      
      tabControl1->AddPage(tabpageRed, "Red page");
      tabControl1->AddPage(tabpageGreen, "Green page");
      tabControl1->AddPage(tabpageBlue, "Blue page");
      tabControl1->AddPage(tabpageYellow, "Yellow page");
      
      tabpageRed->SetBackgroundColour({255, 0, 0});
      tabpageGreen->SetBackgroundColour({0, 128, 0});
      tabpageBlue->SetBackgroundColour({0, 0, 255});
      tabpageYellow->SetBackgroundColour({255, 255, 0});
    }

  private:
    wxPanel* panel = new wxPanel {this};
    wxChoicebook* tabControl1 = new wxChoicebook(panel, wxID_ANY, {10, 10}, {370, 250});
    wxNotebookPage* tabpageRed = new wxNotebookPage(tabControl1, wxID_ANY);
    wxNotebookPage* tabpageGreen = new wxNotebookPage(tabControl1, wxID_ANY);
    wxNotebookPage* tabpageBlue = new wxNotebookPage(tabControl1, wxID_ANY);
    wxNotebookPage* tabpageYellow = new wxNotebookPage(tabControl1, wxID_ANY);
  };

  class Application : public wxApp {
    bool OnInit() override {return (new Frame)->Show();}
  };
}

wxIMPLEMENT_APP(ChoicebookExample::Application);
