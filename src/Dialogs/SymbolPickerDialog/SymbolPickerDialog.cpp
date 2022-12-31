#include <wx/wx.h>
#include <wx/richtext/richtextsymboldlg.h>

namespace Examples {
  class Frame : public wxFrame {
  public:
    Frame() : wxFrame(nullptr, wxID_ANY, "SymbolPickerDialog example") {
      button->Bind(wxEVT_BUTTON, [&](wxCommandEvent& event) {
        wxSymbolPickerDialog dialog("*", wxEmptyString, this->GetFont().GetFaceName(), this);
        dialog.SetFontName(labelSymbol->GetFont().GetFaceName());
        if (dialog.ShowModal() == wxID_OK) {
          auto font = labelSymbol->GetFont();
          font.SetFaceName(dialog.GetFontName());
          labelSymbol->SetFont(font);
          labelSymbol->SetLabel(dialog.GetSymbol());
        }
      });
    }

  private:
    wxPanel* panel = new wxPanel(this);
    wxButton* button = new wxButton(panel, wxID_ANY, "Symbol...", {10, 10});
    wxStaticText* label = new wxStaticText(panel, wxID_ANY, "Symbol = ", {10, 50});
    wxStaticText* labelSymbol = new wxStaticText(panel, wxID_ANY, wxEmptyString, {70, 50});
  };

  class Application : public wxApp {
    bool OnInit() override {
      (new Frame())->Show();
      return true;
    }
  };
}

wxIMPLEMENT_APP(Examples::Application);
