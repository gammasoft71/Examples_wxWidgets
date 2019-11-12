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

class Frame : public wxFrame {
public:
  Frame() : wxFrame(nullptr, wxID_ANY, "My first application", wxDefaultPosition) {
    SetClientSize(wxSize(300, 300));
    staticText1->SetFont(wxFont(points_to_native_font_graphics_untit(32), wxFONTFAMILY_DEFAULT, wxFONTSTYLE_ITALIC, wxFONTWEIGHT_BOLD, false));
    staticText1->SetForegroundColour(wxColour(0, 139, 0));

    CenterOnScreen();
  }
  
private:
  wxPanel* panel = new wxPanel(this);
  wxStaticText* staticText1 = new wxStaticText(panel, wxID_ANY, "Hello, World!", wxPoint(5, 100));
};

class Application : public wxApp {
  bool OnInit() override {(new Frame())->Show(); return true;}
};

wxIMPLEMENT_APP(Application);
