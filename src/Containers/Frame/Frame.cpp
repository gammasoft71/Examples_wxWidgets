#include <wx/wx.h>

namespace Examples {
  class Frame : public wxFrame {
  public:
    Frame() : wxFrame(nullptr, wxID_ANY, "Window example", wxDefaultPosition, {640, 480}) {
      buttonClose->Bind(wxEVT_BUTTON, [&](wxCommandEvent& event) {
        Close();
      });
      
      buttonExit->Bind(wxEVT_BUTTON, [&](wxCommandEvent& event) {
        wxTheApp->Exit();
      });
      
      Bind(wxEVT_CLOSE_WINDOW, [&](wxCloseEvent& event) {
        bool can_close = wxMessageBox("Are you sure you want exit?", "Close Window", wxICON_QUESTION|wxYES_NO) == wxYES;
        event.Veto(!can_close);
        event.Skip(can_close);
      });
    }

  private:
    wxPanel* panel = new wxPanel(this);
    wxButton* buttonClose = new wxButton(panel, wxID_ANY, "Close", {10, 10});
    wxButton* buttonExit = new wxButton(panel, wxID_ANY, "Exit", {100, 10});
  };

  class Application : public wxApp {
    bool OnInit() override {
      (new Frame())->Show();
      return true;
    }
  };
}

wxIMPLEMENT_APP(Examples::Application);
