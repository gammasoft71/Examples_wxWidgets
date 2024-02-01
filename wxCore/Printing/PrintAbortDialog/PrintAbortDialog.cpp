#include <thread>
#include <wx/wx.h>
#include <wx/print.h>
#include <wx/richtext/richtextprint.h>

using namespace std;
using namespace std::literals;

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
          this_thread::sleep_for(200ms);
        }
        dialog->Hide();
      });
    }

  private:
    wxPrintAbortDialog* dialog = new wxPrintAbortDialog(this, "My document");
    wxPanel* panel = new wxPanel(this);
    wxButton* button = new wxButton(panel, wxID_ANY, "Print abort...", {10, 10});
  };

  class Application : public wxApp {
    bool OnInit() override {
      (new Frame)->Show();
      return true;
    }
  };
}

wxIMPLEMENT_APP(PrintAbortDialogExample::Application);
