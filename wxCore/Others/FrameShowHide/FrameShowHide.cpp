#include <wx/app.h>
#include <wx/button.h>
#include <wx/checkbox.h>
#include <wx/frame.h>
#include <wx/panel.h>

class Frame1 : public wxFrame {
public:
  Frame1() : wxFrame {nullptr, wxID_ANY, "Frame show and hide example"} {
    SetClientSize(320, 325);
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
      frame2->SetClientSize(300, 100);
      frame2->Bind(wxEVT_CLOSE_WINDOW, [&](wxCloseEvent& e) {
        e.Skip(!cancelCloseButton->IsChecked());
        if (!cancelCloseButton->IsChecked()) {
          closeCount++;
          frame2 = nullptr;
        }
      });
    }
  }
  
  wxPanel* panel = new wxPanel(this);
  wxButton* closeButton = new wxButton(panel, wxID_ANY, "Close", {10, 10}, {100, 40});
  wxButton* showButton = new wxButton(panel, wxID_ANY, "Show", {10, 60}, {100, 40});
  wxButton* hideButton = new wxButton(panel, wxID_ANY, "Hide", {10, 110}, {100, 40});
  wxCheckBox* cancelCloseButton = new wxCheckBox(panel, wxID_ANY, "cancel close", {10, 160}, {100, 40});
  wxFrame* frame2 = nullptr;
  int closeCount = 0;
};

class Application : public wxApp {
  bool OnInit() override {
    (new Frame1())->Show();
    return true;
  }
};

wxIMPLEMENT_APP(Application);
