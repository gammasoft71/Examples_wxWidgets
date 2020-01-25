#include <wx/wx.h>
#include <wx/progdlg.h>

class Frame : public wxFrame {
public:
  Frame() : wxFrame(nullptr, wxID_ANY, "ProgressDialog example", wxDefaultPosition, {300, 300}) {
    buttonProcess->Bind(wxEVT_BUTTON, [&](wxCommandEvent& event) {
      wxProgressDialog* progressDialog = new wxProgressDialog("Process running", "Please wait...", 100, this, wxPD_APP_MODAL | wxPD_AUTO_HIDE);
      for (int step = 1; step <= progressDialog->GetRange(); step++) {
        progressDialog->Update(step, wxString::Format("Step %d/100", step));
        wxMicroSleep(100000);
      }
      progressDialog->Destroy();
    });

    buttonIndeterminateProcess->Bind(wxEVT_BUTTON, [&](wxCommandEvent& event) {
      wxProgressDialog* progressDialog = new wxProgressDialog("Indeterminate process running", "Click \"Cancel\" to abort", 10, this, wxPD_APP_MODAL | wxPD_AUTO_HIDE  | wxPD_CAN_ABORT);
      while(true) {
        if (!progressDialog->Pulse())
          break;
        wxMicroSleep(100000);
      }
      progressDialog->Destroy();
    });
  }

private:
  wxPanel* panel = new wxPanel(this);
  wxButton* buttonProcess = new wxButton(panel, wxID_ANY, "Process", {10, 10});
  wxButton* buttonIndeterminateProcess = new wxButton(panel, wxID_ANY, "Indeterminate Process", wxPoint(100, 10));
};

class Application : public wxApp {
  bool OnInit() override {(new Frame())->Show(); return true;}
};

wxIMPLEMENT_APP(Application);
