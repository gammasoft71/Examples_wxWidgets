#include <wx/app.h>
#include <wx/combobox.h>
#include <wx/frame.h>
#include <wx/statbmp.h>
#include <wx/panel.h>
#include <wx/sizer.h>
#include "Logo.xpm"

class Frame : public wxFrame {
public:
  Frame() : wxFrame(nullptr, wxID_ANY, "StaticBitmap example") {
    SetClientSize({300, 300});

    choice1->Append("Scale_None", reinterpret_cast<void*>(wxStaticBitmap::Scale_None));
    choice1->Append("Scale_Fill", reinterpret_cast<void*>(wxStaticBitmap::Scale_Fill));
    choice1->Append("Scale_AspectFit", reinterpret_cast<void*>(wxStaticBitmap::Scale_AspectFit));
    choice1->Append("Scale_AspectFill", reinterpret_cast<void*>(wxStaticBitmap::Scale_AspectFill));
    choice1->SetSelection(0);
    choice1->Bind(wxEVT_CHOICE, [this](wxCommandEvent& e) {
      staticBitmap1->SetScaleMode(static_cast<wxStaticBitmap::ScaleMode>(reinterpret_cast<long long>(choice1->GetClientData(choice1->GetSelection()))));
    });

    boxSizer->Add(choice1, 0, wxGROW, 20);
    boxSizer->Add(staticBitmap1, 1, wxEXPAND | wxALL, 20);
    staticBitmap1->SetScaleMode(static_cast<wxStaticBitmap::ScaleMode>(reinterpret_cast<long long>(choice1->GetClientData(choice1->GetSelection()))));
    staticBitmap1->SetWindowStyle(wxBORDER_SIMPLE);
    wxInitAllImageHandlers();
    staticBitmap1->SetBitmap({Logo_xpm});
    staticBitmap1->SetSize(260, 260);
    SetSizerAndFit(boxSizer);
  }

private:
  wxPanel* panel = new wxPanel(this);
  wxBoxSizer* boxSizer = new wxBoxSizer(wxVERTICAL);
  wxStaticBitmap* staticBitmap1 = new wxStaticBitmap(this, wxID_ANY, wxNullBitmap, {20, 50}, {100, 50});
  wxChoice* choice1 = new wxChoice(this, wxID_ANY, {20, 20}, wxDefaultSize, 0, nullptr, wxCB_READONLY);
};

class Application : public wxApp {
  bool OnInit() override {(new Frame())->Show(); return true;}
};

wxIMPLEMENT_APP(Application);
