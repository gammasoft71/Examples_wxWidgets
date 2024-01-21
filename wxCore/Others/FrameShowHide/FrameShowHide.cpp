#include <wx/app.h>
#include <wx/button.h>
#include <wx/checkbox.h>
#include <wx/frame.h>
#include <wx/panel.h>

class Frame1 : public wxFrame {
public:
  Frame1() : wxFrame {nullptr, wxID_ANY, "Frame show and hide example"} {
    SetClientSize(320, 325);
    Bind(wxEVT_CLOSE_WINDOW, [&](auto& e) {wxTheApp->Exit();});
    
    closeButton->Bind(wxEVT_BUTTON, [&](auto&) {frame2->Close();});
    showButton->Bind(wxEVT_BUTTON, [&](auto&) {frame2->Show();});
    hideButton->Bind(wxEVT_BUTTON, [&](auto&) {frame2->Hide();});
    
    CreateFrame2();
  }
  
private:
  void CreateFrame2() {
    static auto closeCount = -1;
    frame2 = new wxFrame {nullptr, wxID_ANY, wxString::Format("Close count = %d", ++closeCount)};
    frame2->SetClientSize(300, 100);
    frame2->Bind(wxEVT_CLOSE_WINDOW, [&](auto& e) {
      e.Skip(!cancelCloseButton->IsChecked());
      if (!cancelCloseButton->IsChecked()) CreateFrame2();
    });
  }

  wxPanel* panel = new wxPanel(this);
  wxButton* closeButton = new wxButton(panel, wxID_ANY, "Close", {10, 10}, {100, 40});
  wxButton* showButton = new wxButton(panel, wxID_ANY, "Show", {10, 60}, {100, 40});
  wxButton* hideButton = new wxButton(panel, wxID_ANY, "Hide", {10, 110}, {100, 40});
  wxCheckBox* cancelCloseButton = new wxCheckBox(panel, wxID_ANY, "cancel close", {10, 160}, {100, 40});
  wxFrame* frame2 = nullptr;
};

class Application : public wxApp {
  bool OnInit() override {
    (new Frame1 {})->Show();
    return true;
  }
};

wxIMPLEMENT_APP(Application);
