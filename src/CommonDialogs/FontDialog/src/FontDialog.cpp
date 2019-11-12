#include <wx/wx.h>
#include <wx/fontdlg.h>

class Frame : public wxFrame {
public:
  Frame() : wxFrame(nullptr, wxID_ANY, "Font example", wxDefaultPosition) {
    SetClientSize(wxSize(400, 400));
    button->Bind(wxEVT_BUTTON, [&](wxCommandEvent& event) {
      wxFontData fontData;
      fontData.SetInitialFont(label->GetFont());
      fontData.SetColour(label->GetForegroundColour());
      wxFontDialog fontDialog(this, fontData);
      if (fontDialog.ShowModal() == wxID_OK) {
        label->SetFont(fontDialog.GetFontData().GetChosenFont());
        label->SetForegroundColour(fontDialog.GetFontData().GetColour());
      }
    });
  }

private:
  wxPanel* panel = new wxPanel(this);
  wxButton* button = new wxButton(panel, wxID_ANY, "Font...", wxPoint(10, 10));
  wxStaticText* label = new wxStaticText(panel, wxID_ANY,
    L"The quick brown fox jumps over the lazy dog.\n"
    L"THE QUICK BROWN FOX JUMPS OVER THE LAZY DOG.\n"
    L"0123456789+-*/%~^&|=<>≤≥±÷≠{{[()]}},;:.?¿!¡\n"
    L"àçéèêëïî@@°_#§$ù£€æœøπµ©®∞\\\"'\n"
    L"\u0400\u0401\u0402\u0403\u0404\u0405\u0406\u0407\u0408\u0409\u040a\u040b\u040c\u040d\u040e\u040f\n"
    L"\u0410\u0411\u0412\u0413\u0414\u0415\u0416\u0417\u0418\u0419\u041a\u041b\u041c\u041d\u041e\u041f\n"
    L"\u4ea0\u4ea1\u4ea2\u4ea3\u4ea4\u4ea5\u4ea6\u4ea7\u4ea8\u4ea9\u4eaa\u4eab\u4eac\u4ead\u4eae\u4eaf\n"
    L"\u4eb0\u4eb1\u4eb2\u4eb3\u4eb4\u4eb5\u4eb6\u4eb7\u4eb8\u4eb9\u4eba\u4ebb\u4ebc\u4ebd\u4ebe\u4ebf\n"
    L"\U0001F428", wxPoint(10, 50));
};

class Application : public wxApp {
  bool OnInit() override {(new Frame())->Show(); return true;}
};

wxIMPLEMENT_APP(Application);
