#include <wx/wx.h>

class Form : public wxFrame {
public:
  Form() : wxFrame(nullptr, wxID_ANY, "PictureBox example", wxDefaultPosition, wxSize(300, 300)) {
    wxImage::AddHandler(new wxPNGHandler());
    this->pictureBox1 = new wxStaticBitmap(this, wxID_ANY, wxBitmap("Resources/Logo.png", wxBITMAP_TYPE_PNG), wxPoint(20,10), wxSize(260, 280));
    this->pictureBox1->SetWindowStyle(wxBORDER_SUNKEN);
  }
  
private:
  wxPanel* panel = new wxPanel(this);
  wxStaticBitmap* pictureBox1;
};

class Application : public wxApp {
  bool OnInit() override {return (new Form())->Show();}
};

wxIMPLEMENT_APP(Application);
