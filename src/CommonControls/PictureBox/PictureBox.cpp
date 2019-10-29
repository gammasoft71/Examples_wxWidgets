#include <wx/wx.h>
#include <wx/generic/statbmpg.h>
#include "Logo.xpm"

class Form : public wxFrame {
public:
  Form() : wxFrame(nullptr, wxID_ANY, "PictureBox example") {
    wxInitAllImageHandlers();
    SetClientSize(wxSize(300, 300));

    boxSizer->Add(pictureBox1, 1, wxEXPAND | wxALL, 20);
    pictureBox1->SetScaleMode(wxStaticBitmap::Scale_AspectFit);
    pictureBox1->SetWindowStyle(wxBORDER_SIMPLE);
    pictureBox1->SetBitmap(wxBitmap(Logo_xpm));
    pictureBox1->SetSize(260, 260);
    SetSizerAndFit(boxSizer);
  }

private:
  wxPanel* panel = new wxPanel(this);
  wxBoxSizer* boxSizer = new wxBoxSizer(wxVERTICAL);
  wxGenericStaticBitmap* pictureBox1 = new wxGenericStaticBitmap(this, wxID_ANY, wxNullBitmap, wxPoint(20, 20), wxSize(100, 50));
};

class Application : public wxApp {
  bool OnInit() override {(new Form())->Show(); return true;}
};

wxIMPLEMENT_APP(Application);
