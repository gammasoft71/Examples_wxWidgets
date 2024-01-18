#include <string>
#include <wx/wx.h>

namespace UserDialogShowWindowModalExample {
  class UserInputDialog : public wxDialog {
  public:
    UserInputDialog(wxWindow *parent) : wxDialog(parent, wxID_ANY, "Input Dialog") {
      SetClientSize(200, 80);
      CenterOnScreen();
      buttonOk->SetDefault();
    }
    
    wxString GetInputText() const {return text->GetValue();}
    virtual void SetInputText(const wxString& inputString) {text->SetValue(inputString);}

  private:
    wxPanel* panel = new wxPanel(this, wxID_ANY);
    wxTextCtrl* text = new wxTextCtrl(panel, wxID_ANY, wxEmptyString, {10, 10}, {180, 25});
    wxButton* buttonCancel = new wxButton(panel, wxID_CANCEL, "Cancel", {10, 50}, {85, -1});
    wxButton* buttonOk = new wxButton(panel, wxID_OK, "OK", {105, 50}, {85, -1});
  };

  class Form1 : public wxFrame {
  public:
    Form1() : wxFrame(nullptr, wxID_ANY, "User dialog example", wxDefaultPosition, {800, 450}) {
      Center();
      
      buttonDialog->Bind(wxEVT_BUTTON, [&](wxCommandEvent& e) {
        dialog->Bind(wxEVT_WINDOW_MODAL_DIALOG_CLOSED, [&](wxWindowModalDialogEvent& event) {
          if (event.GetReturnCode() == wxID_OK)
            inputText->SetLabel(dialog->GetInputText());
        });
        dialog->SetInputText(inputText->GetLabel());
        dialog->ShowWindowModal();
      });
    }
  private:
    UserInputDialog* dialog = new UserInputDialog(this);
    wxPanel* panel = new wxPanel(this, wxID_ANY);
    wxButton* buttonDialog = new wxButton(panel, wxID_ANY, "Dialog", {10, 10});
    wxStaticText* inputText = new wxStaticText(panel, wxID_ANY, "User input text", {10, 50});
  };

  class Application : public wxApp {
    bool OnInit() override {
      (new Form1())->Show();
      return true;
    }
  };
}

wxIMPLEMENT_APP(UserDialogShowWindowModalExample::Application);
