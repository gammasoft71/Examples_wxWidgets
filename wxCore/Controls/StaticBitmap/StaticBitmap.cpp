#include "Logo.xpm"
#include <wx/app.h>
#include <wx/combobox.h>
#include <wx/frame.h>
#include <wx/panel.h>
#include <wx/sizer.h>
#include <wx/statbmp.h>

namespace StaticBitmapExample {
  class Frame : public wxFrame {
  public:
    Frame() : wxFrame {nullptr, wxID_ANY, "StaticBitmap example"} {
      SetClientSize({300, 300});

      choice1->Append("Scale_None", reinterpret_cast<void*>(wxStaticBitmap::Scale_None));
      choice1->Append("Scale_Fill", reinterpret_cast<void*>(wxStaticBitmap::Scale_Fill));
      choice1->Append("Scale_AspectFit", reinterpret_cast<void*>(wxStaticBitmap::Scale_AspectFit));
      choice1->Append("Scale_AspectFill", reinterpret_cast<void*>(wxStaticBitmap::Scale_AspectFill));
      choice1->SetSelection(0);
      choice1->Bind(wxEVT_CHOICE, [&](wxCommandEvent& e) {
        staticBitmap1->SetScaleMode(static_cast<wxStaticBitmap::ScaleMode>(reinterpret_cast<long long>(choice1->GetClientData(choice1->GetSelection()))));
      });

      boxSizer->Add(choice1, 0, wxGROW|wxTOP|wxLEFT|wxRIGHT, 20);
      boxSizer->Add(staticBitmap1, 1, wxGROW|wxALL, 20);
      staticBitmap1->SetScaleMode(static_cast<wxStaticBitmap::ScaleMode>(reinterpret_cast<long long>(choice1->GetClientData(choice1->GetSelection()))));
      staticBitmap1->SetWindowStyle(wxBORDER_SIMPLE);
      wxInitAllImageHandlers();
      staticBitmap1->SetBitmap(wxBitmap {Logo_xpm});
      panel->SetSizerAndFit(boxSizer);
    }

  private:
    wxPanel* panel = new wxPanel {this};
    wxBoxSizer* boxSizer = new wxBoxSizer {wxVERTICAL};
    wxStaticBitmap* staticBitmap1 = new wxStaticBitmap {panel, wxID_ANY, wxNullBitmap};
    wxChoice* choice1 = new wxChoice {panel, wxID_ANY};
  };

  class Application : public wxApp {
    bool OnInit() override {return (new Frame)->Show();}
  };
}

wxIMPLEMENT_APP(StaticBitmapExample::Application);
