#include "Logo.xpm"
#include <wx/generic/statbmpg.h>
#include <wx/app.h>
#include <wx/choice.h>
#include <wx/frame.h>
#include <wx/panel.h>
#include <wx/sizer.h>

namespace GenericStaticBitmapExample {
  class Frame : public wxFrame {
  public:
    Frame() : wxFrame {nullptr, wxID_ANY, "GenericStaticBitmap example"} {
      SetClientSize(300, 340);
      
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
      staticBitmap1->SetBitmap(wxBitmap {Logo_xpm});
      panel->SetSizerAndFit(boxSizer);

      Bind(wxEVT_SIZING, [&](wxSizeEvent& e) {
        staticBitmap1->Refresh();
      });
    }
    
  private:
    wxPanel* panel = new wxPanel {this};
    wxBoxSizer* boxSizer = new wxBoxSizer {wxVERTICAL};
    wxGenericStaticBitmap* staticBitmap1 = new wxGenericStaticBitmap {panel, wxID_ANY, wxNullBitmap};
    wxChoice* choice1 = new wxChoice {panel, wxID_ANY};
  };

  class Application : public wxApp {
    bool OnInit() override {return (new Frame)->Show();}
  };
}

wxIMPLEMENT_APP(GenericStaticBitmapExample::Application);
