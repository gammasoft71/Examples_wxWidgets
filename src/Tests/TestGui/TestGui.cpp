#include "Application.h"
#include <wx/wx.h>
#include <wx/display.h>
#include <wx/log.h>
#include <wx/msgout.h>

class Frame1 : public wxFrame {
public:
  Frame1() : wxFrame {nullptr, wxID_ANY, wxEmptyString} {
    Bind(wxEVT_CLOSE_WINDOW, [&](wxCloseEvent& e) {
      wxTheApp->Exit();
    });

    closeButton->Bind(wxEVT_BUTTON, [&](wxCommandEvent&) {
      if (frame2 != nullptr) frame2->Close();
    });
    
    showButton->Bind(wxEVT_BUTTON, [&](wxCommandEvent&) {
      CreateFrame2();
      frame2->Show();
    });
    
    hideButton->Bind(wxEVT_BUTTON, [&](wxCommandEvent&) {
      CreateFrame2();
      frame2->Hide();
    });
    
    CreateFrame2();
  }

private:
  void CreateFrame2() {
    if (frame2 == nullptr) {
      frame2 = new wxFrame(nullptr, wxID_ANY, wxString::Format("CloseCount = %d", closeCount));
      
      frame2->Bind(wxEVT_CLOSE_WINDOW, [&](wxCloseEvent& e) {
        if (cancelCloseButton->IsChecked()) {
          e.SetCanVeto(true);
          e.Veto();
        } else {
          closeCount++;
          frame2 = nullptr;
          e.Skip();
        }
      });
    }
  }
  wxPanel* panel = new wxPanel(this);
  wxButton* closeButton = new wxButton(panel, wxID_ANY, "Close", {10, 10}, {100, 40});
  wxButton* showButton = new wxButton(panel, wxID_ANY, "Show", {10, 60}, {100, 40});
  wxButton* hideButton = new wxButton(panel, wxID_ANY, "Hide", {10, 110}, {100, 40});
  wxCheckBox* cancelCloseButton = new wxCheckBox(panel, wxID_ANY, "Cancel close", {10, 160}, {100, 40});
  wxFrame* frame2 = nullptr;
  int closeCount = 0;
};

class Application : public wxApp {
  bool OnInit() override {
    auto frame1 = new Frame1();
    frame1->Show();
    wxTheApp->SetTopWindow(frame1);

    return true;
  }
};

wxIMPLEMENT_APP(Application);
