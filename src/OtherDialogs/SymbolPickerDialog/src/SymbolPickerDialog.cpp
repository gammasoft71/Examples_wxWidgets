#include <wx/wx.h>
#include <wx/richtext/richtextsymboldlg.h>

class Form : public wxFrame {
public:
  Form() : wxFrame(nullptr, wxID_ANY, "SymbolPickerDialog example", wxDefaultPosition, wxSize(300, 300)) {
    button->Bind(wxEVT_BUTTON, [this](wxCommandEvent& event) {
      wxSymbolPickerDialog dialog("*", wxEmptyString, this->GetFont().GetFaceName(), this);
      dialog.SetFontName(labelSymbol->GetFont().GetFaceName());
      if (dialog.ShowModal() == wxID_OK) {
        wxFont font = labelSymbol->GetFont();
        font.SetFaceName(dialog.GetFontName());
        labelSymbol->SetFont(font);
        labelSymbol->SetLabel(dialog.GetSymbol());
      }
    });
  }

private:
  wxPanel* panel = new wxPanel(this);
  wxButton* button = new wxButton(panel, wxID_ANY, "Symbol...", wxPoint(10, 10));
  wxStaticText* label = new wxStaticText(panel, wxID_ANY, "Symbol = ", wxPoint(10, 50));
  wxStaticText* labelSymbol = new wxStaticText(panel, wxID_ANY, wxEmptyString, wxPoint(70, 50));
};

class Application : public wxApp {
  bool OnInit() override {(new Form())->Show(); return true;}
};

wxIMPLEMENT_APP(Application);
