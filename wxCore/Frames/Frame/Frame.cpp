#include <wx/wx.h>

namespace FrameExample {
  class Frame : public wxFrame {
  public:
    Frame() : wxFrame(nullptr, wxID_ANY, "Window example", wxDefaultPosition, {640, 480}) {
      buttonClose->Bind(wxEVT_BUTTON, [&](wxCommandEvent& event) {
        Close();
      });

      buttonExit->Bind(wxEVT_BUTTON, [&](wxCommandEvent& event) {
        wxTheApp->Exit();
      });
      
      buttonExitMainLoop->Bind(wxEVT_BUTTON, [&](wxCommandEvent& event) {
        wxTheApp->ExitMainLoop();
      });

      Bind(wxEVT_CLOSE_WINDOW, [&](wxCloseEvent& event) {
        if (wxMessageBox("Are you sure you want exit?", "Close Window", wxICON_QUESTION|wxYES_NO) != wxYES) event.Veto();
        else event.Skip();
      });
    }

  private:
    wxPanel* panel = new wxPanel(this);
    wxButton* buttonClose = new wxButton(panel, wxID_ANY, "Close", {10, 10});
    wxButton* buttonExit = new wxButton(panel, wxID_ANY, "Exit", {100, 10});
    wxButton* buttonExitMainLoop = new wxButton(panel, wxID_ANY, "ExitMainLoop", {190, 10});
  };

  class Application : public wxApp {
    bool OnInit() override {
      (new Frame())->Show();
      return true;
    }
  };
}

wxIMPLEMENT_APP(FrameExample::Application);
