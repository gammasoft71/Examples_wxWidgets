#include <wx/app.h>
#include <wx/frame.h>
#include <wx/listbook.h>
#include <wx/panel.h>

namespace ListbookExample {
  class Frame : public wxFrame {
  public:
    Frame() : wxFrame {nullptr, wxID_ANY, "Listbook example"} {
      SetClientSize(390, 270);
      
      tabControl1->AddPage(tabPageRed, "Red");
      tabControl1->AddPage(tabPageGreen, "Green");
      tabControl1->AddPage(tabPageBlue, "Blue");
      tabControl1->AddPage(tabPageYellow, "Yellow");
      
      tabPageRed->SetBackgroundColour(wxTheColourDatabase->Find("Red"));
      tabPageGreen->SetBackgroundColour(wxTheColourDatabase->Find("Forest Green"));
      tabPageBlue->SetBackgroundColour(wxTheColourDatabase->Find("Blue"));
      tabPageYellow->SetBackgroundColour(wxTheColourDatabase->Find("Yellow"));
    }
    
  private:
    wxPanel* panel = new wxPanel {this};
    wxListbook* tabControl1 = new wxListbook {panel, wxID_ANY, {10, 10}, {370, 250}};
    wxNotebookPage* tabPageRed = new wxNotebookPage {tabControl1, wxID_ANY};
    wxNotebookPage* tabPageGreen = new wxNotebookPage {tabControl1, wxID_ANY};
    wxNotebookPage* tabPageBlue = new wxNotebookPage {tabControl1, wxID_ANY};
    wxNotebookPage* tabPageYellow = new wxNotebookPage {tabControl1, wxID_ANY};
  };

  class Application : public wxApp {
    bool OnInit() override {return (new Frame)->Show();}
  };
}

wxIMPLEMENT_APP(ListbookExample::Application);
