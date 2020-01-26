#include <string>
#include <wx/wx.h>

namespace Examples {
  class UserInputDialog : public wxDialog {
  public:
    UserInputDialog(wxWindow *parent) : wxDialog(parent, wxID_ANY, "Input Dialog") {
      SetClientSize(200, 80);
      CenterOnParent();
      buttonOk->SetDefault();
    }
    
    wxString GetInputText() const {return text->GetValue();}
    virtual void SetInputText(const wxString& inputString) {text->SetValue(inputString);}

  private:
    wxPanel* panel = new wxPanel(this, wxID_ANY);
    wxTextCtrl* text = new wxTextCtrl(panel, wxID_ANY, wxEmptyString, {10, 10}, {180, 25});
    wxButton* buttonCancel = new wxButton(panel, wxID_CANCEL, "Cancel", {10, 50});
    wxButton* buttonOk = new wxButton(panel, wxID_OK, "OK", {100, 50});
  };

  class Form1 : public wxFrame {
  public:
    Form1() : wxFrame(nullptr, wxID_ANY, "User dialog example", wxDefaultPosition, {800, 450}, wxDEFAULT_FRAME_STYLE) {
      Center();
      
      buttonDialog->Bind(wxEVT_BUTTON, [&](wxCommandEvent& e) {
        UserInputDialog dialog(this);
        dialog.SetInputText(inputText->GetLabel());
        if (dialog.ShowModal() == wxID_OK) inputText->SetLabel(dialog.GetInputText());
      });
    }
  private:
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

wxIMPLEMENT_APP(Examples::Application);
