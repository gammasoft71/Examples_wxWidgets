#include <wx/dialog.h>
#include <wx/wx.h>
#include <wx/windowptr.h>

// Workaround : with wxWidgets version <= 3.2.0 wxMessageDialog ShowWindowModal method doesn't exists on other platform that macOS
#if defined(__APPLE__)
using MessageDialog = wxMessageDialog;
#else
class MessageDialog : public wxMessageDialog {
public:
  MessageDialog(wxWindow *parent, const wxString& message, const wxString& caption = wxMessageBoxCaptionStr, long style = wxOK|wxCENTRE, const wxPoint& pos = wxDefaultPosition) : wxMessageDialog(parent, message, caption, style, pos) {}
  void ShowWindowModal() {
    ShowModal();
    wxWindowModalDialogEvent event(wxEVT_WINDOW_MODAL_DIALOG_CLOSED, this->GetId());
    event.SetEventObject(this);
    wxPostEvent(this, event);
  }
};
#endif

namespace Examples {
  class Frame : public wxFrame {
  public:
    Frame() : wxFrame(nullptr, wxID_ANY, "MessageDialog (ShowWindowModal) example") {
      buttonShowMessage->Bind(wxEVT_BUTTON, [this](wxCommandEvent& event) {
        wxWindowPtr<MessageDialog> messageDialog(new MessageDialog(this, "Hello, World!", "Message", wxICON_ERROR|wxOK|wxCANCEL));
        messageDialog->Bind(wxEVT_WINDOW_MODAL_DIALOG_CLOSED, [this, messageDialog](wxWindowModalDialogEvent& event) {
          labelDialogResult->SetLabelText(wxString::Format("Result = %s", event.GetReturnCode() == wxID_OK ? "wxOK" : "wxCANCEL"));
        });
        
        labelDialogResult->SetLabelText("Result = ");
        messageDialog->SetParent(this);
        messageDialog->ShowWindowModal();
      });
    }
    
  private:
    wxPanel* panel = new wxPanel(this);
    wxButton* buttonShowMessage = new wxButton(panel, wxID_ANY, "Message...", {10, 10});
    wxStaticText* labelDialogResult = new wxStaticText(panel, wxID_ANY, "Result = ", {10, 45});
  };

  class Application : public wxApp {
    bool OnInit() override {
      (new Frame())->Show();
      return true;
    }
  };
}

wxIMPLEMENT_APP(Examples::Application);
