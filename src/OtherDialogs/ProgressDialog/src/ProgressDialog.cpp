#include <wx/wx.h>
#include <wx/progdlg.h>

class Form : public wxFrame {
public:
  Form() : wxFrame(nullptr, wxID_ANY, "ColorDialog example", wxDefaultPosition, wxSize(300, 300)) {
    buttonProcess->Bind(wxEVT_BUTTON, [this](wxCommandEvent& event) {
      wxProgressDialog* progressDialog = new wxProgressDialog("Process running", "Please wait...", 20, this, wxPD_APP_MODAL | wxPD_AUTO_HIDE);
      for (int i = 0; i <= progressDialog->GetRange(); i++) {
        progressDialog->Update(i);
        wxMicroSleep(100000);
      }
      progressDialog->Destroy();
    });

    buttonIndeterminateProcess->Bind(wxEVT_BUTTON, [this](wxCommandEvent& event) {
      wxProgressDialog* progressDialog = new wxProgressDialog("Indeterminate process running", "Click \“Cancel\" to abort", 10, this, wxPD_APP_MODAL | wxPD_AUTO_HIDE  | wxPD_CAN_ABORT);
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
  wxButton* buttonProcess = new wxButton(panel, wxID_ANY, "Process", wxPoint(10, 10));
  wxButton* buttonIndeterminateProcess = new wxButton(panel, wxID_ANY, "Indeterminate Process", wxPoint(100, 10));
};

class Application : public wxApp {
  bool OnInit() override {(new Form())->Show(); return true;}
};

wxIMPLEMENT_APP(Application);
