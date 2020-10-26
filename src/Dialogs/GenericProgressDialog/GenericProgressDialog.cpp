#include <thread>
#include <wx/wx.h>
#include <wx/progdlg.h>

using namespace std;
using namespace std::literals;

namespace Examples {
  class Frame : public wxFrame {
  public:
    Frame() : wxFrame(nullptr, wxID_ANY, "GenericProgressDialog example", wxDefaultPosition, {300, 300}) {
      buttonProcess->Bind(wxEVT_BUTTON, [&](wxCommandEvent& event) {
        wxGenericProgressDialog* progressDialog = new wxGenericProgressDialog("Process running", "Please wait...", 100, this, wxPD_APP_MODAL|wxPD_AUTO_HIDE|wxPD_CAN_ABORT);
        for (auto step = 1; step <= progressDialog->GetRange(); step++) {
          if (!progressDialog->Update(step, wxString::Format("Step %d/100", step))) break;
          this_thread::sleep_for(100ms);
        }
        progressDialog->Destroy();
      });

      buttonIndeterminateProcess->Bind(wxEVT_BUTTON, [&](wxCommandEvent& event) {
        wxProgressDialog* progressDialog = new wxProgressDialog("Indeterminate process running", "Click \"Cancel\" to abort", 10, this, wxPD_APP_MODAL|wxPD_AUTO_HIDE|wxPD_CAN_ABORT);
        while(true) {
          if (!progressDialog->Pulse()) break;
          this_thread::sleep_for(100ms);
        }
        progressDialog->Destroy();
      });
    }

  private:
    wxPanel* panel = new wxPanel(this);
    wxButton* buttonProcess = new wxButton(panel, wxID_ANY, "Process", {10, 10});
    wxButton* buttonIndeterminateProcess = new wxButton(panel, wxID_ANY, "Indeterminate Process", {100, 10});
  };

  class Application : public wxApp {
    bool OnInit() override {
      (new Frame())->Show();
      return true;
    }
  };
}

wxIMPLEMENT_APP(Examples::Application);
