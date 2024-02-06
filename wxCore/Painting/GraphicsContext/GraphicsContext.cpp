#include <wx/app.h>
#include <wx/dcclient.h>
#include <wx/frame.h>
#include <wx/graphics.h>

namespace GraphicContextExample {
  class Frame : public wxFrame {
  public:
    Frame() : wxFrame {nullptr, wxID_ANY, "GraphicsContext example"} {
      SetPosition({100, 100});
      SetClientSize(640, 480);
      
      Bind(wxEVT_PAINT, [&](wxPaintEvent& event) {
        auto dc = wxPaintDC {this};
        auto graphics = wxGraphicsContext::Create(dc);
      
        graphics->SetPen(*wxRED_PEN);
        auto path = graphics->CreatePath();
        
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
    bool OnInit() override {return (new Frame)->Show();}
  };
}

wxIMPLEMENT_APP(GraphicContextExample::Application);
