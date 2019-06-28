#include <wx/wx.h>
#include <wx/richtext/richtextctrl.h>

class Form : public wxFrame {
public:
  Form() : wxFrame(nullptr, wxID_ANY, "RichTextBox example", wxDefaultPosition, wxSize(300, 300)) {
    this->Bind(wxEVT_SIZING, [&](wxSizeEvent& event) {
      this->richTextBox->SetSize(this->GetClientSize());
    });
    this->richTextBox->SetSize(this->GetClientSize());

    this->richTextBox->WriteText("Colored text :\n");
    this->richTextBox->BeginTextColour(wxColour(255, 0, 0));
    this->richTextBox->WriteText("  Red\n");
    this->richTextBox->EndTextColour();
    this->richTextBox->BeginTextColour(wxColour(0, 139, 0));
    this->richTextBox->WriteText("  Green\n");
    this->richTextBox->EndTextColour();
    this->richTextBox->BeginTextColour(wxColour(0, 0, 255));
    this->richTextBox->WriteText("  Blue\n");
    this->richTextBox->EndTextColour();
  }
  
private:
  wxPanel* panel = new wxPanel(this);
  wxRichTextCtrl* richTextBox = new wxRichTextCtrl(this->panel);
};

class Application : public wxApp {
  bool OnInit() override {return (new Form())->Show();}
};

wxIMPLEMENT_APP(Application);
