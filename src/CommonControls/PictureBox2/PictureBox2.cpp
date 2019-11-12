#include <wx/wx.h>

class Frame : public wxFrame {
public:
  Frame() : wxFrame(nullptr, wxID_ANY, "PictureBox2 example", wxDefaultPosition, wxSize(300, 300)) {
    SetClientSize(wxSize(300, 300));
    pictureBox1->SetBitmap(wxBitmap("Resources/Logo.png", wxBITMAP_TYPE_ANY));
    pictureBox1->SetWindowStyle(wxBORDER_SIMPLE);
  }

private:
  wxPanel* panel = new wxPanel(this);
  wxStaticBitmap* pictureBox1 = new wxStaticBitmap(this, wxID_ANY, wxNullBitmap, wxPoint(20, 20), wxSize(100, 50));;
};

class Application : public wxApp {
  bool OnInit() override {
    wxInitAllImageHandlers();
    (new Frame())->Show(); return true;
  }
};

wxIMPLEMENT_APP(Application);
