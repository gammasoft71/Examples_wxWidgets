#include <wx/wx.h>
#include <wx/graphics.h>
#include <wx/statline.h>

namespace Examples {
#if defined(__WXOSX__)
  int PointsToNativeFontGraphicsUntit(int size) {
    return static_cast<float>(size) / wxScreenDC().GetPPI().GetHeight() * 96.0f;  // font is in pixels and not in points
  }
#else
  int PointsToNativeFontGraphicsUntit(int size) {
    return size;  // font is in points
  }
#endif

  class Form : public wxFrame {
  public:
    Form() : wxFrame(nullptr, wxID_ANY, "GraphicsContext example") {
      SetPosition({100, 100});
      SetClientSize(640, 480);
      
      Bind(wxEVT_PAINT, [&](wxPaintEvent& event) {
        wxPaintDC dc(this);
        auto graphics = wxGraphicsContext::Create(dc);
      
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
    bool OnInit() override {
      (new Form())->Show();
      return true;
    }
  };
}

wxIMPLEMENT_APP(Examples::Application);
