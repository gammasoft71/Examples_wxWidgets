#include <functional>
#include <wx/wx.h>

class UserInputDialog : public wxDialog {
public:
  UserInputDialog(wxWindow *parent) : wxDialog(parent, wxID_ANY, "Input Dialog") {
    this->SetClientSize(200, 80);
    this->CenterOnParent();
  }
  
  wxString GetInputText() const {return this->text->GetValue();}
  void SetInputText(const wxString& inputString) {this->text->SetValue(inputString);}

private:
  wxTextCtrl* text = new wxTextCtrl(this, wxID_ANY, wxEmptyString, wxPoint(10, 10), wxSize(180, 25));
  wxButton* buttonOk = new wxButton(this, wxID_OK, "OK", wxPoint(10, 50));
  wxButton* buttonCancel = new wxButton(this, wxID_CANCEL, "Cancel", wxPoint(100, 50));
};

class Form1 : public wxFrame {
public:
  Form1() : wxFrame(nullptr, wxID_ANY, "User dialog example", wxDefaultPosition, wxSize(800, 450), wxDEFAULT_FRAME_STYLE) {
    this->SetBackgroundColour(this->panel1->GetBackgroundColour());
    this->SetForegroundColour(this->panel1->GetForegroundColour());
    this->panel1->Hide();
    
    this->Center();
    
    this->button_dialog->Bind(wxEVT_BUTTON, [&](wxCommandEvent& e) {
      UserInputDialog dialog(this);
      dialog.SetInputText(this->input_text->GetLabel());
      if(dialog.ShowModal() == wxID_OK) this->input_text->SetLabel(dialog.GetInputText());
    });
  }
private:
  wxPanel* panel1 = new wxPanel(this);
  wxButton* button_dialog = new wxButton(this, wxID_ANY, "Dialog", wxPoint(10, 10));
  wxStaticText* input_text = new wxStaticText(this, wxID_ANY, "User input text", wxPoint(10, 50));
};

class Application : public wxApp {
  bool OnInit() override {return (new Form1())->Show();}
};

wxIMPLEMENT_APP(Application);
