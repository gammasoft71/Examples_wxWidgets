#include <wx/app.h>
#include <wx/button.h>
#include <wx/frame.h>
#include <wx/panel.h>
#include <wx/print.h>

namespace PrintAbortDialogExample {
  class Frame : public wxFrame {
  public:
    Frame() : wxFrame {nullptr, wxID_ANY, "PrintAbortDialog example"} {
      button->Bind(wxEVT_BUTTON, [&](wxCommandEvent& event) {
        dialog->Show();
        wxYield();
        for (auto step = 0; step <= 10; step++) {
          dialog->SetProgress(step, 10, 1, 1);
          wxMilliSleep(200);
          wxYield();
        }
        dialog->Hide();
      });
    }

  private:
    wxPanel* panel = new wxPanel {this};
    wxButton* button = new wxButton {panel, wxID_ANY, "Print abort...", {10, 10}};
    wxPrintAbortDialog* dialog = new wxPrintAbortDialog {this, "My document"};
  };

  class Application : public wxApp {
    bool OnInit() override {return (new Frame)->Show();}
  };
}

wxIMPLEMENT_APP(PrintAbortDialogExample::Application);
