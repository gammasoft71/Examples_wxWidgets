#include <wx/wx.h>
#include <wx/richtext/richtextctrl.h>

class Frame : public wxFrame {
public:
  Frame() : wxFrame(nullptr, wxID_ANY, "RichTextBox example", wxDefaultPosition, wxSize(300, 300)) {
    Bind(wxEVT_SIZING, [&](wxSizeEvent& event) {
      richTextBox->SetSize(GetClientSize());
    });
    richTextBox->SetSize(GetClientSize());

    richTextBox->WriteText("Colored text :\n");
    richTextBox->BeginTextColour(wxColour(255, 0, 0));
    richTextBox->WriteText("  Red\n");
    richTextBox->EndTextColour();
    richTextBox->BeginTextColour(wxColour(0, 139, 0));
    richTextBox->WriteText("  Green\n");
    richTextBox->EndTextColour();
    richTextBox->BeginTextColour(wxColour(0, 0, 255));
    richTextBox->WriteText("  Blue\n");
    richTextBox->EndTextColour();
  }
  
private:
  wxPanel* panel = new wxPanel(this);
  wxRichTextCtrl* richTextBox = new wxRichTextCtrl(panel);
};

class Application : public wxApp {
  bool OnInit() override {(new Frame())->Show(); return true;}
};

wxIMPLEMENT_APP(Application);
