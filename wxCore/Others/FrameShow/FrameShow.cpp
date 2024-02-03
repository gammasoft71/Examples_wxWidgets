#include <wx/wx.h>
#include <wx/statline.h>

namespace FrameShowExample {
  class Window : public wxFrame {
  public:
    Window() : wxFrame(nullptr, wxID_ANY, "Frame show example") {
      SetClientSize(320, 400);
      Bind(wxEVT_CLOSE_WINDOW, [&](wxCloseEvent& event) {
        wxTheApp->Exit();
      });

      panel->SetSizerAndFit(boxSizer);
      panel->SetBackgroundColour(wxSystemSettings::GetColour(wxSystemColour::wxSYS_COLOUR_BTNFACE));

      boxSizer->Add(buttonNormal, 1, wxGROW|wxUP|wxRIGHT|wxLEFT, 5);
      boxSizer->Add(buttonModeless, 1, wxGROW|wxUP|wxRIGHT|wxLEFT, 5);
      boxSizer->Add(buttonStayOnTop, 1, wxGROW|wxUP|wxRIGHT|wxLEFT, 5);
      boxSizer->Add(buttonModal, 1, wxGROW|wxUP|wxDOWN|wxRIGHT|wxLEFT, 5);
      
      buttonNormal->Bind(wxEVT_BUTTON, [&](wxCommandEvent& event) {
        auto dialog = new wxFrame(nullptr, wxID_ANY, "dialog show normal", wxDefaultPosition, {250, 100});
        dialog->Show();
      });
      
      buttonModeless->Bind(wxEVT_BUTTON, [&](wxCommandEvent& event) {
        auto dialog = new wxFrame(this, wxID_ANY, "dialog show modeless", wxDefaultPosition, {250, 100}, wxDEFAULT_FRAME_STYLE|wxFRAME_FLOAT_ON_PARENT);
        dialog->Show();
      });
      
      buttonStayOnTop->Bind(wxEVT_BUTTON, [&](wxCommandEvent& event) {
        auto dialog = new wxFrame(nullptr, wxID_ANY, "dialog stay on top", wxDefaultPosition, {250, 100}, wxDEFAULT_FRAME_STYLE|wxSTAY_ON_TOP);
        dialog->Show();
      });

      buttonModal->Bind(wxEVT_BUTTON, [&](wxCommandEvent& event) {
        auto dialog = new wxDialog(this, wxID_ANY, "dialog show modal", wxDefaultPosition, {250, 100}, wxDEFAULT_FRAME_STYLE);
        dialog->ShowModal();
      });
    }
    
  private:
    wxPanel* panel = new wxPanel {this};
    wxBoxSizer* boxSizer = new wxBoxSizer(wxVERTICAL);
    wxButton* buttonNormal = new wxButton(panel, wxID_ANY, "Show normal", wxDefaultPosition, wxDefaultSize, wxBORDER_SIMPLE);
    wxButton* buttonModeless = new wxButton(panel, wxID_ANY, "Show modeless", wxDefaultPosition, wxDefaultSize, wxBORDER_SIMPLE);
    wxButton* buttonStayOnTop = new wxButton(panel, wxID_ANY, "Show stay on top", wxDefaultPosition, wxDefaultSize, wxBORDER_SIMPLE);
    wxButton* buttonModal = new wxButton(panel, wxID_ANY, "Show modal", wxDefaultPosition, wxDefaultSize, wxBORDER_SIMPLE);
  };
  
  class Application : public wxApp {
    bool OnInit() override {return (new Window())->Show();}
  };
}

wxIMPLEMENT_APP(FrameShowExample::Application);
