#include <wx/app.h>
#include <wx/fontpicker.h>
#include <wx/frame.h>
#include <wx/panel.h>
#include <wx/stattext.h>

namespace FontPickerCtrlExample {
  class Frame : public wxFrame {
  public:
    Frame() : wxFrame {nullptr, wxID_ANY, "FontPickerCtrl example"} {
      SetClientSize(400, 400);
      picker->SetSelectedFont(label->GetFont());
      picker->SetSelectedColour(label->GetForegroundColour());
      picker->Bind(wxEVT_FONTPICKER_CHANGED, [&](wxFontPickerEvent& event) {
        label->SetFont(picker->GetSelectedFont());
        label->SetForegroundColour(picker->GetSelectedColour());
      });
    }
    
  private:
    wxPanel* panel = new wxPanel {this};
    wxStaticText* label = new wxStaticText {panel, wxID_ANY,
      "The quick brown fox jumps over the lazy dog.\n"
      "THE QUICK BROWN FOX JUMPS OVER THE LAZY DOG.\n"
      "0123456789+-*/%~^&|=<>≤≥±÷≠{{[()]}},;:.?¿!¡\n"
      "àçéèêëïî@@°_#§$ù£€æœøπµ©®∞\\\"'\n"
      "\u0400\u0401\u0402\u0403\u0404\u0405\u0406\u0407\u0408\u0409\u040a\u040b\u040c\u040d\u040e\u040f\n"
      "\u0410\u0411\u0412\u0413\u0414\u0415\u0416\u0417\u0418\u0419\u041a\u041b\u041c\u041d\u041e\u041f\n"
      "\u4ea0\u4ea1\u4ea2\u4ea3\u4ea4\u4ea5\u4ea6\u4ea7\u4ea8\u4ea9\u4eaa\u4eab\u4eac\u4ead\u4eae\u4eaf\n"
      "\u4eb0\u4eb1\u4eb2\u4eb3\u4eb4\u4eb5\u4eb6\u4eb7\u4eb8\u4eb9\u4eba\u4ebb\u4ebc\u4ebd\u4ebe\u4ebf\n"
      "\U0001F428", {10, 50}};
    wxFontPickerCtrl* picker = new wxFontPickerCtrl {panel, wxID_ANY, {}, {10, 10}, wxDefaultSize, wxFNTP_FONTDESC_AS_LABEL};
  };

  class Application : public wxApp {
    bool OnInit() override {return (new Frame)->Show();}
  };
}

wxIMPLEMENT_APP(FontPickerCtrlExample::Application);
