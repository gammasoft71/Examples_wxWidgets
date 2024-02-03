#include <wx/app.h>
#include <wx/frame.h>
#include <wx/panel.h>
#include <wx/sizer.h>
#include <wx/richtext/richtextctrl.h>

namespace RichTextCtrlExample {
  class Frame : public wxFrame {
  public:
    Frame() : wxFrame(nullptr, wxID_ANY, "RichTextCtrl example") {
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
    wxRichTextCtrl* richTextCtrl = new wxRichTextCtrl(this);
  };

  class Application : public wxApp {
    bool OnInit() override {return (new Frame)->Show();}
  };
}

wxIMPLEMENT_APP(RichTextCtrlExample::Application);
