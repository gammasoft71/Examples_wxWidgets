#include <wx/app.h>
#include <wx/button.h>
#include <wx/frame.h>
#include <wx/msgdlg.h>
#include <wx/panel.h>
#include <wx/stattext.h>

namespace MessageDialogExample {
  class Frame : public wxFrame {
  public:
    Frame() : wxFrame(nullptr, wxID_ANY, "MessageDialog example") {
      buttonShowMessage->Bind(wxEVT_BUTTON, [&](wxCommandEvent& event) {
        labelDialogResult->SetLabelText("Result = ");
        auto messageDialog = wxMessageDialog {this, "Hello, World!", "Message", wxOK|wxCANCEL};
        labelDialogResult->SetLabelText(wxString::Format("Result = %s", messageDialog.ShowModal() == wxID_OK ? "wxOK" : "wxCANCEL"));
      });
    }
    
  private:
    wxPanel* panel = new wxPanel {this};
    wxButton* buttonShowMessage = new wxButton {panel, wxID_ANY, "Message...", {10, 10}};
    wxStaticText* labelDialogResult = new wxStaticText {panel, wxID_ANY, "Result = ", {10, 45}};
  };

  class Application : public wxApp {
    bool OnInit() override {return (new Frame)->Show();}
  };
}

wxIMPLEMENT_APP(MessageDialogExample::Application);
