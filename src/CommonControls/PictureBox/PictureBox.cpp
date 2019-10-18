#include <wx/wx.h>
#include "Logo.xpm"

class Form : public wxFrame {
public:
  Form() : wxFrame(nullptr, wxID_ANY, "PictureBox example", wxDefaultPosition, wxSize(300, 300)) {
    SetClientSize(wxSize(300, 300));
    wxImage::AddHandler(new wxPNGHandler());
    pictureBox1 = new wxStaticBitmap(this, wxID_ANY, wxBitmap(Logo_xpm), wxPoint(20,10), wxSize(260, 280));
    pictureBox1->SetWindowStyle(wxBORDER_SUNKEN);
  }

private:
  wxPanel* panel = new wxPanel(this);
  wxStaticBitmap* pictureBox1;
};

class Application : public wxApp {
  bool OnInit() override {(new Form())->Show(); return true;}
};

wxIMPLEMENT_APP(Application);
