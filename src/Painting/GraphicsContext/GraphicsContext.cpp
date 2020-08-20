#include <wx/wx.h>
#include <wx/graphics.h>
#include <wx/statline.h>

namespace Examples {
  // Workaround : with wxWidgets version <= 3.1.4 font is in pixels and not in points on macOS
  int PointsToNativeFontGraphicsUntit(int size) {
    return wxPlatformInfo::Get().GetOperatingSystemFamilyName() != "Macintosh" ? size : static_cast<float>(size) / wxScreenDC().GetPPI().GetHeight() * 96.0f;
  }

  class Window : public wxFrame {
  public:
    Window() : wxFrame(nullptr, wxID_ANY, "GraphicsContext example") {
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
      (new Window())->Show();
      return true;
    }
  };
}

wxIMPLEMENT_APP(Examples::Application);
