#include <wx/wx.h>

#if defined(__WXOSX__)
float points_to_native_font_graphics_untit(float size) {
  return size / wxScreenDC().GetPPI().GetHeight() * 96.0f;  // font is in pixels and not in points
}
#else
float points_to_native_font_graphics_untit(float size) {
  return size;  // font is in points
}
#endif

class Form : public wxFrame {
public:
  Form() : wxFrame(nullptr, wxID_ANY, "My first application", wxDefaultPosition) {
    this->SetClientSize(wxSize(300, 300));
    this->label1->SetFont(wxFont(points_to_native_font_graphics_untit(34), wxFONTFAMILY_DEFAULT, wxFONTSTYLE_ITALIC, wxFONTWEIGHT_BOLD, false, "Arial"));
    this->label1->SetForegroundColour(wxColour(0, 139, 0));

    this->CenterOnScreen();
  }
  
private:
  wxPanel* panel = new wxPanel(this);
  wxStaticText* label1 = new wxStaticText(this->panel, wxID_ANY, "Hello, World!", wxPoint(5, 100));
};

class Application : public wxApp {
  bool OnInit() override {return (new Form())->Show();}
};

wxIMPLEMENT_APP(Application);
