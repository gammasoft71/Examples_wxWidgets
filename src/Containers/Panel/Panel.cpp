#include <wx/wx.h>

class Frame : public wxFrame {
public:
  Frame() : wxFrame(nullptr, wxID_ANY, "Panel example", wxDefaultPosition) {
    SetClientSize(wxSize(640, 480));
  }
  
private:
  wxPanel* panel = new wxPanel(this);
  wxPanel* panel1 = new wxPanel(panel, wxID_ANY, {10, 10}, wxSize(305, 460), wxTAB_TRAVERSAL | wxBORDER_SIMPLE);
  wxPanel* panel2 = new wxPanel(panel, wxID_ANY, wxPoint(325, 10), wxSize(305, 460), wxTAB_TRAVERSAL | wxBORDER_THEME);
};

class Application : public wxApp {
  bool OnInit() override {(new Frame())->Show(); return true;}
};

wxIMPLEMENT_APP(Application);
