#include <wx/app.h>
#include <wx/button.h>
#include <wx/frame.h>
#include <wx/panel.h>
#include <wx/progdlg.h>

namespace ProgressDialogExample {
  class Frame : public wxFrame {
  public:
    Frame() : wxFrame {nullptr, wxID_ANY, "ProgressDialog example"} {
      buttonProcess->Bind(wxEVT_BUTTON, [&](wxCommandEvent& event) {
        auto progressDialog = wxProgressDialog {"Process running", "Please wait...", 100, this, wxPD_APP_MODAL|wxPD_AUTO_HIDE|wxPD_CAN_SKIP|wxPD_REMAINING_TIME};
        for (auto step = 1; step <= progressDialog.GetRange(); ++step) {
          progressDialog.Update(step, wxString::Format("Step %d/%d ==> %s", step, progressDialog.GetRange(), progressDialog.WasSkipped() ? "skipped" : "done"));
          wxMilliSleep(100);
        }
      });

      buttonIndeterminateProcess->Bind(wxEVT_BUTTON, [&](wxCommandEvent& event) {
        auto progressDialog = wxProgressDialog {"Indeterminate process running", "Click \"Cancel\" to abort", 10, this, wxPD_APP_MODAL|wxPD_CAN_ABORT|wxPD_ELAPSED_TIME};
        while(!progressDialog.WasCancelled()) {
          progressDialog.Pulse();
          wxMilliSleep(100);
        }
      });
    }

  private:
    wxPanel* panel = new wxPanel {this};
    wxButton* buttonProcess = new wxButton {panel, wxID_ANY, "Process", {10, 10}};
    wxButton* buttonIndeterminateProcess = new wxButton {panel, wxID_ANY, "Indeterminate Process", {100, 10}};
  };

  class Application : public wxApp {
    bool OnInit() override {return (new Frame)->Show();}
  };
}

wxIMPLEMENT_APP(ProgressDialogExample::Application);
