#include <wx/app.h>
#include <wx/frame.h>
#include <wx/generic/statbmpg.h>
#include <wx/panel.h>
#include <wx/sizer.h>
#include "Logo.xpm"

class Frame : public wxFrame {
public:
  Frame() : wxFrame(nullptr, wxID_ANY, "StaticBitmap example") {
    wxInitAllImageHandlers();
    SetClientSize(wxSize(300, 300));

    boxSizer->Add(staticBitmap1, 1, wxEXPAND | wxALL, 20);
    staticBitmap1->SetScaleMode(wxStaticBitmap::Scale_AspectFit);
    staticBitmap1->SetWindowStyle(wxBORDER_SIMPLE);
    staticBitmap1->SetBitmap(wxBitmap(Logo_xpm));
    staticBitmap1->SetSize(260, 260);
    SetSizerAndFit(boxSizer);
  }

private:
  wxPanel* panel = new wxPanel(this);
  wxBoxSizer* boxSizer = new wxBoxSizer(wxVERTICAL);
  wxGenericStaticBitmap* staticBitmap1 = new wxGenericStaticBitmap(this, wxID_ANY, wxNullBitmap, wxPoint(20, 20), wxSize(100, 50));
};

class Application : public wxApp {
  bool OnInit() override {(new Frame())->Show(); return true;}
};

wxIMPLEMENT_APP(Application);
