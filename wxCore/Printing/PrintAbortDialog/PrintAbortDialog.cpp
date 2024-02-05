#include <wx/wx.h>
#include <wx/print.h>
#include <wx/richtext/richtextprint.h>

namespace PrintAbortDialogExample {
  class Frame : public wxFrame {
  public:
    Frame() : wxFrame(nullptr, wxID_ANY, "PrintAbortDialog example") {
      button->Bind(wxEVT_BUTTON, [&](wxCommandEvent& event) {
        dialog->Show();
        wxYield();
        for (auto step = 0; step <= 10; step++) {
          dialog->SetProgress(step, 10, 1, 1);
          wxYield();
          wxMilliSleep(200);
        }
        dialog->Hide();
      });
    }

  private:
    wxPrintAbortDialog* dialog = new wxPrintAbortDialog(this, "My document");
    wxPanel* panel = new wxPanel {this};
    wxButton* button = new wxButton(panel, wxID_ANY, "Print abort...", {10, 10});
  };

  class Application : public wxApp {
    bool OnInit() override {return (new Frame)->Show();}
  };
}

wxIMPLEMENT_APP(PrintAbortDialogExample::Application);
