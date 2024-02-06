#include <wx/app.h>
#include <wx/button.h>
#include <wx/dialog.h>
#include <wx/frame.h>
#include <wx/panel.h>
#include <wx/stattext.h>
#include <wx/textctrl.h>

namespace UserDialogExample {
  class UserInputDialog : public wxDialog {
  public:
    UserInputDialog(wxWindow* parent) : wxDialog {parent, wxID_ANY, "Input Dialog"} {
      SetClientSize(200, 80);
      CenterOnParent();
      buttonOk->SetDefault();
    }
    
    wxString GetInputText() const {return text->GetValue();}
    virtual void SetInputText(const wxString& inputString) {text->SetValue(inputString);}

  private:
    wxPanel* panel = new wxPanel {this, wxID_ANY};
    wxTextCtrl* text = new wxTextCtrl {panel, wxID_ANY, wxEmptyString, {10, 10}, {180, 25}};
    wxButton* buttonCancel = new wxButton {panel, wxID_CANCEL, "Cancel", {10, 50}, {85, -1}};
    wxButton* buttonOk = new wxButton {panel, wxID_OK, "OK", {105, 50}, {85, -1}};
  };

  class Frame : public wxFrame {
  public:
    Frame() : wxFrame {nullptr, wxID_ANY, "User dialog example", wxDefaultPosition, {800, 450}, wxDEFAULT_FRAME_STYLE} {
      
      buttonDialog->Bind(wxEVT_BUTTON, [&](wxCommandEvent& e) {
        auto dialog = UserInputDialog {this};
        dialog.SetInputText(inputText->GetLabel());
        if (dialog.ShowModal() == wxID_OK) inputText->SetLabel(dialog.GetInputText());
      });
    }
  private:
    wxPanel* panel = new wxPanel {this};
    wxButton* buttonDialog = new wxButton {panel, wxID_ANY, "Dialog", {10, 10}};
    wxStaticText* inputText = new wxStaticText {panel, wxID_ANY, "User input text", {10, 50}};
  };

  class Application : public wxApp {
    bool OnInit() override {return (new Frame)->Show();}
  };
}

wxIMPLEMENT_APP(UserDialogExample::Application);
