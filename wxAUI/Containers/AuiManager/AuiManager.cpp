#include <wx/wx.h>
#include <wx/splitter.h>
#include <wx/aui/framemanager.h>
#include <wx/aui/auibar.h>
#include <wx/aui/dockart.h>

namespace AuiManagerExample {
  class Frame : public wxFrame {
  public:
    Frame() : wxFrame(nullptr, wxID_ANY, "AuiManager example") {
      SetClientSize(800, 450);
      
      auto artProvider = auiManager->GetArtProvider();
      artProvider->SetMetric(wxAUI_DOCKART_SASH_SIZE, 4);

      panel1->SetBackgroundColour({255, 0, 0});
      panel2->SetBackgroundColour({0, 128, 0});
      panel3->SetBackgroundColour({0, 0, 255});
      panel4->SetBackgroundColour({255, 255, 0});

      auiManager->AddPane(panel1, wxAuiPaneInfo().Center().Caption("Red").CaptionVisible(false).CloseButton(false));
      auiManager->AddPane(panel2, wxAuiPaneInfo().Top().Caption("Green").CloseButton(false));
      auiManager->AddPane(panel3, wxAuiPaneInfo().Left().Caption("Blue").CloseButton(false).PinButton());
      auiManager->AddPane(panel4, wxAuiPaneInfo().Float().Caption("Yellow").FloatingPosition({400, 300}).FloatingSize({300, 200}).CloseButton(false).MaximizeButton().MinimizeButton());
      auiManager->Update();
    }
    
  private:
    wxPanel* panel1 = new wxPanel(this, wxID_ANY, wxDefaultPosition, {100, 100});
    wxPanel* panel2 = new wxPanel(this, wxID_ANY, wxDefaultPosition, {100, 100});
    wxPanel* panel3 = new wxPanel(this, wxID_ANY, wxDefaultPosition, {100, 100});
    wxPanel* panel4 = new wxPanel(this, wxID_ANY, wxDefaultPosition, {100, 100});
    wxAuiManager* auiManager = new wxAuiManager(this, wxAUI_MGR_DEFAULT);
  };

  class Application : public wxApp {
    bool OnInit() override {return (new Frame)->Show();}
  };
}

wxIMPLEMENT_APP(AuiManagerExample::Application);
