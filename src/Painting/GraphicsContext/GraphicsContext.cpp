#include <wx/wx.h>
#include <wx/graphics.h>
#include <wx/statline.h>

#if defined(__WXOSX__)
float points_to_native_font_graphics_untit(float size) {
  return size / wxScreenDC().GetPPI().GetHeight() * 96.0f;  // font is in pixels and not in points
}
#else
float points_to_native_font_graphics_untit(float size) {
  return size;  // font is in points
}
#endif

namespace Examples {
  class Form : public wxFrame {
  public:
    Form() : wxFrame(nullptr, wxID_ANY, "GraphicsContext example", wxDefaultPosition, {300, 300}) {
      SetPosition(wxPoint(100, 100));
      SetClientSize(wxSize(640, 480));
      
      Bind(wxEVT_PAINT, [&](wxPaintEvent& event) {
        wxPaintDC dc(this);
        wxGraphicsContext* graphics = wxGraphicsContext::Create(dc);
      
        graphics->SetPen(*wxRED_PEN);
        wxGraphicsPath path = graphics->CreatePath();
        
        path.AddCircle( 50.0, 50.0, 50.0 );
        path.MoveToPoint(0.0, 50.0);
        path.AddLineToPoint(100.0, 50.0);
        path.MoveToPoint(50.0, 0.0);
        path.AddLineToPoint(50.0, 100.0 );
        path.CloseSubpath();
        path.AddRectangle(25.0, 25.0, 50.0, 50.0);
        
        graphics->StrokePath(path);
        delete graphics;
      });
    }
  };
  
  class Application : public wxApp {
    bool OnInit() override {(new Form())->Show(); return true;}
  };
}

wxIMPLEMENT_APP(Examples::Application);
