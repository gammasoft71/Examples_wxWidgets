#include <wx/wx.h>
#include <wx/splitter.h>
#include <wx/aui/framemanager.h>
#include <wx/aui/auibook.h>

namespace AuiNotebookExample {
  class Frame : public wxFrame {
  public:
    Frame() : wxFrame(nullptr, wxID_ANY, "AuiNotebook example") {
      SetClientSize(800, 450);
      
      panelRed->SetBackgroundColour({255, 0, 0});
      panelGreen->SetBackgroundColour({0, 128, 0});
      panelBlue->SetBackgroundColour({0, 0, 255});
      panelYellow->SetBackgroundColour({255, 255, 0});

      auiNotebook1->AddPage(panelRed, "Red");
      auiNotebook1->AddPage(panelGreen, "Green");
      auiNotebook1->AddPage(panelBlue, "Blue");
      auiNotebook1->AddPage(panelYellow, "Yellow");
    }
    
  private:
    wxAuiNotebook* auiNotebook1 = new wxAuiNotebook(this, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxAUI_NB_TOP|wxAUI_NB_TAB_SPLIT|wxAUI_NB_TAB_MOVE|wxAUI_NB_SCROLL_BUTTONS|wxAUI_NB_CLOSE_ON_ACTIVE_TAB|wxAUI_NB_MIDDLE_CLICK_CLOSE);
    wxPanel* panelRed = new wxPanel(this);
    wxPanel* panelGreen = new wxPanel(this);
    wxPanel* panelBlue = new wxPanel(this);
    wxPanel* panelYellow = new wxPanel(this);
  };

  class Application : public wxApp {
    bool OnInit() override {
      (new Frame)->Show();
      return true;
    }
  };
}

wxIMPLEMENT_APP(AuiNotebookExample::Application);
