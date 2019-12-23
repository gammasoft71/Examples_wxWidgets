#include <wx/app.h>
#include <wx/combobox.h>
#include <wx/frame.h>
#include <wx/generic/statbmpg.h>
#include <wx/panel.h>
#include <wx/sizer.h>
#include "Logo.xpm"

class Frame : public wxFrame {
public:
  Frame() : wxFrame(nullptr, wxID_ANY, "GenericStaticBitmap example") {
    wxInitAllImageHandlers();
    SetClientSize(wxSize(300, 340));
    
    comboBox1->Append("Scale_None", (void*)wxStaticBitmap::Scale_None);
    comboBox1->Append("Scale_Fill", (void*)wxStaticBitmap::Scale_Fill);
    comboBox1->Append("Scale_AspectFit", (void*)wxStaticBitmap::Scale_AspectFit);
    comboBox1->Append("Scale_AspectFill", (void*)wxStaticBitmap::Scale_AspectFill);
    comboBox1->SetSelection(0);
    comboBox1->Bind(wxEVT_COMBOBOX, [&](wxCommandEvent& e) {
      staticBitmap1->SetScaleMode((wxStaticBitmap::ScaleMode)(long long)comboBox1->GetClientData(comboBox1->GetSelection()));
    });
    
    boxSizer->Add(comboBox1, 0, wxGROW, 20);
    boxSizer->Add(staticBitmap1, 1, wxEXPAND | wxALL, 20);
    staticBitmap1->SetScaleMode((wxStaticBitmap::ScaleMode)(long long)comboBox1->GetClientData(comboBox1->GetSelection()));
    staticBitmap1->SetWindowStyle(wxBORDER_SIMPLE);
    staticBitmap1->SetBitmap(wxBitmap(Logo_xpm));
    staticBitmap1->SetSize(260, 260);
    SetSizerAndFit(boxSizer);
  }
  
private:
  wxPanel* panel = new wxPanel(this);
  wxBoxSizer* boxSizer = new wxBoxSizer(wxVERTICAL);
  wxGenericStaticBitmap* staticBitmap1 = new wxGenericStaticBitmap(this, wxID_ANY, wxNullBitmap, wxPoint(20, 50), wxSize(100, 50));
  wxComboBox* comboBox1 = new wxComboBox(this, wxID_ANY, wxEmptyString, wxPoint(20, 20), wxDefaultSize, 0, nullptr, wxCB_READONLY);
};

class Application : public wxApp {
  bool OnInit() override {(new Frame())->Show(); return true;}
};

wxIMPLEMENT_APP(Application);
