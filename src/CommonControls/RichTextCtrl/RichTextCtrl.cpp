#include <wx/app.h>
#include <wx/frame.h>
#include <wx/panel.h>
#include <wx/sizer.h>
#include <wx/richtext/richtextctrl.h>

class Frame : public wxFrame {
public:
  Frame() : wxFrame(nullptr, wxID_ANY, "RichTextCtrl example", wxDefaultPosition, {300, 300}) {
    Bind(wxEVT_SIZING, [&](wxSizeEvent& event) {
      richTextCtrl->SetSize(GetClientSize());
    });
    richTextCtrl->SetSize(GetClientSize());

    richTextCtrl->WriteText("Colored text :\n");
    richTextCtrl->BeginTextColour({255, 0, 0});
    richTextCtrl->WriteText("  Red\n");
    richTextCtrl->EndTextColour();
    richTextCtrl->BeginTextColour({0, 139, 0});
    richTextCtrl->WriteText("  Green\n");
    richTextCtrl->EndTextColour();
    richTextCtrl->BeginTextColour({0, 0, 255});
    richTextCtrl->WriteText("  Blue\n");
    richTextCtrl->EndTextColour();
  }
  
private:
  wxPanel* panel = new wxPanel(this);
  wxRichTextCtrl* richTextCtrl = new wxRichTextCtrl(panel);
};

class Application : public wxApp {
  bool OnInit() override {(new Frame())->Show(); return true;}
};

wxIMPLEMENT_APP(Application);
