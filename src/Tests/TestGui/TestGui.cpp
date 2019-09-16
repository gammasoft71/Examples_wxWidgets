#include <functional>
#include <wx/wx.h>
#include <wx/apptrait.h>

class UserDialog : public wxDialog {
public:
  UserDialog(wxWindow *parent) : wxDialog(parent, wxID_ANY, "Input Dialog") {
    this->SetClientSize(200, 80);
    this->CenterOnParent();
  }
  
  wxString GetText() const {return this->text->GetValue();}
  
private:
  wxTextCtrl* text = new wxTextCtrl(this, wxID_ANY, "Input text", wxPoint(10, 10), wxSize(180, 25));
  wxButton* buttonOk = new wxButton(this, wxID_OK, "OK", wxPoint(10, 50));
  wxButton* buttonCancel = new wxButton(this, wxID_CANCEL, "Cancel", wxPoint(100, 50));
};

class Form1 : public wxFrame {
public:
  Form1() : wxFrame(nullptr, wxID_ANY, "Test gui", wxDefaultPosition, wxSize(800, 450), wxDEFAULT_FRAME_STYLE) {
    this->SetBackgroundColour(this->panel1->GetBackgroundColour());
    this->SetForegroundColour(this->panel1->GetForegroundColour());
    this->panel1->Hide();
    
    this->Center();
    
    this->button1->Bind(wxEVT_BUTTON, [&](wxCommandEvent& e) {
      UserDialog dialog(this);
      wxMessageOutputDebug().Printf("Result = %s, text = \"%s\"", dialog.ShowModal() == wxID_OK ? "wxOK" : "wxCANCEL", dialog.GetText());
    });
  }
private:
  wxPanel* panel1 = new wxPanel(this);
  
  wxButton* button1 = new wxButton(this, wxID_ANY, "Dialog", wxPoint(10, 10));
};

class Application : public wxApp {
  bool OnInit() override {return (new Form1())->Show();}
};

wxIMPLEMENT_APP(Application);
